/*
* Project Name: FourteenSegDisplay
* File: FourteenSegDisplay.h
* Description: header file for FourteenSegDisplay  library
* Author: Gavin Lyons.
* Created: August 2019
* Fork of Arduino library FourteenSegDisplay
* URL: https://github.com/gavinlyonsrepo/pic_16F18446_projects
*/

#ifndef FourteenSegDisplay_h
#define FourteenSegDisplay_h

#include <stdint.h>

#define SHIFT_DELAY 25   //shift delay in usecconds can be adjusted to avoid flickering 
#define ASCII_OFFSET 32 // ASCII table offset to jump over first missing 32 chars
#define HEX_OFFSET   16 // ASCII table offset to reach 0 position
#define DOT_MASK_DEC   0x4000 //  Mask to switch on decimal point in fourteen segment.   
#define COMMON_ANODE_MASK 0xFFFF // mask to be applied if user wants common anode. 
#define LOWER_BYTE_MASK 0X00FF //mask to be applied to mask off lower byte of a uint16_t var


    
    // Functions

    //  Init function
    // also passed a boolean value called common
    // common true = Common Cathode(default)
    // common false = Common Anode
    void FourteenSegDisplay(bool common);
    
    // Send ASCII value to 14 segment display, passed ASCII value byte
    // Digits position 0x80-0x40-0x20-0x10-0x08-0x04-0x02-0x01 D8-D1
    void displayASCII(uint8_t ascii, uint8_t digits);

    // Same as displayASCII function but turns on dot/decimal point as well 
    // Digits position 0x80-0x40-0x20-0x10-0x08-0x04-0x02-0x01 D8-D1
    void displayASCIIwDot(uint8_t ascii, uint8_t digits) ;

    // Send HEX value to 14 segment display, passed a hex value  0-15 : 0x00 to 0x0F
    // Digits position 0x80-0x40-0x20-0x10-0x08-0x04-0x02-0x01 D8-D1
    void displayHex(uint8_t hex, uint8_t digits);

    // Send  segment value to  14 segment display
    //  Passed value corresponding to segments  (DP-N-M-L-K-J-H-G2-G1-F-E-D-C-B-A) Two bytes. 
    // eg 0000000100000001 or 0x0101 will switch on A and H
    // Digits position 0x80-0x40-0x20-0x10-0x08-0x04-0x02-0x01 D8-D1
    void displaySeg(uint16_t value, uint8_t digits);
    
    // This function is for Model 2 design only: passed a string 
    // and starting position 0x80-0x40-0x20-0x10-0x08-0x04-0x02-0x01 D8-D1
    // So to print 12345678 as "12345678" set start position to 0x80.
    void displayString(const char* str, uint8_t startPos);
    
    //Used for timing internally in DataDisplay method
    void sclock(void);
    
    //Shift out a byte of data MSB
    void DataDisplay(unsigned int data);
    
    bool _common; //If true common cathode , if false common cathode

#endif
