/*
* Project Name: FourteenSegDisplay
* File: FourteenSegDisplay.cpp
* Description: Source file for FourteenSegDisplay  library
* Author: Gavin Lyons.
* Created: August 2019
* Fork of Arduino library FourteenSegDisplay
* URL: https://github.com/gavinlyonsrepo/pic_16F18446_projects
*/

#include "mcc_generated_files/mcc.h"
#include "FourteenSegDisplay.h"
#include "FourteenSegDisplayFont.h"

void FourteenSegDisplay(bool common) {
  _common = common;
  SER_SetDigitalOutput();
  SCLK_SetDigitalOutput();
  RCLK_SetDigitalOutput();
}

void displaySeg(uint16_t value) { 
   if (_common == false) 
   {
     value = (value ^ COMMON_ANODE_MASK); // If common anode flip all bits.
   }
  uint8_t  upper , lower = 0;
  lower = (value) & LOWER_BYTE_MASK;  // select lower byte
  upper = (value >> 8) & LOWER_BYTE_MASK; //select upper 
  RCLK_SetLow() ;
  DataDisplay(upper);
  DataDisplay(lower);
  RCLK_SetHigh();
}

void displayASCII(uint8_t ascii) {
  displaySeg(FourteenSeg[ascii - ASCII_OFFSET]);
}

void displayASCIIwDot(uint8_t ascii) { 
    // add  0x4000 to turn on decimal point/dot in 14 seg
  displaySeg(FourteenSeg[ascii - ASCII_OFFSET] + DOT_MASK_DEC);
}

void displayHex(uint8_t hex) 
{
    uint8_t hexchar = 0;
    if ((hex >= 0) && (hex <= 9))
    {
        displaySeg(FourteenSeg[hex + HEX_OFFSET]);
        // 16 is offset in reduced ASCII table for 0 
    }else if ((hex >= 10) && (hex <=15))
    {
        // Calculate offset in reduced ASCII table for ABCDEF
        switch(hex) 
        {
         case 10: hexchar = 'A'; break;
         case 11: hexchar = 'B'; break;
         case 12: hexchar = 'C'; break;
         case 13: hexchar = 'D'; break;
         case 14: hexchar = 'E'; break;
         case 15: hexchar = 'F'; break;
        }
        displaySeg(FourteenSeg[hexchar - ASCII_OFFSET]);
    }
    
}

/* sclock:
 * This function clock will enable the storage Clock to 74HC595
 */
void sclock(void){
    SCLK_SetHigh();
    __delay_us(SHIFT_DELAY);
    SCLK_SetLow();
    __delay_us(SHIFT_DELAY);
}

/* DataDisplay:
 * This function will send the data to serial line 74HC9595
 */
void DataDisplay(unsigned int data){
    for (uint8_t i=0 ; i<8 ; i++){
       // bit shift and bit mask data. MSB
        SER_LAT = (data >>(7-i)) & 0x01;
        sclock(); //enable data storage clock
    }
  
}