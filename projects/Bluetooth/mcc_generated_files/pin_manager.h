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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F18446
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
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

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set POT aliases
#define POT_TRIS                 TRISCbits.TRISC0
#define POT_LAT                  LATCbits.LATC0
#define POT_PORT                 PORTCbits.RC0
#define POT_WPU                  WPUCbits.WPUC0
#define POT_OD                   ODCONCbits.ODCC0
#define POT_ANS                  ANSELCbits.ANSC0
#define POT_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define POT_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define POT_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define POT_GetValue()           PORTCbits.RC0
#define POT_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define POT_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define POT_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define POT_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define POT_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define POT_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define POT_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISCbits.TRISC3
#define LED_LAT                  LATCbits.LATC3
#define LED_PORT                 PORTCbits.RC3
#define LED_WPU                  WPUCbits.WPUC3
#define LED_OD                   ODCONCbits.ODCC3
#define LED_ANS                  ANSELCbits.ANSC3
#define LED_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED_GetValue()           PORTCbits.RC3
#define LED_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LED_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LED_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

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