/*
 * Project Name: TM1638plus_Model2 
 * File: TM1638plus_Model2.h
 * Description: TM1638plus_Model2.h header file PIC library for Model 2 TM1638 module(16 KEY 16 pushbuttons).
 * Author: Gavin Lyons.
 * Created August 2019
 * PIC: pic16F18446
 * URL: https://github.com/gavinlyonsrepo/TM1638plus
 */


#ifndef TM1638plus_Model2_h
#define TM1638plus_Model2_h

#include <stdint.h>

#define SCLK_DELAY 75    // delay  used in uSeconds duirng comms
#define ACTIVATE_TM 0x8F // Start up
#define BUTTONS_MODE 0x42 // Buttons mode
#define WRITE_LOC 0x44 // Write to a location
#define WRITE_INC 0x40 // Incremental write
#define SEG_ADR 0xC0  // leftmost segment Address C0 C2 C4 C6 C8 CA CC CE
#define BRIGHT_ADR 0x88 // Brightness address
#define BRIGHT_MASK 0x07 // Brightness mask 
#define DEFAULT_BRIGHTNESS 0x02 //can be 0x00 to 0x07 

#define DISPLAY_SIZE 8 //size of display
#define ASCII_OFFSET 32 // Ascii table offset to jump over first missing 32 chars   
#define DOT_MASK_DEC 128 // 0x80 Mask to  switch on decimal point in seven seg.  

bool _SWAP_NIBBLES = false;

typedef enum {
    TMAlignTextRight = 1,
    TMAlignTextLeft = 2,
} AlignTextType_e; // Alignment of text

// Init the module
// swap_nibbles is false by default set to true to swap the nibbles in 7-seg display
// i.e ABCDEFGH becomes EFGHABCD. This is support different versions of Model 2 on market
// same function but have been wired differently. 
void TM1638Init_Model2(bool swap_nibbles);

// Send a command to module
void TM1638sendCommand(uint8_t value);

// Reset module 
void TM1638Reset(void);

//Sets the brightness level on a scale of brightness = 0 to 7.
//0 is not turned off, it's just the lowest brightness.
//If user wishes to change the default brightness at start-up change.
//The DEFAULT_BRIGHTNESS define in header file.
void TM1638brightness(uint8_t brightness);

//Read buttons returns a byte with value of buttons 1-16 (1 for S1 2 for S2 ... 16 for S16 )
//User may have to deb-ounce buttons depending on application..
unsigned char TM1638ReadKey16(void);

// Send seven segment value module
// pass segment  0-7, byte of data corresponding to segments abcdefg(dp) 01234567.
// a is 0 , dp is 7 , segmentValue is which segments are off or on for each digit. d7d6d5d54d3d2d1 
// Have to call it 8 times in row to set all segments. 
// to set all "a" on send (0x00,0xFF)
// to set all segment "g" off (0x06,0X00)
void TM1638DisplaySegments(uint8_t segment, uint8_t segmentValue);

// Display a decimal number , takes a number and byte for decimal point display,  leading zeros optional 
// converts to string. 
// Then passes array of eight ASCII bytes to DisplayValues function
void TM1638DisplayStr(const char* string, const uint16_t dots);

// Takes in Array of 8 ASCII bytes , Called from DisplayStr 
// Scans each ASCII byte converts to array of 8 segment bytes where each byte represents a segment
// i.e. byte 0 represents a in segment and then each bit represents the a segment in each digit.
// So for "00000005" is converted by DisplayStr to hex "3F 3F 3F 3F 3F 3F 3F 6D" where left is first digit.
// this is converted to hex "FF FE FF FF FE FF 01 00"  Where left is first segment
// So "a" segment is turned on for all bytes and "b" is on for all except last digit.
// The bits are  mapping below abcdefg(dp) = 01234567 ! 
// see for mapping of seven segment to digit https://en.wikipedia.org/wiki/Seven-segment_display
void TM1638ASCIItoSegment(const uint8_t values[]);

//Shift out a byte of data from DIO line, used internally 
void TM1638shiftOut(uint8_t data);

//Shift in a byte of data from DIO line, used internally 
uint8_t TM1638shiftIn(void);

// Controls clock signal when shifting data out, used internally
void TM1638sclock(void);

// Display a Hexadecimal number ,takes a number and byte for decimal point display, leading zeros optional
// converts to string. 
//void DisplayHexNum(unsigned long number, byte dots, boolean leadingZeros = true);
void TM1638DisplayHexNum(uint16_t numberUpper, uint16_t numberLower, uint8_t dots, bool leadingZeros, AlignTextType_e);

// Display a decimal number , takes a number and byte for decimal point display,  leading zeros optional 
// converts to string. 
void TM1638DisplayDecNum(unsigned long number, uint8_t dots, bool leadingZeros, AlignTextType_e);

//Divides the display into two nibbles and displays a Decimal number in each.
//takes in two numbers 0-9999 for each nibble ,  and byte for decimal point display,
//and leading zeros optional
void TM1638DisplayDecNumNibble(uint16_t numberUpper, uint16_t numberLower, uint8_t dots, bool leadingZeros, AlignTextType_e);

// Function Desc: Reads the push  buttons:  alternate function to ReadKeys16
// Can detect multiple key presses , See notes section in README(arduino org port) regarding
// problems with seven segment display when pressing certain keys in combination
// Returns: A 16 bit integer where each bit correspond to a switch
// Eg:
// S1 = 0x0001
// S16 = 0x8000
// S16 + S1 together = 0x8001
uint16_t TM1638ReadKey16Two(void);

// map of ASCII values/table to 7-segment, offset to position 32. 
const uint8_t SevenSeg[] = {
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
};


#endif
