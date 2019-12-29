/*
* Project Name: FourteenSegDisplay
* File: main.c
* Description: test  file for FourteenSegDisplay  library
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

        // test 1 Hex
       //displayHex(0x3, 0x01);

        // test 2 ASCII
        //displayASCII('A', 0x01);

        //test 3 ASCII with dot
        //displayASCIIwDot('A', 0x01);

        // test 4 Segments manual
        //displaySeg(testdata2, 0x01);


       // __delay_ms(digitdelay);

        // ***** Display digit two ****

        // test 1 Hex
     //   displayHex(0xF, 0x02);

        
        // test 2 ASCII
       //displayASCII('B', 0x02);

        //test 3 ASCII with dot
        //displayASCIIwDot('B', 0x02);

        // test 4 Segments manual
        //displaySeg(testdata3, 0x02);
        
        //  __delay_ms(digitdelay);
        
         // ***** Display string tests ****
       
        // test 5 string
        //displayString("AB", 0x02);
        
        //test 6 string with dots
        //displayString("A.B", 0x02);
        
        //test 7  string 8 digits 
        displayString("12345678", 0x80);
        
    }
}
/* End of File */