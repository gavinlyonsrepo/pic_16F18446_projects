/*
* Project Name: Bluetooth
* File: main.c 
* Description: Example code for a Bluetooth module. 
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18446 
* IDE:  MPLABX v5.30
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18446 _projects
*/

#include "mcc_generated_files/mcc.h"
#include <stdint.h>
#include "DHT22.h"

#define INITDELAY 2000

int16_t temperature;
int16_t humidity;
char temp[6];

void DisplayData(void);

/*      Main application     */
void main(void)
{
    // initialize the device and enable the global and Peripheral Interrupts
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
     __delay_ms(INITDELAY);
    DHT22_init();
    while (1)
    {
        __delay_ms(2000);
        DisplayData();
    }
}
/*    End of Main    */


// Function display the data from DHT22 on OLED
void DisplayData(void)
{
        uint8_t status = DHT22_read(&temperature, &humidity);
        bool errorflag = false;
        switch (status)
        {
            case 1:
                if (temperature < 0) 
                    temp[0] = '-';
                else
                    temp[0] = '+';
                temp[1] = (temperature / 100) + '0';
                temp[2] = ((temperature/ 10) % 10) + '0';
                temp[3] = (temperature % 10) + '0';
                temp[4] = '\0';
                
                printf("%c%c%c C\n", temp[0], temp[1], temp[2]);
                
                temp[1] = (humidity / 100) + '0';
                temp[2] = ((humidity/ 10) % 10) + '0';
                
                printf("%c%c %%\n", temp[1],temp[2]);
                
            break;
            
            case 2: 
            case 3:
                errorflag = true;
            break;
            
            default:
               errorflag = true;
            break;           
        }
        
        if (errorflag == true)
        {
            printf("Error: %d\n", status);
        }
}

/** End of File */
 
