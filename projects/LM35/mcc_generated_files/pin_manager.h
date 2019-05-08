/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F18446
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED_STATUS_RA2 aliases
#define LED_STATUS_RA2_TRIS                 TRISAbits.TRISA2
#define LED_STATUS_RA2_LAT                  LATAbits.LATA2
#define LED_STATUS_RA2_PORT                 PORTAbits.RA2
#define LED_STATUS_RA2_WPU                  WPUAbits.WPUA2
#define LED_STATUS_RA2_OD                   ODCONAbits.ODCA2
#define LED_STATUS_RA2_ANS                  ANSELAbits.ANSA2
#define LED_STATUS_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_STATUS_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_STATUS_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_STATUS_RA2_GetValue()           PORTAbits.RA2
#define LED_STATUS_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_STATUS_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_STATUS_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_STATUS_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_STATUS_RA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_STATUS_RA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_STATUS_RA2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_STATUS_RA2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISBbits.TRISB4
#define SDA1_LAT                  LATBbits.LATB4
#define SDA1_PORT                 PORTBbits.RB4
#define SDA1_WPU                  WPUBbits.WPUB4
#define SDA1_OD                   ODCONBbits.ODCB4
#define SDA1_ANS                  ANSELBbits.ANSB4
#define SDA1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SDA1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SDA1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SDA1_GetValue()           PORTBbits.RB4
#define SDA1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISBbits.TRISB6
#define SCL1_LAT                  LATBbits.LATB6
#define SCL1_PORT                 PORTBbits.RB6
#define SCL1_WPU                  WPUBbits.WPUB6
#define SCL1_OD                   ODCONBbits.ODCB6
#define SCL1_ANS                  ANSELBbits.ANSB6
#define SCL1_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SCL1_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SCL1_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SCL1_GetValue()           PORTBbits.RB6
#define SCL1_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set POT_ANC0 aliases
#define POT_ANC0_TRIS                 TRISCbits.TRISC0
#define POT_ANC0_LAT                  LATCbits.LATC0
#define POT_ANC0_PORT                 PORTCbits.RC0
#define POT_ANC0_WPU                  WPUCbits.WPUC0
#define POT_ANC0_OD                   ODCONCbits.ODCC0
#define POT_ANC0_ANS                  ANSELCbits.ANSC0
#define POT_ANC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define POT_ANC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define POT_ANC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define POT_ANC0_GetValue()           PORTCbits.RC0
#define POT_ANC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define POT_ANC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define POT_ANC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define POT_ANC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define POT_ANC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define POT_ANC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define POT_ANC0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define POT_ANC0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set LM35_ANC1 aliases
#define LM35_ANC1_TRIS                 TRISCbits.TRISC1
#define LM35_ANC1_LAT                  LATCbits.LATC1
#define LM35_ANC1_PORT                 PORTCbits.RC1
#define LM35_ANC1_WPU                  WPUCbits.WPUC1
#define LM35_ANC1_OD                   ODCONCbits.ODCC1
#define LM35_ANC1_ANS                  ANSELCbits.ANSC1
#define LM35_ANC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LM35_ANC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LM35_ANC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LM35_ANC1_GetValue()           PORTCbits.RC1
#define LM35_ANC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LM35_ANC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define LM35_ANC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define LM35_ANC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define LM35_ANC1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define LM35_ANC1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define LM35_ANC1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define LM35_ANC1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/