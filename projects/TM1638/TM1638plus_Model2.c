/*
* Project Name: TM1638plus 
* File: TM1638plus_Model2.c
* Description: Source c file for PIC library for "Model 2" TM1638 module(16 KEY 16 pushbuttons).
* Author: Gavin Lyons.
* Created: August 2019
* PIC 16F18446
*/

#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <stdio.h>
#include "TM1638plus_Model2.h"


void TM1638Init_Model2( bool swap_nibbles) 
{
  STBpin_SetDigitalOutput();
  CLKpin_SetDigitalOutput(); 
  DIOpin_SetDigitalOutput();
  TM1638sendCommand(ACTIVATE_TM);
  TM1638brightness(DEFAULT_BRIGHTNESS);
  TM1638Reset();
    if (swap_nibbles == true)
    {
        _SWAP_NIBBLES = true;
    }
  
}

void TM1638sendCommand(uint8_t value)
{
  STBpin_SetLow();
  TM1638shiftOut(value);
  STBpin_SetHigh(); 
}


void TM1638Reset() 
{
  TM1638sendCommand(WRITE_INC); // set auto increment mode
  STBpin_SetLow();
  TM1638shiftOut(SEG_ADR);   // set starting address to 0
  for (uint8_t i = 0; i < 16; i++)
  {
    TM1638shiftOut(0x00);
  }
   STBpin_SetHigh(); 
}


void TM1638DisplaySegments(uint8_t segment, uint8_t digit)
{
   if (_SWAP_NIBBLES == true)
   {
   	  uint8_t upper , lower = 0;
   	  lower = (digit) & 0x0F;  // select lower nibble
   	  upper =  (digit >> 4) & 0X0F; //select upper nibble
   	  digit = (uint8_t)(lower << 4 | upper);
   }
    
  segment = (uint8_t)(segment<<1);
  TM1638sendCommand(WRITE_LOC);
  STBpin_SetLow();
  TM1638shiftOut(SEG_ADR | segment);
  TM1638shiftOut(digit);
  STBpin_SetHigh(); 
}

void TM1638brightness(uint8_t brightness)
{
    uint8_t  value = 0;
    value = BRIGHT_ADR + (BRIGHT_MASK & brightness);
    STBpin_SetLow();
    TM1638shiftOut(value);
    STBpin_SetHigh(); 
}

void TM1638DisplayStr(const char* string, const uint16_t dots)
{
  uint8_t values[DISPLAY_SIZE];
  bool done = false;
 char c, pos;
 uint16_t i = 0;
  pos = 0;
  while ((c = (*string++))) {
    if (dots >> (7-i) & 0x01) {
      values[i] = (SevenSeg[c - ASCII_OFFSET] | DOT_MASK_DEC);
    }  else {
       values[i] = SevenSeg[c - ASCII_OFFSET] ;
    }
    i++;
  }
 TM1638ASCIItoSegment(values);
}

void TM1638ASCIItoSegment(const uint8_t values[])
{
  for (uint8_t  segment = 0; segment < DISPLAY_SIZE; segment++) {
  uint8_t  SegmentValue = 0;
  for (uint8_t  j = 0; j < DISPLAY_SIZE; j++) {
    SegmentValue |= ((values[j] >> segment) & 1) << (DISPLAY_SIZE - j - 1);
  }
  TM1638DisplaySegments(segment , SegmentValue);
  }
}

unsigned char TM1638ReadKey16()
{
  unsigned char c[4], i, key_value = 0;
  
  STBpin_SetLow();
  TM1638shiftOut(BUTTONS_MODE);
  DIOpin_SetDigitalInput();
 for (i = 0; i < 4; i++)
  {
	 c[i] = TM1638shiftIn();
	 if (c[i] == 0x04) key_value = 1 + (2*i); //00000100 4 0x04
	 if (c[i] == 0x40) key_value = 2 + (2*i); //01000000 64 0x40
	 if (c[i] == 0x02) key_value = 9 + (2*i); //00000010 2 0x02
	 if (c[i] == 0x20) key_value = 10 + (2*i);  //00100000 32 0x20
  }
  DIOpin_SetDigitalOutput(); 
  STBpin_SetHigh();
  return (key_value);
  // Data matrix for read key_value. 
  // c3 0110 0110  c2 0110 0110  c1 0110 0110  c0 0110 0110 :bytes read 
  //    8,16 7,15     6,14 5,13     4,12 3,11     2,10  1,9 :button value
}

void TM1638shiftOut(uint8_t data)
{
        for (int i=0 ; i<8 ; i++)
        {
        DIOpin_LAT = (data >> i) & 0x01; // bit shift and bit mask data. 
        TM1638sclock(); //enable data storage clock
         }
}

