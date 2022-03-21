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
#include <stdio.h>

#define ADCRES  0.0012207 // ADC resolution per volt = 5/4096 , vcc/adc , 2^12

uint8_t counterUpdate = 0; //counter incremented by Timer0 overflow.

/* Function prototypes */

void DisplayTitle(void);
void DisplayData(void);

/* Main application */
void main(void) {
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    __delay_ms(15);
    PCF8574_LCDInit(LCDCursorTypeOn, 2, 16, 0x27);
    DisplayTitle();

    while (1) {
        if (counterUpdate == 1) // (counter is incremented in tmr0.c 16.3mSX200=3.26S)
        {
            DisplayData();
        }

    }
}
/* End of Main */

/* Function Space */


void DisplayTitle(void) {
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    PCF8574_LCDSendString("LM35 Sensor Data:");
}

//Display LM35 temp value in degrees and ADC on Line 2 of LCD

void DisplayData(void) {
    uint16_t ADCValue = 0;
    uint16_t temperature = 0;
    char ADCstr[9];
    char Tempstr[9];

    ADCValue = ADCC_GetSingleConversion(LM35_ANC1);
    sprintf(ADCstr, "V: %u%u%u%u", (ADCValue/1000)%10, (ADCValue/100)%10, (ADCValue/10)%10, ( ADCValue/1)%10);
    temperature = (ADCValue * (ADCRES * 10000));
    sprintf(Tempstr, "T: %u%u.%u%u", (temperature / 1000) % 10, (temperature / 100) % 10, (temperature / 10) % 10, (temperature / 1) % 10);
    
    PCF8574_LCDGOTO(LCDLineNumberTwo, 0);
    PCF8574_LCDSendString(ADCstr);
    PCF8574_LCDGOTO(LCDLineNumberTwo, 8);
    PCF8574_LCDSendString(Tempstr);
}

void TMR0_ISR(void) {
    // clear the TMR0 interrupt flag
    PIR0bits.TMR0IF = 0;
    if (TMR0_InterruptHandler) {
        TMR0_InterruptHandler();
    }

    // add your TMR0 interrupt custom code
    // (counter is incremented in tmr0.c 16.3mS X 200 = 3.26S)
    // ---------- Glyons ------------
    counterUpdate++;
    if (counterUpdate == 200) {
        counterUpdate = 0;
    }
}

/* End of File */