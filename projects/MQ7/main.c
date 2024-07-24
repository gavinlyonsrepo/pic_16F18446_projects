/*!
 * @file main.c
 * @desc Read a Mq7 sensor and display its data on an LCD
 * @url See https://github.com/gavinlyonsrepo/pic_16F18446_projects for details. 
 */

#include "mcc_generated_files/mcc.h"
#include "HD44780_I2C_lcd.h"
#include "MQ7.h"

#define PWM_HIGH_STATE 510 // 5V 
#define PWM_LOW_STATE 144  // MOSFET 1.4V 

#define HEAT_ON_TIME 60000 // seconds , High voltage heating  period
#define HEAT_LOW_TIME 90000 // seconds , Low voltage heating period
#define READ_DELAY 1000 // seconds, delay between starting each sensor read cycle 
#define READ_DELAY_TWO 50 // delay between switching  sensor back to 5V and reading it after low heating cycle


void DisplayTitle(void);
void CalibrateSensor(void);

/* Main application */
void main(void)
{
     // variables
    char dataStr[16];
    uint16_t SensorReadCount = 1;
    float SensorPPM = 0.0;
    
     // initialize the device
     __delay_ms(1000);
    SYSTEM_Initialize();
    __delay_ms(1000);
    
    // Init state LCD and LED  
    LED_RA5_SetHigh();
    PCF8574_LCDInit(LCDCursorTypeOn, 2, 16, 0x27);
    
    // Display title
    DisplayTitle();
     
     // Calibrate sensor 
     CalibrateSensor();
     
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    while (1)
    {
        SensorPPM = 0.0;
         // (1) 5 Volt PWM on Sensor
        PWM6_LoadDutyValue(PWM_HIGH_STATE); //510 is DC 5V output
        LED_RA5_SetLow();
        __delay_ms(HEAT_ON_TIME);            // heat for 60 second  

        // (2) 1.4 Volt signal now reduce the heating power  
        PWM6_LoadDutyValue(PWM_LOW_STATE);  // turn the heater to approx 1,4V  
        LED_RA5_SetHigh();
        __delay_ms(HEAT_LOW_TIME);            // wait for 90 seconds  

        // (3) we need to read the sensor at 5V. 
        PWM6_LoadDutyValue(PWM_HIGH_STATE); // 512 is DC 5V output 
        __delay_ms(READ_DELAY_TWO);   
        SensorPPM = MQ7readPpm();

        // (4)  send PPM data to LCD
         PCF8574_LCDClearScreen();
        PCF8574_LCDGOTO(LCDLineNumberOne, 0);
        sprintf(dataStr, "Count =  %u", SensorReadCount);
        SensorReadCount++;
        PCF8574_LCDSendString(dataStr);
        
        PCF8574_LCDGOTO(LCDLineNumberTwo, 0);
        sprintf(dataStr, "PPM = %.2f", SensorPPM);
        PCF8574_LCDSendString(dataStr);
    } // main loop 
} // end of main 


void DisplayTitle(void) {
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    PCF8574_LCDSendString("MQ7");
      __delay_ms(1000);
}

void CalibrateSensor(void) {
    if (PB_RC4_GetValue() == HIGH)
    {
        PCF8574_LCDClearLine(LCDLineNumberOne);
        PCF8574_LCDGOTO(LCDLineNumberOne, 0);
        PCF8574_LCDSendString("Calibrate");
        MQ7calibrate();
    }
        PCF8574_LCDClearScreen();
        PCF8574_LCDGOTO(LCDLineNumberOne, 0);
        PCF8574_LCDSendString("Testing");
}

/* End of File */