void TM1638sclock(void){
    CLKpin_SetHigh(); 
    __delay_us(SCLK_DELAY);
    CLKpin_SetLow(); 
    __delay_us(SCLK_DELAY);
}

uint8_t TM1638shiftIn(void) {

 uint8_t value = 0;
 uint8_t i;

 for (i = 0; i < 8; ++i) 
 {
    CLKpin_SetHigh();
    value |= DIOpin_PORT  << i; //LSB
    CLKpin_SetLow();
 }
 return value;

}

void TM1638DisplayHexNum(uint16_t  numberUpper, uint16_t numberLower, uint8_t dots, bool leadingZeros, AlignTextType_e  TextAlignment)
{
  char valuesUpper[DISPLAY_SIZE + 1];
  char valuesLower[DISPLAY_SIZE/2 + 1];
  char TextDisplay[5] = "%";
  char TextLeft[4] = "-4X";
  char TextRight[3] = "4X";
  
     if (TextAlignment == TMAlignTextLeft)
    {
        strcat(TextDisplay ,TextLeft);  // %-4X
    }else if ( TextAlignment == TMAlignTextRight)
    {
        strcat(TextDisplay ,TextRight); // %4X
    }  
    
  snprintf(valuesUpper, DISPLAY_SIZE/2 + 1, leadingZeros ? "%04X" : TextDisplay, numberUpper);
  snprintf(valuesLower, DISPLAY_SIZE/2 + 1, leadingZeros ? "%04X" : TextDisplay, numberLower); 
  strcat(valuesUpper ,valuesLower);
  TM1638DisplayStr(valuesUpper, dots);
}

void TM1638DisplayDecNum(unsigned long number, uint8_t  dots, bool leadingZeros,  AlignTextType_e  TextAlignment)
{ 
  char values[DISPLAY_SIZE + 1];
  char TextDisplay[6] = "%";
  char TextLeft[5] = "-8ld";
  char TextRight[4] = "8ld";
  
    if (TextAlignment == TMAlignTextLeft)
    {
        strcat(TextDisplay ,TextLeft);  // %ld
    }else if ( TextAlignment == TMAlignTextRight)
    {
        strcat(TextDisplay ,TextRight); // %8ld
    }
    
  snprintf(values, DISPLAY_SIZE + 1, leadingZeros ? "%08ld" : TextDisplay, number); 
  TM1638DisplayStr(values, dots);

}

void TM1638DisplayDecNumNibble(uint16_t  numberUpper, uint16_t numberLower, uint8_t  dots, bool leadingZeros,  AlignTextType_e  TextAlignment)
{
  char valuesUpper[DISPLAY_SIZE + 1];
  char valuesLower[DISPLAY_SIZE/2 + 1];
  char TextDisplay[5] = "%";
  char TextLeft[4] = "-4d";
  char TextRight[3] = "4d";
  
     if (TextAlignment == TMAlignTextLeft)
    {
        strcat(TextDisplay ,TextLeft);  // %-4d
    }else if ( TextAlignment == TMAlignTextRight)
    {
        strcat(TextDisplay ,TextRight); // %4d
    }  
    
  snprintf(valuesUpper, DISPLAY_SIZE/2 + 1, leadingZeros ? "%04d" : TextDisplay, numberUpper);
  snprintf(valuesLower, DISPLAY_SIZE/2 + 1, leadingZeros ? "%04d" : TextDisplay, numberLower); 
  strcat(valuesUpper ,valuesLower);
  TM1638DisplayStr(valuesUpper, dots);
    
}

uint16_t  TM1638ReadKey16Two()
{
    
  uint16_t key_value = 0;
  uint8_t Datain ,i = 0;
  
  STBpin_SetLow();
  TM1638shiftOut(BUTTONS_MODE);
  DIOpin_SetDigitalInput();
  
  for (i = 0; i < 4; i++)
  {
     Datain = TM1638shiftIn();
      // turn Datain ABCDEFGI = 0BC00FG0  into 00CG00BF see matrix below
     Datain = (((Datain & 0x40) >> 3 | (Datain & 0x04)) >> 2) | (Datain & 0x20) | (Datain & 0x02) << 3;
     // i = 0 Datain =  00,10,9,0021 // i = 1 Datain  = 00,12,11,0043
     // i = 2 Datain =  00 ,14,13,0065 // i = 3 Datain =  00,16,15,0087
     // key_value =  16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1. 
      key_value |= ((Datain & 0x000F) << (2*i)) | (((Datain & 0x00F0) << 4) << (2*i));
  }
  DIOpin_SetDigitalOutput();
  STBpin_SetHigh();
   
  return (key_value);
  
  //  Data matrix for read key_value. c = datain
  //   c3 0110 0110  c2 0110 0110  c1 0110 0110  c0 0110 0110 :bytes read 
  //    8,16 7,15     6,14 5,13     4,12 3,11                   2,10  1,9 :button value
}