/*
* Project Name: LM35_16F18446
* File: main.c 
* Description: Display a LM35 sensor data on a 
* HD44780-based character LCD 16x02 in I2C mode(PCF8574).
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18446 
* IDE:  MPLAB X v6.0
* Created April 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18446 _projects
*/

#include "mcc_generated_files/mcc.h"
#include "HD44780_I2C_lcd.h"

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
    PCF8574_LCDInit(CURSOR_OFF);
}

//Display ADC value in volts and ADC on Line 1 of LCD
void DisplayLine1(void)
{      
    PCF8574_LCDGOTO(1, 0);
    PCF8574_LCDSendString("LM35 Sensor Data:");
}

//Display LM35 temp value in degrees and ADC on Line 2 of LCD
void DisplayLine2(void)
{
        uint16_t adc_value = 0;
        uint16_t temp = 0;
        char ADCstr[5];
        char Tempstr[5];
        
        adc_value =  ADCC_GetSingleConversion(LM35_ANC1);
        temp = (adc_value * ADCRES) * 10000;
        sprintf(ADCstr, "%u%u%u%u", (adc_value/1000)%10, (adc_value/100)%10, (adc_value/10)%10, ( adc_value/1)%10);
        sprintf(Tempstr, "%u%u.%u%u", (temp/1000)%10, (temp/100)%10, (temp/10)%10, ( temp/1)%10);
        
        PCF8574_LCDGOTO(2, 0);
        PCF8574_LCDSendString ("V: ");
        PCF8574_LCDSendString (ADCstr);
        PCF8574_LCDSendString (" T: ");
        PCF8574_LCDSendString (Tempstr);
}
/* End of File */