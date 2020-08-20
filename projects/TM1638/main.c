
/*
 * Project Name: TM1638 
 * File: main.c 
 * Description: demo file for library for TM1638 module(LED & KEY).
runs thru a series of tests. 
 * Author: Gavin Lyons.
 * Complier: xc8 v2.05 compiler
 * PIC: PIC16F18446
 * IDE:  MPLAB X v5.05
 * Development board: Microchip Curiosity Board
 * Created May 2019
 */

#include "mcc_generated_files/mcc.h"
#include "TM1638.h"
#include <stdio.h>

// Some vars and defines for the tests.
#define myTestDelay  5000
#define myTestDelay3 3000
#define myTestDelay1 1000

// Set to true for: LKM1638(aka model 3) the variant with bi-color leds, green & red
// Set to false for: Tm1638(aka model 1) the variant with just red LEDS
bool LKM1638 = false;
#define TM_1638_RED_LED 0x02
#define TM_1638_GREEN_LED 0x01
#define TM_1638_OFF_LED 0x00

// ---------------- Function prototypes -------------------
void Setup(void);
void Test1(void); // Brightness
void Test2(void); // ASCII display
void Test3(void); // TEST 3 Set a single segment
void Test4(void); // Hex digits
void Test5(void); // Text String with Decimal point
void Test6(void); // TEXT + ASCII combo
void Test7(void); // Integer Decimal number
void Test8(void); // Text String + Float hack
void Test9(void); // Text String + decimal number
void Test10(void); // Multiple Decimal points
void Test11(void); // Display Overflow
void Test12(void); // Scrolling text
void Test13(void); // setLED and setLEDs for model 1 (red led only)
void Test13b(void); // setLED and setLEDs for model 3(green and red bicolour LEDS)
void Test14(void); // Buttons 

/*  --------------  MAIN LOOP ----------------  */
void main(void) {
    Setup();
    Test1(); // Brightness
    Test2(); // ASCII display
    Test3(); // TEST 3 Set a single segment
    Test4(); // Hex digits
    Test5(); // Text String with Decimal point
    Test6(); // TEXT + ASCII combo
    Test7(); // Integer Decimal number
    Test8(); // Text String + Float hack
    Test9(); // Text String + decimal number
    Test10(); // Multiple Decimal points
    Test11(); // Display Overflow
    Test12(); // Scrolling text n/a

    if (LKM1638 == false)
        Test13(); // setLED and setLEDs for model 1 (red led only)
    else
        Test13b(); // setLED and setLEDs for model 3(green and red bicolour LEDS)

    Test14(); // Buttons 
}
// ---------------- End of main -------------------


// ----------- Function space ---------------------

void Setup(void) {
    // initialize the device
    SYSTEM_Initialize();
    TM1638Init();
    TM1638Reset();
    TM1638setLED(0, 1);
    __delay_ms(myTestDelay);
    TM1638Reset(); // test reset
}

void Test1() {
    // Test 1  Brightness and reset
    for (uint8_t brightness = 0; brightness < 8; brightness++) {
        TM1638brightness(brightness);
        TM1638displayText("00000000");
        __delay_ms(myTestDelay1);
    }
    TM1638Reset();
    // restore default brightness
    TM1638brightness(0x02);
}

void Test2() {
    //Test 2 ASCII display 2.348

    TM1638displayASCIIwDot(0, '2');
    TM1638displayASCII(1, '3');
    TM1638displayASCII(2, '4');
    TM1638displayASCII(3, '8');
    __delay_ms(myTestDelay);
    TM1638Reset();
}

void Test3() {
    //TEST 3 single segment (pos, (dp)gfedcba)
    //In this case  segment g (middle dash) of digit position 7
    TM1638display7Seg(7, 0b01000000);
    __delay_ms(myTestDelay);
}

void Test4() {
    // Test 4 Hex digits.
    TM1638displayHex(0, 1);
    TM1638displayHex(1, 2);
    TM1638displayHex(2, 3);
    TM1638displayHex(3, 4);
    TM1638displayHex(4, 5);
    TM1638displayHex(5, 6);
    TM1638displayHex(6, 7);
    TM1638displayHex(7, 8);
    __delay_ms(myTestDelay);

    TM1638displayHex(0, 8);
    TM1638displayHex(1, 9);
    TM1638displayHex(2, 10);
    TM1638displayHex(3, 11);
    TM1638displayHex(4, 12);
    TM1638displayHex(5, 13);
    TM1638displayHex(6, 14);
    TM1638displayHex(7, 15);
    __delay_ms(myTestDelay);
}

void Test5() {
    // Test 5 TEXT  with dec point
    // abcdefgh with decimal point for c and d
    TM1638displayText("abc.d.efgh");
    __delay_ms(myTestDelay);
}

void Test6() {
    // Test6  TEXT + ASCII combo
    // ADC=.2.548
    char text1[] = "ADC=.";
    TM1638displayText(text1);
    TM1638displayASCIIwDot(4, '2');
    TM1638displayASCII(5, '5');
    TM1638displayASCII(6, '4');
    TM1638displayASCII(7, '8');
    __delay_ms(myTestDelay);
    TM1638Reset();
}

