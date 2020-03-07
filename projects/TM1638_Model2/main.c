/*
* Project Name: TM1638plus_Model2 
* File: TM1638plus_Model2.h
* Description: test main  file PIC library for Model 2 TM1638 module(16 KEY 16 pushbuttons).
* Author: Gavin Lyons.
* Created August 2019
* PIC: pic16F18446
*/

#include "mcc_generated_files/mcc.h"
#include "TM1638plus_Model2.h"
#include <string.h>

char values[9];
unsigned char buttons = 0;

void main(void)
{
    // initialize the device
    
    SYSTEM_Initialize();
    TM1638Init_Model2(false); //set to True to swap nibbles, default is false.
    TM1638Reset();
    TM1638brightness(DEFAULT_BRIGHTNESS);
        
    // Test 1 display strings
    TM1638DisplayStr("   HELLO", 0x04); //"   HEL.LO"
    __delay_ms(2000);
     TM1638DisplayStr("HELLOYOU", 0); 
    __delay_ms(2000);

      // Test 2 manually set segments
      // display a one in position one "       1"
      TM1638DisplaySegments(0, 0x00); //a
      TM1638DisplaySegments(1, 0x01); //b for b turn on digit one only 
      TM1638DisplaySegments(2, 0x01); //c for c turn on digit one only
      TM1638DisplaySegments(3, 0x00);
      TM1638DisplaySegments(4, 0x00);
      TM1638DisplaySegments(5, 0x00);
      TM1638DisplaySegments(6, 0x00); //g
      TM1638DisplaySegments(7, 0x00);
      __delay_ms(2000);
        
        // Test 3 decimal numbers
        TM1638DisplayDecNum(5, 1 << 6, true); // 00.000005
        __delay_ms(2000);
        TM1638DisplayDecNum(99991111, 1 << 4, true); // 9999.1111
        __delay_ms(2000);
        TM1638DisplayDecNum(-2888, 0 ,true);  // -0002888
       __delay_ms(2000);
        // Test 1b  decimal numbers with the DisplayDecNumNibble function divides display into two nibbles.
        TM1638DisplayDecNumNibble(1234 , 78, 1<<4 , true); // "1234.0078"
        __delay_ms(2000);

        // Test 4 Hexadecimal number
        TM1638DisplayHexNum(0x0000, 0x456E, 0x00, true); // 0000456E
        __delay_ms(2000);
        TM1638DisplayHexNum(0xABCD, 0xEF23, 0, true); // ABCDEF23
        __delay_ms(2000);
        TM1638DisplayHexNum(0x0000, 0x00FF, 1 << 4, true); // 0000.00FF
        __delay_ms(2000);
        
        //test 5 , ASCII to segments takes an array of bytes and displays them 
        // without ref to the ASCII font table direct data to digits to displays 3F 3F 3F 6D 3F 3F 3F 6D = 00050005
       // gfedcba = 3F for zero https://en.wikipedia.org/wiki/Seven-segment_display

       const uint8_t values1[8] = {0x3F, 0x3F, 0x3F, 0x6D, 0x3F, 0x3F, 0x3F, 0x6D}; // for ascii to segment test 00050005
       TM1638ASCIItoSegment(values1);
        __delay_ms(2000);
        
       TM1638Reset();
       
       while (1)
        {
          // Test 6 scan buttons if pressed 1-16 
             buttons = TM1638ReadKey16();
             __delay_ms(200);
              snprintf(values, 9,  "%08i", buttons); 
              TM1638DisplayStr(values, 0); 

          }
}
