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

// get/set STBpin aliases
#define STBpin_TRIS                 TRISCbits.TRISC0
#define STBpin_LAT                  LATCbits.LATC0
#define STBpin_PORT                 PORTCbits.RC0
#define STBpin_WPU                  WPUCbits.WPUC0
#define STBpin_OD                   ODCONCbits.ODCC0
#define STBpin_ANS                  ANSELCbits.ANSC0
#define STBpin_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define STBpin_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define STBpin_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define STBpin_GetValue()           PORTCbits.RC0
#define STBpin_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define STBpin_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define STBpin_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define STBpin_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define STBpin_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define STBpin_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define STBpin_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define STBpin_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set CLKpin aliases
#define CLKpin_TRIS                 TRISCbits.TRISC1
#define CLKpin_LAT                  LATCbits.LATC1
#define CLKpin_PORT                 PORTCbits.RC1
#define CLKpin_WPU                  WPUCbits.WPUC1
#define CLKpin_OD                   ODCONCbits.ODCC1
#define CLKpin_ANS                  ANSELCbits.ANSC1
#define CLKpin_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define CLKpin_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define CLKpin_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define CLKpin_GetValue()           PORTCbits.RC1
#define CLKpin_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define CLKpin_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define CLKpin_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define CLKpin_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define CLKpin_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define CLKpin_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define CLKpin_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define CLKpin_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set DIOpin aliases
#define DIOpin_TRIS                 TRISCbits.TRISC2
#define DIOpin_LAT                  LATCbits.LATC2
#define DIOpin_PORT                 PORTCbits.RC2
#define DIOpin_WPU                  WPUCbits.WPUC2
#define DIOpin_OD                   ODCONCbits.ODCC2
#define DIOpin_ANS                  ANSELCbits.ANSC2
#define DIOpin_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define DIOpin_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define DIOpin_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define DIOpin_GetValue()           PORTCbits.RC2
#define DIOpin_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define DIOpin_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define DIOpin_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define DIOpin_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define DIOpin_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define DIOpin_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define DIOpin_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define DIOpin_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

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