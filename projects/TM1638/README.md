

Overview
--------------------------------------------
* Name: TM1638
* Description: A library to display data on a 8-digit TM1638 seven segment module
This module is the (KEY & LED) variant which has 8 LED's and 8 Push buttons.
Supports the models with bi colour LEDS and single colour LEDS.
* Author: Gavin Lyons.
* URL : https://github.com/gavinlyonsrepo/pic_16F18446_projects
* Model : 1 & 3
* Complier: xc8 v2.40 compiler
* PIC: PIC16F18446
* IDE:  MPLAB X v6.00
* Note: This library is a fork of a section of the [Arduino library](https://github.com/gavinlyonsrepo/TM1638plus) 
"TM1638plus" which is also written by Author and can be found in Arduino library manger. 

Features
----------------------
These Tm1638 modules are commonly available. 
They consist of an 8-digit seven segment display with decimal points,
8 Leds and 8 Push buttons, controlled by Tm1638 IC.
There are various models. This libray supports model 1 & 3.
If you have the push buttons(#16) only module, 
see model 2 entry on menu of main PIC_16F1886 Readme. 

| Model No | Module Name | LEDS | KEYS | 
| ------ | ------ |  ------ | ------ |
| One | TM1638 LED & KEY | 8 | 8 red colour |
| Two | TM1638 KEYS QYF  | 0 | 16 |
| Three | LKM1638  | 8 | 8 bi colour, green and red |

Connections to PIC: 

1. RC0 = STB
2. RC1 = CLK
3. RC2 = DIO

In order to switch between model 1 & model 3 in the main.c test file 
change the boolean LKM1638 at start.

Model 1
-------------------

Two 4 digit 3461AS (common anode , RED , decimal point) are used in this module
giving a total of 8 digits. A TM1638 controller chip drives the unit.
The unit is marked (LED & KEY) 
The library is contained in two files.
The commented functions can be found in library header file TM1638.h.
The library support ASCII ,text ,Hex and allows for setting individual segments,
and the decimal point of segment.
The main.c contains a set of tests demonstrating library functions.

For more information on library functions see commented headers in header file. 

![ module ](https://github.com/gavinlyonsrepo/pic_16F18446_projects/blob/master/images/TM1638.jpg)

Model Three
-----------------------------------------

There are different PCB's  of these modules on market, 
This library was tested on version 1.3 below.. 

1. LKM1638 v1.1
2. LKM1638 v1.2
3. TM1638 V1.3 

This module is a variant of Model 1. The differences are the LEDs are bigger and bi-color
both red and green, The seven segment display is larger and extra connectors are added for Daisy chaining. 

Two 4 digit KYX-5461AS-7.3 (.54 inch, 4 digit ,common cathode,  decimal point, RED)are used in this module
giving a total of 8 digits. 

![ module ](https://github.com/gavinlyonsrepo/TM1638plus/blob/master/extra/images/tm16384.jpg)*

setLED and setLEDs functions behaviour is the only difference in code base between 1 and 3.

SetLED: The difference is when you call the setLED function you pass the following to get LEDs to change colour.

| Model | setLED Value | result | 
|    ----   |    ----   |    ----   |
|    1 & 3  |    0   |    LED off   |
|    3   |    1   |    Led green  |
|    3   |    2   |    LED red   |
|    1   |    1   |    LED on   |

SetLEDs: When you pass call the setLEDs function you can pass a word pattern where upper byte is turns LEDs green and lower byte turns LEDs red. Model one ignores lower byte always set to 0x00. 

1. Model 3 setLEDs(word) = 0xGGRR
3. Model 1 setLEDs(word) = 0xRR00

For more detailed information on functions see commented headers in header file(.h).
