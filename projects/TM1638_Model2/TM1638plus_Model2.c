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
   	  digit = lower << 4 | upper;
   }
    
  segment = (segment<<1);
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
  while (c = (*string++)) {
    if (dots >> 7-i & 0x01) {
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
  for (i = 0; i<4; i++)
  {
    c[i] = TM1638shiftIn();
  }
  DIOpin_SetDigitalOutput(); 
  STBpin_SetHigh();
  
  if (c[0] == 0x04) key_value = 1; //00000100 4
  if (c[0] == 0x40) key_value = 2; //01000000 64
  if (c[1] == 0x04) key_value = 3; 
  if (c[1] == 0x40) key_value = 4; 
  if (c[2] == 0x04) key_value = 5; 
  if (c[2] == 0x40) key_value = 6; 
  if (c[3] == 0x04) key_value = 7; 
  if (c[3] == 0x40) key_value = 8; 
  if (c[0] == 0x02) key_value = 9; //00000010 2
  if (c[0] == 0x20) key_value = 10;//00100000 32
  if (c[1] == 0x02) key_value = 11; 
  if (c[1] == 0x20) key_value = 12; 
  if (c[2] == 0x02) key_value = 13; 
  if (c[2] == 0x20) key_value = 14; 
  if (c[3] == 0x02) key_value = 15; 
  if (c[3] == 0x20) key_value = 16; 
  return (key_value);
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