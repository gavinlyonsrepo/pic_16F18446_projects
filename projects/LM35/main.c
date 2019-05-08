/*
* Project Name: LM35_16F18446
* File: main.c 
* Description: Display a LM35 sensor data + analog input on a 
* HD44780-based character LCD 16x02 in I2C mode.
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
#include "lcd.h"

#define ADCRES  0.0012207 // ADC  per volt = 5/4096 , vcc/adc , 2^12

/* Function prototypes */
void Setup(void);
void  DisplayLine1(void);
void  DisplayLine2(void);

/* Main application */
void main(void)
{
    Setup();
    while (1)
    {
        if (counter == 1)  // (counter is incremented in tmr0.c 16.3mSX200=3.26S)
        {
            DisplayLine1();
            DisplayLine2();  
        }

    }
}
/* End of Main */

/* Function Space */

// initialize the device
void Setup (void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    __delay_ms(15);
    lcd_init ();
    LED_STATUS_RA2_SetHigh();
}

//Display ADC value in volts and ADC on Line 1 of LCD
void DisplayLine1(void)
{      
        uint16_t pot_value = 0;
        uint16_t voltage = 0;
        char ADCstr[5];
        char Voltstr[5];
        
        pot_value =  ADCC_GetSingleConversion(POT_ANC0);
        voltage = (pot_value * ADCRES) * 100;
        sprintf(ADCstr, "%u%u%u%u", (pot_value/1000)%10, (pot_value/100)%10, (pot_value/10)%10, ( pot_value/1)%10);
        sprintf(Voltstr, "%u%u.%u%u", (voltage/1000)%10, (voltage/100)%10, (voltage/10)%10, ( voltage/1)%10);
        
        lcd_send_cmd (LCD_LINE1);
        lcd_send_string ("POT:  ");
        lcd_send_string (ADCstr);
        lcd_send_string (" ");
        lcd_send_string (Voltstr);
}

//Display LM35 temp value in degrees and ADC on Line 2 of LCD
void DisplayLine2(void)
{
        uint16_t pot_value = 0;
        uint16_t temp = 0;
        char ADCstr[5];
        char Tempstr[5];
        
        pot_value =  ADCC_GetSingleConversion(LM35_ANC1);
        temp = (pot_value * ADCRES) * 10000;
        sprintf(ADCstr, "%u%u%u%u", (pot_value/1000)%10, (pot_value/100)%10, (pot_value/10)%10, ( pot_value/1)%10);
        sprintf(Tempstr, "%u%u.%u%u", (temp/1000)%10, (temp/100)%10, (temp/10)%10, ( temp/1)%10);
        
        lcd_send_cmd (LCD_LINE2);
        lcd_send_string ("LM35: ");
        lcd_send_string (ADCstr);
        lcd_send_string (" ");
        lcd_send_string (Tempstr);
}
/* End of File */