void Test7() {
    // TEST 7a Integer
    TM1638displayIntNum(87, false); // "87      "
    __delay_ms(myTestDelay);
    // TEST 7b Integer
    TM1638displayIntNum(12345, true); // "00012345"
    __delay_ms(myTestDelay);
    TM1638Reset();
    // TEST 7b TM1638DisplayDecNumNIbble
    TM1638DisplayDecNumNibble(1488, 9944, false); // "14889944"
    __delay_ms(myTestDelay);
    TM1638DisplayDecNumNibble(153, 699, true); // "01530699"
    __delay_ms(myTestDelay);
}

void Test8() {
    // TEST 8  TEXT STRING + integer SSSSIIII
    char workStr[11];
    uint16_t data = 225;
    sprintf(workStr, "ADC=.%04d", data); // "ADC=.0225"
    TM1638displayText(workStr);
    __delay_ms(myTestDelay);
}

void Test9() {
    // TEST 9 Text String + Float  SSSSFFFF ,  just one possible method.
    float voltage = 12.45;
    uint16_t temp = 0;
    char workStr[11];
    uint8_t digit1, digit2, digit3, digit4;
    voltage = voltage * 100; // 1245
    temp = (uint16_t) voltage;
    digit1 = (temp / 1000) % 10;
    digit2 = (temp / 100) % 10;
    digit3 = (temp / 10) % 10;
    digit4 = temp % 10;

    sprintf(workStr, "ADC=.%d%d.%d%d", digit1, digit2, digit3, digit4);
    TM1638displayText(workStr); //12.45.VOLT
    __delay_ms(myTestDelay);
    TM1638Reset();
}

void Test10() {
    //TEST 10 Multiple dots test
    TM1638displayText("Hello...");
    __delay_ms(myTestDelay);
    TM1638displayText("...---..."); //SOS in morse
    __delay_ms(myTestDelay);
}

void Test11() {
    //TEST11 user overflow
    TM1638displayText("1234567890abc"); //should display just 12345678
    __delay_ms(myTestDelay);
    TM1638Reset();
}

void Test12() {
    //TEST 12 n/a 
    __nop();
}

// Model 1
void Test13() {
    //Test 13 LED display
    uint8_t LEDposition = 0;

    // Test 13A Turn on redleds with setLED
    for (LEDposition = 0; LEDposition < 8; LEDposition++) {
        TM1638setLED(LEDposition, 1);
        __delay_ms(500);
        TM1638setLED(LEDposition, 0);
    }

    // TEST 13b test setLEDs function (0xLEDXX) (L0-L7,XX)
    // For model 1 just use upper byte , lower byte is is used by model3 for bi-color leds leave at 0x00. 
    TM1638setLEDs(0xFF00); //all red
    __delay_ms(3000);
    TM1638setLEDs(0xF000); // L0-L7 XXXXLLLL
    __delay_ms(3000);
    TM1638setLEDs(0x0000); //all off
    __delay_ms(3000);

}

// Model 3
void Test13b() {
    //Test 13 LED display
    uint8_t LEDposition = 0;

    // Test 13A Turn on green leds with setLED
    for (LEDposition = 0; LEDposition < 8; LEDposition++) {
        TM1638setLED(LEDposition, TM_1638_GREEN_LED);
        __delay_ms(500);
        TM1638setLED(LEDposition, TM_1638_OFF_LED);
    }

    // Test 13b turn on red LEDs with setLED
    for (LEDposition = 0; LEDposition < 8; LEDposition++) {
        TM1638setLED(LEDposition, TM_1638_RED_LED);
        __delay_ms(500);
        TM1638setLED(LEDposition, TM_1638_OFF_LED);
    }

    // TEST 13c test setLEDs function (0xgreenred) (L0-L7, L0-L7)
    TM1638setLEDs(0xE007); //L0-L7 RRRXXGGG 
    __delay_ms(myTestDelay3);
    TM1638setLEDs(0xF00F); // L0-L7 RRRRGGGG
    __delay_ms(myTestDelay3);
    TM1638setLEDs(0xFE01); // L0-L7 RGGGGGGG
    __delay_ms(myTestDelay3);
    TM1638setLEDs(0x00FF); //all red
    __delay_ms(myTestDelay3);
    TM1638setLEDs(0xFF00); //all green
    __delay_ms(myTestDelay3);
    TM1638setLEDs(0x0000); //all off
    __delay_ms(myTestDelay3);
}

void Test14() {
    //Test 14 buttons and LED test, press switch number S-X to turn on LED-X, where x is 1-8.
    //The HEx value of switch is also sent to Serial port.
    TM1638displayText("buttons ");
    while (1) // Loop here forever
    {
        uint8_t buttons = TM1638readButtons();
        /* buttons contains a byte with values of button s8s7s6s5s4s3s2s1
         HEX  :  Switch no : Binary
         0x01 : S1 Pressed  0000 0001 
         0x02 : S2 Pressed  0000 0010 
         0x04 : S3 Pressed  0000 0100 
         0x08 : S4 Pressed  0000 1000 
         0x10 : S5 Pressed  0001 0000 
         0x20 : S6 Pressed  0010 0000 
         0x40 : S7 Pressed  0100 0000 
         0x80 : S8 Pressed  1000 0000  
         */
        TM1638displayIntNum(buttons, true);
        __delay_ms(250);
    }
}

/**************  End of File ***********************/