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

#define TESTDELAY1  __delay_ms(1000);
#define TESTDELAY2  __delay_ms(2000);
#define TESTDELAY5  __delay_ms(5000);

// Test vars ...  for testing
char values[9];
unsigned char buttons = 0;
uint16_t buttonsTwo = 0;
uint8_t ButtonTestType = 1; // 1 for TM1638ReadKey16() 2 for TM1638ReadKey16Two()

void main(void) {
    // initialize the device

    SYSTEM_Initialize();
    TM1638Init_Model2(false); //set to True to swap nibbles, default is false.
    TM1638Reset();
    TM1638brightness(DEFAULT_BRIGHTNESS);

    // Test 1 display strings
    TM1638DisplayStr("   HELLO", 0x04); //"   HEL.LO"
    TESTDELAY2
    TM1638DisplayStr("HELLOYOU", 0);
    TESTDELAY2

    // Test 2 manually set segments
    // display a one in position 1 " .       1" and a dot in position 7
    TM1638DisplaySegments(0, 0x00); //a
    TM1638DisplaySegments(1, 0x01); //b for b turn on digit one only
    TM1638DisplaySegments(2, 0x01); //c for c turn on digit one only
    TM1638DisplaySegments(3, 0x00);
    TM1638DisplaySegments(4, 0x00);
    TM1638DisplaySegments(5, 0x00);
    TM1638DisplaySegments(6, 0x00); //g
    TM1638DisplaySegments(7, 0x80); // Dp turn on dot in digit 7 
    TESTDELAY2
    TM1638Reset();
    
    // Test 3 decimal numbers
    TM1638DisplayDecNum(50, 1<<7, false, TMAlignTextLeft); // "5.0      "
    TESTDELAY5
    TM1638DisplayDecNum(991118, 1 << 4, true, TMAlignTextLeft); // "0099.1118  "
    TESTDELAY5
       
    TM1638DisplayDecNum(54, 1 << 2, false, TMAlignTextRight); // "    .54"
    TESTDELAY5
    TM1638DisplayDecNum(991111, 1 << 4, true, TMAlignTextRight); // "0099.1111"
    TESTDELAY5
                    
    TM1638DisplayDecNum(-2888, 0, true, TMAlignTextLeft); // -0002888
    TESTDELAY5

    // Test 3b  decimal numbers with the DisplayDecNumNibble function divides display into two nibbles.
    TM1638DisplayDecNumNibble(12, 78, 0, false, TMAlignTextLeft); // "12  78  "
    TESTDELAY5
    TM1638DisplayDecNumNibble(13, 79, 1 << 4, true, TMAlignTextLeft); // "0013.0079"
    TESTDELAY5
    TM1638DisplayDecNumNibble(14, 880, 1 << 5, false, TMAlignTextRight); // "  1.4 880"
    TESTDELAY5
    TM1638DisplayDecNumNibble(115, 7, 0, true, TMAlignTextRight); // "01150007"
    TESTDELAY5
    
   // Test 4 Hexadecimal number
    TM1638DisplayHexNum(0x0001, 0x056E, 0x00, false, TMAlignTextLeft); // "1    56E "
    TESTDELAY5
    TM1638DisplayHexNum(0x0BCD, 0xEF, 0, true, TMAlignTextLeft); // 0BCD00EF
    TESTDELAY5
    TM1638DisplayHexNum(0x0000, 0xABFF, 0, false, TMAlignTextRight); // "   0ABFF"
    TESTDELAY5
    TM1638DisplayHexNum(0x0065, 0x00FF, 1 << 4, true, TMAlignTextRight); // 0065.00FF
    TESTDELAY5

    //test 5 , ASCII to segments takes an array of bytes and displays them
    // without ref to the ASCII font table direct data to digits to displays 3F 3F 3F 6D 3F 3F 3F 6D = 00050005
    // gfedcba = 3F for zero https://en.wikipedia.org/wiki/Seven-segment_display
    // for ascii to segment test 00050005
    const uint8_t values1[8] = {0x3F, 0x3F, 0x3F, 0x6D, 0x3F, 0x3F, 0x3F, 0x6D};
    TM1638ASCIItoSegment(values1);
    TESTDELAY2

    TM1638Reset();

    // Test 6  Brightness and reset
    for (uint8_t brightness = 0; brightness < 8; brightness++) {
        TM1638brightness(brightness);
        TM1638DisplayStr("brightnes", 1);
        TESTDELAY1
    }
    TM1638brightness(0x02); // restore default
    TM1638Reset();

    while (1) {
        if (ButtonTestType == 1) {
            buttons = TM1638ReadKey16(); // Test 7a scan buttons if pressed 1-16
            TM1638DisplayDecNum(buttons, 0, false, TMAlignTextRight);
        } else {
            buttonsTwo = TM1638ReadKey16Two(); // Test 7b scan buttons if pressed 1-16
            TM1638DisplayHexNum(0x0000, buttonsTwo, 0, true, TMAlignTextRight);
        }
        __delay_ms(200);
    }
}
