
/*
* Project Name: TM1638 
* File: main.c 
* Description: demo file for library for TM1638 module(LED & KEY).
runs thru a series of tests. 
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F18446
* IDE:  MPLAB X v5.05
* Development board: Microchip Curiosity Board
* Created May 2019
*/

#include "mcc_generated_files/mcc.h"
#include "TM1638.h"

void doLEDs(uint8_t value);

/*   Main application  */
void main(void)
{
    // initialize the device
      SYSTEM_Initialize();
      TM1638Init();
      TM1638Reset();
      TM1638brightness(0x00);
      
      
        //Test 0 display 2.333 in ascii at low brightness
        TM1638displayASCIIwDot(0, '2');
        TM1638displayASCII(1, '3');
        TM1638displayASCII(2, '4');
        TM1638displayASCII(3, '8');
          TM1638setLED(0, 1);
        __delay_ms(2000);
        
       
       //test 1 Turn on single segment gfedcba 
      //IN this case LED 0 segment g (middle dash)
       TM1638display7Seg(4,0b01000000);
       TM1638setLED(1, 1);
        __delay_ms(2000);
         
      //Test 2 ASCII at medium brighntess 
      TM1638brightness(0x02);
      TM1638displayASCII(6, 'u');
      TM1638displayASCII(7, 'p');
      TM1638setLED(2, 1);
      __delay_ms(2000);
      
            //test 3  HEX at high brightness
       TM1638brightness(0x07);
      TM1638displayHex(0, 1);
      TM1638displayHex(1, 2);
      TM1638displayHex(2, 3);
      TM1638displayHex(3, 4);
      TM1638displayHex(4, 5);
      TM1638displayHex(5, 6);
      TM1638displayHex(6, 7);
      TM1638displayHex(7, 8);
      TM1638setLED(3, 1);
      __delay_ms(2000);
      
      //test 3b more hex  number
      TM1638displayHex(0, 8);
      TM1638displayHex(1, 9);
      TM1638displayHex(2, 10);
      TM1638displayHex(3, 11);
      TM1638displayHex(4, 12);
      TM1638displayHex(5, 13);
      TM1638displayHex(6, 14);
      TM1638displayHex(7, 15);
       TM1638setLED(4, 1);
      __delay_ms(2000);
      
       //test 4 turn off LEDS & medium brightness 
       TM1638brightness(0x02);
       TM1638setLED(0, 0);
       TM1638setLED(1, 0);
       TM1638setLED(2, 0);
       TM1638setLED(3, 0);
       TM1638setLED(4, 0);
      __delay_ms(1000);
      
       // test 5 TEXT 
       // abcdefhg with decmial point for c and d on

      TM1638displayText("abc.d.efhg");
       __delay_ms(3000);
      
       // test6  TEXT + ASCII combo 
       // ADC=2.548
       char text1[]= "ADC=";
      TM1638displayText(text1);
        TM1638displayASCIIwDot(4, '2');
        TM1638displayASCII(5, '5');
        TM1638displayASCII(6, '4');
        TM1638displayASCII(7, '8');
       __delay_ms(2000);
     
      
       
       
    while (1)
    {
    // Test 7 scan buttons if pressed turn on opposite LED 
     uint8_t buttons = TM1638readButtons();
     doLEDs(buttons);   
     
    }
}

void doLEDs(uint8_t value) {
  for (uint8_t position = 0; position < 8; position++)
  {
    TM1638setLED(position, value & 1);
    value = value >> 1;
  }
}
/*  End of File */