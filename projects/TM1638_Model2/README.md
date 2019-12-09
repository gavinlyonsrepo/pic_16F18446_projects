Overview
--------------------------------------------
* Name: TM1638plus
* Description: An PIC library to display data on a 8-digit TM1638 seven segment module
This library supports (16 KEY)(QFY) variant which has 16 pushbuttons.
* Author: Gavin Lyons.
* PIC: PIC 16F18446
* URL : https://github.com/gavinlyonsrepo/pic_16F18446_projects
* Model : 2
* Development board: Microchip Curiosity Board DM164137
* Complier: xc8 v2.05 compiler
* PIC: PIC16F18446
* IDE:  MPLAB X v5.15
* MCC version: 3.85
* Note: This library is a fork of a section of the Arduino library "TM1638plus" which is also
written by Author and can be found in Arduino library manger. 


Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)

Features
----------------------

These Tm1638 modules are commonly available. 
They consist of an 8-digit seven segment display with decimal points,
16 Push buttons, controlled by Tm1638 IC.
I have seen two variants, this library is for the one Model 2
If you want model 1 ,
See "TM1638 Seven Segment 8 LED and 8 Push Button Module library" entry on menu of main PIC_16F1886 Readme.  

| Model No | Module Name | LEDS | KEYS | 
| ------ | ------ |  ------ | ------ |
| One | TM1638 LED & KEY | 8 | 8 |
| Two | TM1638 KEYS QYF  | 0 | 16 |


Connections to PIC: 

1. GPIO = RC0 =  STB = Strobe
2. GPIO  = RC1 =  CLK  = Clock
3. GPIO = RC2  = DIO = Data input / output  (Configure as open drain)

This library supports this variants of the TM1638 module

1. TM1638 16 KEY , (QYF) 16 Push buttons (MODEL 2)


**========================================================================**

**Model 2: TM1638 Module 16 Push buttons (16 KEY) (QYF)**

![ module ](https://github.com/gavinlyonsrepo/TM1638plus/blob/master/extra/images/tm16381.jpg)

![ sch ](https://github.com/gavinlyonsrepo/TM1638plus/blob/master/extra/images/tm16382.jpg)


They consist of an 8-digit seven segment display with decimal points,
and 16 Push buttons.

Two 4 digit 3461BS-1 (34 inch, 4 digit ,common Anode,  decimal point, RED)are used in this module
giving a total of 8 digits. A TM1638 controller chip drives the unit.


**Model 2 Library Functions**

The commented functions can be found in library header file TM1638plus_Model2.h.
The TM1638plus_TEST_Model2.ino contains a set of tests demonstrating library functions.

For more detailed information see commented headers in header file(.h).

1. Manually set segments to create custom patterns.
2. Print a text string.
3. Read buttons status. User may have to debounce buttons depending on application.
4. Reset and init module functions.
5. Adjust brightness of module. Support 8 degree brightness adjustment.
If user wishes to change the default brightness at start-up change.
The DEFAULT_BRIGHTNESS define in header file. 
6. Decimal point function is supported.

**Note NB**

Swapped display Issue:
For some users using the arduino library the nibbles in information display byte 
where swapped around. This is because there are different modules on market with different wiring. 
Same function but different pcb which requires a small code change.
See issue #3 on [github](https://github.com/gavinlyonsrepo/TM1638plus/issues/3) 
called Swapped display :: "ABCDEFGH" becomes "EFGHABCD". 

If you test library and you see this issue, in order to fix this when you init the 
display, set the parameter "swap_nibbles" to True, The default is false.

| PCB Model Label | Operation | Init function call  |
| ------ | ------ | ------ | 
| QYF-TM1638 | default operation | TM1638Init_Model2(false) | 
| QYF-TM1638 -Ver 1.0 | Swapped display Fix | TM1638Init_Model2(true) |  