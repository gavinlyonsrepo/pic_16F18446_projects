/*
* Project Name: TM1638 
* File: TM1638.h
* Description: TM1638.h header file library for  TM1638 module(LED & KEY).
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F18446
* IDE:  MPLAB X v5.05
* Development board: Microchip Curiosity Board, PIC16F1619
* Created May 2019
*/


#ifndef TM1638_h
#define TM1638_h

#include <stdint.h>

#define SCLK_DELAY 75

#define ACTIVATE 0x8f
#define BUTTONS 0x42
#define WRITE_LOC 0x44
#define WRITE_INC 0x40
#define STARTADR 0XC0
#define LEDLOC 0xC1

// Init the module
void TM1638init(void);

// Send a command to module
void sendCommand(uint8_t value);

//reset module
void reset(void);

//Read buttons returns an integer with value of buttons 1-8 b7b6b5b4b3b2b1
// 1 pressed zero not pressed. 
uint8_t readButtons(void);

// Set an LED, pass it LED position 0-7 and value o or 1
void setLED(uint8_t position, uint8_t value);

// Send Text to Seven segments, passed char array
void displayText(char text[]);

// Send ASCII value to seven segment, pass position 0-7 and ASCII value byte
void displayASCII(uint8_t position, uint8_t ascii);

// Send HEX value to seven segment, pass position 0-7 and hex value(DEC) 0-15
void displayHex(uint8_t position, uint8_t hex);

// Send seven segment value to seven segment
//  pass position 0-7 byte of data coresspoding to segments ghfedcba of segment
// i.e 10000001 will set g and a on. 

void displaySS(uint8_t position, uint8_t value);

//Shift out a byte of data from DIO line
void shiftOut(uint8_t data);

//Shift in a byte of data from DIO line
uint8_t shiftIn(void);

/* sclock:
 * Controls clock signal  when shifting data
 */
void sclock(void);
   
    
// map of ASCII values/table to 7-segment
const char SevenSeg[96] = {
  0x00, /* (space) */
  0x86, /* ! */
  0x22, /* " */
  0x7E, /* # */
  0x6D, /* $ */
  0xD2, /* % */
  0x46, /* & */
  0x20, /* ' */
  0x29, /* ( */
  0x0B, /* ) */
  0x21, /* * */
  0x70, /* + */
  0x10, /* , */
  0x40, /* - */
  0x80, /* . */
  0x52, /* / */
  0x3F, /* 0 */
  0x06, /* 1 */
  0x5B, /* 2 */
  0x4F, /* 3 */
  0x66, /* 4 */
  0x6D, /* 5 */
  0x7D, /* 6 */
  0x07, /* 7 */
  0x7F, /* 8 */
  0x6F, /* 9 */
  0x09, /* : */
  0x0D, /* ; */
  0x61, /* < */
  0x48, /* = */
  0x43, /* > */
  0xD3, /* ? */
  0x5F, /* @ */
  0x77, /* A */
  0x7C, /* B */
  0x39, /* C */
  0x5E, /* D */
  0x79, /* E */
  0x71, /* F */
  0x3D, /* G */
  0x76, /* H */
  0x30, /* I */
  0x1E, /* J */
  0x75, /* K */
  0x38, /* L */
  0x15, /* M */
  0x37, /* N */
  0x3F, /* O */
  0x73, /* P */
  0x6B, /* Q */
  0x33, /* R */
  0x6D, /* S */
  0x78, /* T */
  0x3E, /* U */
  0x3E, /* V */
  0x2A, /* W */
  0x76, /* X */
  0x6E, /* Y */
  0x5B, /* Z */
  0x39, /* [ */
  0x64, /* \ */
  0x0F, /* ] */
  0x23, /* ^ */
  0x08, /* _ */
  0x02, /* ` */
  0x5F, /* a */
  0x7C, /* b */
  0x58, /* c */
  0x5E, /* d */
  0x7B, /* e */
  0x71, /* f */
  0x6F, /* g */
  0x74, /* h */
  0x10, /* i */
  0x0C, /* j */
  0x75, /* k */
  0x30, /* l */
  0x14, /* m */
  0x54, /* n */
  0x5C, /* o */
  0x73, /* p */
  0x67, /* q */
  0x50, /* r */
  0x6D, /* s */
  0x78, /* t */
  0x1C, /* u */
  0x1C, /* v */
  0x14, /* w */
  0x76, /* x */
  0x6E, /* y */
  0x5B, /* z */
  0x46, /* { */
  0x30, /* | */
  0x70, /* } */
  0x01, /* ~ */
  0x00, /* (del) */
};

 
#endif
