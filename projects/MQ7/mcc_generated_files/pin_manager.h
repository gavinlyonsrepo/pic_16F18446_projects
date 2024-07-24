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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC16F18446
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
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

// get/set LED_RA5 aliases
#define LED_RA5_TRIS                 TRISAbits.TRISA5
#define LED_RA5_LAT                  LATAbits.LATA5
#define LED_RA5_PORT                 PORTAbits.RA5
#define LED_RA5_WPU                  WPUAbits.WPUA5
#define LED_RA5_OD                   ODCONAbits.ODCA5
#define LED_RA5_ANS                  ANSELAbits.ANSA5
#define LED_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_RA5_GetValue()           PORTAbits.RA5
#define LED_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_RA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_RA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_RA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_RA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_RA5_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define LED_RA5_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

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

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

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

// get/set SENSOR_ANC0 aliases
#define SENSOR_ANC0_TRIS                 TRISCbits.TRISC0
#define SENSOR_ANC0_LAT                  LATCbits.LATC0
#define SENSOR_ANC0_PORT                 PORTCbits.RC0
#define SENSOR_ANC0_WPU                  WPUCbits.WPUC0
#define SENSOR_ANC0_OD                   ODCONCbits.ODCC0
#define SENSOR_ANC0_ANS                  ANSELCbits.ANSC0
#define SENSOR_ANC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SENSOR_ANC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SENSOR_ANC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SENSOR_ANC0_GetValue()           PORTCbits.RC0
#define SENSOR_ANC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SENSOR_ANC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SENSOR_ANC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SENSOR_ANC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SENSOR_ANC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SENSOR_ANC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SENSOR_ANC0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SENSOR_ANC0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set PB_RC4 aliases
#define PB_RC4_TRIS                 TRISCbits.TRISC4
#define PB_RC4_LAT                  LATCbits.LATC4
#define PB_RC4_PORT                 PORTCbits.RC4
#define PB_RC4_WPU                  WPUCbits.WPUC4
#define PB_RC4_OD                   ODCONCbits.ODCC4
#define PB_RC4_ANS                  ANSELCbits.ANSC4
#define PB_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define PB_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define PB_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define PB_RC4_GetValue()           PORTCbits.RC4
#define PB_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define PB_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define PB_RC4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define PB_RC4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define PB_RC4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define PB_RC4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define PB_RC4_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define PB_RC4_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

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