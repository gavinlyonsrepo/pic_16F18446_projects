/*
* Project Name: TM1638 
* File: TM1638.c
* Description: source file library for  TM1638 module(LED & KEY).
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F18446
* IDE:  MPLAB X v5.05
* Development board: Microchip Curiosity Board, PIC16F1619
* Created May 2019
*/

#include "TM1638.h"
#include <string.h>
#include "mcc_generated_files/mcc.h"

void TM1638init() {
  STBpin_SetDigitalOutput();
  CLKpin_SetDigitalOutput(); 
  DIOpin_SetDigitalOutput();       
  sendCommand(ACTIVATE);
  reset();
}

void sendCommand(uint8_t value)
{
  STBpin_SetLow();
  shiftOut(value);
  STBpin_SetHigh(); 
}

void reset() {
  sendCommand(WRITE_INC); // set auto increment mode
  STBpin_SetLow();
  shiftOut(STARTADR);   // set starting address to 0
  for (uint8_t i = 0; i < 16; i++)
  {
    shiftOut(0x00);
  }
   STBpin_SetHigh(); 
}

void setLED(uint8_t position, uint8_t value)
{
  DIOpin_SetDigitalOutput(); 
  sendCommand(WRITE_LOC);
  STBpin_SetLow();
  shiftOut(LEDLOC + (position << 1));
  shiftOut(value);
  STBpin_SetHigh(); 
}


void displayText(char text[]) 
{
  size_t length = strlen(text);
  for (uint8_t i = 0; i < length; i++) 
  {
    for (uint8_t position = 0; position < 8; position++) 
    {
      displayASCII(position, text[position]);
    }
  }
}
void displaySS(uint8_t position, uint8_t value) { // call 7-segment
  sendCommand(WRITE_LOC);
  STBpin_SetLow();
  shiftOut(STARTADR + (position << 1));
  shiftOut(value);
  STBpin_SetHigh(); 
}


void displayASCII(uint8_t position, uint8_t ascii) {
  displaySS(position, SevenSeg[ascii - 32]);
}
 
void displayHex(uint8_t position, uint8_t hex) 
{
    uint8_t offset = 0;
    if ((hex >= 0) && (hex <= 9))
    {
        displaySS(position, SevenSeg[hex + 16]);
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
        displaySS(position, SevenSeg[offset-32]);
    }
    
}

void shiftOut(uint8_t data)
{
        for (int i=0 ; i<8 ; i++)
        {
        DIOpin_LAT = (data >> i) & 0x01; // bit shift and bit mask data. 
        sclock(); //enable data storage clock
         }
}


void sclock(void){
    CLKpin_SetHigh(); 
    __delay_us(SCLK_DELAY);
    CLKpin_SetLow(); 
    __delay_us(SCLK_DELAY);
}


uint8_t readButtons()
{
  uint8_t buttons = 0;
  STBpin_SetLow();
  shiftOut(BUTTONS);
  
  DIOpin_SetDigitalInput();

  for (uint8_t i = 0; i < 4; i++)
  {
    uint8_t v = shiftIn() << i;
    buttons |= v;
  }

  DIOpin_SetDigitalOutput(); 
  STBpin_SetHigh(); 
  return buttons;
}

uint8_t shiftIn(void) {

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


