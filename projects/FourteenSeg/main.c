/*
* Project Name: FourteenSegDisplay
* File: FourteenSegDisplay.h
* Description: main.c test file for FourteenSegDisplay  library
* Author: Gavin Lyons.
* Created: August 2019
* Fork of Arduino library FourteenSegDisplay
* URL: https://github.com/gavinlyonsrepo/pic_16F18446_projects
*/

#include "mcc_generated_files/mcc.h"
#include "FourteenSegDisplay.h"

/* Main application */

//testdata for single segment function.
#define testdata1 0x0202 // b j -> on :
#define testdata2 0x1708 // d h j k m -> on : Antenna shape
#define testdata3 0x4006 // DP b c -> on : Exclamination point
#define testdata4 0x0000 // all off
#define testdata5 0x7FFF // all on 
#define digitdelay 1 //delay in mS fir 

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    FourteenSegDisplay(true);

    while (1)
    {
       //  **** Display digit one ****
       DIGIT1_SetHigh(); //turn on digit one

        // test 1 Hex
        //displayHex(0x3);

        // test 2 ASCII
        //displayASCII('A');

        //test 3 ASCII with dot
        //displayASCIIwDot('A');

        // test 4 Segments manual
        displaySeg(testdata2);

        DIGIT1_SetLow(); //turn off digit one
        __delay_ms(digitdelay);

        // ***** Display digit two ****
        DIGIT2_SetHigh(); //turn on digit two

        // test 1 Hex
        //displayHex(0xF);

        // test 2 ASCII
        //displayASCII('B');

        //test 3 ASCII with dot
        //displayASCIIwDot('B');

        // test 4 Segments manual
        displaySeg(testdata3);

        DIGIT2_SetLow(); //turn off digit two
        __delay_ms(digitdelay);

    }
}
/* End of File */