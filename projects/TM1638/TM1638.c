/*
* Project Name: TM1638 
* File: TM1638.c
* Description: source file library for  TM1638 module(LED & KEY).
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F18446
* IDE:  MPLAB X v5.05
* Development board: Microchip Curiosity Board
* Created May 2019
*/

#include <stdio.h>
#include <string.h>
#include "mcc_generated_files/mcc.h"
#include "TM1638.h"


void TM1638Init(void) {
  STBpin_SetDigitalOutput();
  CLKpin_SetDigitalOutput(); 
  DIOpin_SetDigitalOutput();       
  TM1638SendCommand(ACTIVATE);
  TM1638brightness(DEFAULT_BRIGHTNESS);
  TM1638Reset();
}

void TM1638SendCommand(uint8_t value)
{
  STBpin_SetLow();
  TM1638shiftOut(value);
  STBpin_SetHigh(); 
}

void TM1638Reset() {
  TM1638SendCommand(WRITE_INC); // set auto increment mode
  STBpin_SetLow();
  TM1638shiftOut(SEGADR);   // set starting address to 0
  for (uint8_t i = 0; i < 16; i++)
  {
    TM1638shiftOut(0x00);
  }
   STBpin_SetHigh(); 
}

void TM1638setLED(uint8_t position, uint8_t value)
{
  DIOpin_SetDigitalOutput(); 
  TM1638SendCommand(WRITE_LOC);
  STBpin_SetLow();
  TM1638shiftOut((uint8_t)(LEDADR + (position << 1)));
  TM1638shiftOut(value);
  STBpin_SetHigh(); 
}

void TM1638displayText(char *text) {
  char c, pos;

  pos = 0;
  while ((c = (*text++)) && pos < DISPLAY_SIZE ) {
    if (*text == '.' && c != '.') {
      TM1638displayASCIIwDot(pos++, c);

      text++;
    }  else {
      TM1638displayASCII(pos++, c);
    }
  }
}


void TM1638displayASCIIwDot(uint8_t position, uint8_t ascii) { 
    // add 128 or 0x080 0b1000000 to turn on decimal point/dot in seven seg
  TM1638display7Seg(position, SevenSeg[ascii- ASCII_OFFSET] +  DOT_MASK_DEC);
}

void TM1638display7Seg(uint8_t position, uint8_t value) { // call 7-segment
  TM1638SendCommand(WRITE_LOC);
  STBpin_SetLow();
  TM1638shiftOut((uint8_t)(SEGADR + (position << 1)));
  TM1638shiftOut(value);
  STBpin_SetHigh(); 
}


void TM1638displayASCII(uint8_t position, uint8_t ascii) {
  TM1638display7Seg(position, SevenSeg[ascii - ASCII_OFFSET]);
}
 
void TM1638displayHex(uint8_t position, uint8_t hex) 
{
    uint8_t offset = 0;
    hex = hex % 16;
    if (hex <= 9)
    {
        TM1638display7Seg(position, SevenSeg[hex + HEX_OFFSET]);
        // 16 is offset in reduced ASCII table for 0 
    }else if ((hex >= 10) && (hex <=15))
    {
        // Calculate offset in reduced ASCII table for AbCDeF
        switch(hex) 
        {
         case 10: offset = 'A'; break;
         case 11: offset = 'b'; break;
         case 12: offset = 'C'; break;
         case 13: offset = 'd'; break;
         case 14: offset = 'E'; break;
         case 15: offset = 'F'; break;
        }
        TM1638display7Seg(position, SevenSeg[offset-32]);
    }
    
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


uint8_t TM1638readButtons()
{
  uint8_t buttons = 0;
  STBpin_SetLow();
  TM1638shiftOut(BUTTONS);
  
  DIOpin_SetDigitalInput();

  for (uint8_t i = 0; i < 4; i++)
  {
    uint8_t v = (uint8_t)(TM1638shiftIn() << i);
    buttons |= v;
  }

  DIOpin_SetDigitalOutput(); 
  STBpin_SetHigh(); 
  return buttons;
}

uint8_t TM1638shiftIn(void) {

 uint8_t value = 0;
 uint8_t i;

 for (i = 0; i < 8; ++i) 
 {
    CLKpin_SetHigh();
    value |= DIOpin_PORT  << i;
    CLKpin_SetLow();
 }
 return value;

}

void TM1638brightness(uint8_t brightness)
{
    uint8_t  value = 0;
    value = BRIGHTADR + (BRIGHT_MASK & brightness);
    STBpin_SetLow();
    TM1638shiftOut(value);
    STBpin_SetHigh(); 
}

void TM1638setLEDs(uint16_t ledvalues)
{
  for (uint8_t LEDposition = 0;  LEDposition < 8; LEDposition++) {
    uint8_t color = 0;

    if ((ledvalues & (1 << LEDposition)) != 0) {
      color |= TM1638_RED_LED; //scan lower byte, set Red if one
    } 

    if ((ledvalues & (1 << (LEDposition + 8))) != 0) {
      color |= TM1638_GREEN_LED; //scan upper byte, set green if one
    }

    TM1638setLED(LEDposition, color);
  }
}

void TM1638displayIntNum(unsigned long number, bool leadingZeros, AlignTextType_e TextAlignment)
{
  char values[DISPLAY_SIZE + 1];
  char TextDisplay[5] = "%";
  char TextLeft[3] = "ld";
  char TextRight[4] = "8ld";
  
  if (TextAlignment == TMAlignTextLeft)
    {
        strcat(TextDisplay ,TextLeft);  // %ld
    }else if ( TextAlignment == TMAlignTextRight)
    {
        strcat(TextDisplay ,TextRight); // %8ld
    }
    
  snprintf(values, DISPLAY_SIZE + 1, leadingZeros ? "%08ld" : TextDisplay, number); 
  TM1638displayText(values);
} 

void TM1638DisplayDecNumNibble(uint16_t  numberUpper, uint16_t numberLower, bool leadingZeros, AlignTextType_e TextAlignment)
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
    TM1638displayText(valuesUpper);
    
}