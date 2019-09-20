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

// get/set DIGIT1 aliases
#define DIGIT1_TRIS                 TRISAbits.TRISA0
#define DIGIT1_LAT                  LATAbits.LATA0
#define DIGIT1_PORT                 PORTAbits.RA0
#define DIGIT1_WPU                  WPUAbits.WPUA0
#define DIGIT1_OD                   ODCONAbits.ODCA0
#define DIGIT1_ANS                  ANSELAbits.ANSA0
#define DIGIT1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define DIGIT1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define DIGIT1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define DIGIT1_GetValue()           PORTAbits.RA0
#define DIGIT1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define DIGIT1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define DIGIT1_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define DIGIT1_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define DIGIT1_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define DIGIT1_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define DIGIT1_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define DIGIT1_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set DIGIT2 aliases
#define DIGIT2_TRIS                 TRISAbits.TRISA1
#define DIGIT2_LAT                  LATAbits.LATA1
#define DIGIT2_PORT                 PORTAbits.RA1
#define DIGIT2_WPU                  WPUAbits.WPUA1
#define DIGIT2_OD                   ODCONAbits.ODCA1
#define DIGIT2_ANS                  ANSELAbits.ANSA1
#define DIGIT2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define DIGIT2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define DIGIT2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define DIGIT2_GetValue()           PORTAbits.RA1
#define DIGIT2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define DIGIT2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define DIGIT2_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define DIGIT2_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define DIGIT2_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define DIGIT2_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define DIGIT2_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define DIGIT2_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set SER aliases
#define SER_TRIS                 TRISCbits.TRISC0
#define SER_LAT                  LATCbits.LATC0
#define SER_PORT                 PORTCbits.RC0
#define SER_WPU                  WPUCbits.WPUC0
#define SER_OD                   ODCONCbits.ODCC0
#define SER_ANS                  ANSELCbits.ANSC0
#define SER_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SER_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SER_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SER_GetValue()           PORTCbits.RC0
#define SER_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SER_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SER_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SER_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SER_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SER_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SER_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SER_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SCLK aliases
#define SCLK_TRIS                 TRISCbits.TRISC1
#define SCLK_LAT                  LATCbits.LATC1
#define SCLK_PORT                 PORTCbits.RC1
#define SCLK_WPU                  WPUCbits.WPUC1
#define SCLK_OD                   ODCONCbits.ODCC1
#define SCLK_ANS                  ANSELCbits.ANSC1
#define SCLK_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SCLK_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SCLK_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SCLK_GetValue()           PORTCbits.RC1
#define SCLK_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SCLK_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SCLK_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SCLK_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SCLK_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SCLK_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SCLK_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SCLK_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RCLK aliases
#define RCLK_TRIS                 TRISCbits.TRISC2
#define RCLK_LAT                  LATCbits.LATC2
#define RCLK_PORT                 PORTCbits.RC2
#define RCLK_WPU                  WPUCbits.WPUC2
#define RCLK_OD                   ODCONCbits.ODCC2
#define RCLK_ANS                  ANSELCbits.ANSC2
#define RCLK_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RCLK_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RCLK_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RCLK_GetValue()           PORTCbits.RC2
#define RCLK_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RCLK_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RCLK_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define RCLK_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define RCLK_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define RCLK_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define RCLK_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define RCLK_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

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