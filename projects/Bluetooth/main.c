/*
* Project Name: Bluetooth
* File: main.c 
* Description: Exmaple code for a Bluetooth module. 
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F18446 
* IDE:  MPLAB X v5.15
* Development board: Microchip Curiosity Board, DM164137
* Created April 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18446 _projects
*/

#include "mcc_generated_files/mcc.h"
#include <stdint.h>


uint16_t potvalue=0; //var to hold pot value from RC0

/*      Main application     */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    while (1)
    {
        __delay_ms(2000);
        potvalue =  ADCC_GetSingleConversion(POT);
        printf("%d POT \n", potvalue);

    }
}
/** End of File */
 
