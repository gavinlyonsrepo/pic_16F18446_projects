
/*
* Project Name: TM1638 
* File: main.c 
* Description: demo file for library for  TM1637 module(LED & KEY).
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F18446
* IDE:  MPLAB X v5.05
* Development board: Microchip Curiosity Board, PIC16F1619
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
      TM1638init();
      reset();
      
        
       //test 1 Turn on single segment ghfedcba 
      //IN this case LED 0 segment g (middle dash)
       displaySS(0,0b01000000);
        setLED(0, 1);
        __delay_ms(2000);
         
      //Test 2 ASCII
      displayASCII(6, 'u');
      displayASCII(7, 'p');
      setLED(1, 1);
      __delay_ms(2000);
      
      //test 3 hex  number
      displayHex(0, 8);
      displayHex(1, 9);
      displayHex(2, 10);
      displayHex(3, 11);
      displayHex(4, 12);
      displayHex(5, 13);
      displayHex(6, 14);
      displayHex(7, 15);
       setLED(2, 1);
      __delay_ms(2000);
      
      //test 4 ASCII
      displayHex(0, 1);
      displayHex(1, 2);
      displayHex(2, 3);
      displayHex(3, 4);
      displayHex(4, 5);
      displayHex(5, 6);
      displayHex(6, 7);
      displayHex(7, 8);
      setLED(3, 1);
      __delay_ms(2000);
      
      // test 5 TEXT
      displayText("gav lyon");
      setLED(4, 1);
       __delay_ms(2000);
     
       //test 6 turn off LEDS
       setLED(0, 0);
       setLED(1, 0);
       setLED(2, 0);
       setLED(3, 0);
       setLED(4, 0);
       
    while (1)
    {
    // Test 7 scan buttons if pressed turn on opposite LED 
     uint8_t buttons = readButtons();
     doLEDs(buttons);   
    }
}

void doLEDs(uint8_t value) {
  for (uint8_t position = 0; position < 8; position++)
  {
    setLED(position, value & 1);
    value = value >> 1;
  }
}
/*  End of File */