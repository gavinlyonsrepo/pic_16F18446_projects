/*
* Project Name: blink
* File: main.c 
* Description:  A program to blink an LED attached to RA2 every 2 Seconds in C using "delay_ms" function
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC:  PIC16F18313 
* IDE:  MPLAB X v5.05
* Development board: DM164137 Microchip Curiosity Board, PIC16F18313
* Created: March 2019
* URL: https://github.com/gavinlyonsrepo/pic_16F18313_projects
*/

#include "mcc_generated_files/mcc.h"

/*Main application */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    while (1)
    {
       LED_BLINK_Toggle();
       __delay_ms(2000);
    }
}
/* End of File */