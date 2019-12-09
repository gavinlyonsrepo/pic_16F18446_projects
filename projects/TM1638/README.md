

Overview
--------------------------------------------
* Name: TM1638
* Description: A library to display data on a 8-digit TM1638 seven segment module
This module is the (KEY & LED) variant which has 8 LED's and 8 Push buttons.
* Author: Gavin Lyons.
* URL : https://github.com/gavinlyonsrepo/pic_16F18446_projects
* Model : 1
* Complier: xc8 v2.05 compiler
* PIC: PIC16F18446
* IDE:  MPLAB X v5.05
* MCC version: 3.75
* Development board: Microchip Curiosity Board DM164137
* Note: This library is a fork of a section of the Arduino library "TM1638plus" which is also
written by Author and can be found in Arduino library manger. 


Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)

Features
----------------------


**TM1638 Module 8 Push buttons 8 LEDS (LED & KEY) MODEL 1**

These Tm1638 modules are commonly available. 
They consist of an 8-digit seven segment display with decimal points,
8 Leds and 8 Push buttons, controlled by Tm1638 IC.
I have seen two variants, this library is for the one marked LED & KEY( MODEL 1).
If you have the push buttons(#16) only module, see model 2 entry on menu of main PIC_16F1886 Readme. 

| Model No | Module Name | LEDS | KEYS | 
| ------ | ------ |  ------ | ------ |
| One | TM1638 LED & KEY | 8 | 8 |
| Two | TM1638 KEYS QYF  | 0 | 16 |


Two 4 digit 3461AS (common anode , RED , decimal point) are used in this module
giving a total of 8 digits. A TM1638 controller chip drives the unit.
The unit is marked (LED & KEY) 
The library is contained in two files.

Connections to PIC: 

1. RC0 = STB
2. RC1 = CLK
3. RC2 = DIO


**Library Functions**

The commented functions can be found in library header file TM1638.h.
The library support ASCII ,text ,Hex and allows for setting individual segments,
and the decimal point of segment.
The main.c contains a set of tests demonstrating library functions.

For more information see commented headers in header file. 

1. Print an ASCII character.
2. Print an ASCII character with a dot/decimal point.
3. Print a Hexadecimal digit(0-15).
4. Print a text string(dots are replaced and dot is turned on preceding digit), 
"abc.def" becomes "abcdef" with c decimal point segment switched on.
5. Read buttons status.
6. Switch LEDS on and off.
7. Reset and init module functions.
8. Adjust brightness of module. Support 8 degree brightness adjustment.



![ module ](https://github.com/gavinlyonsrepo/pic_16F18446_projects/blob/master/images/TM1638.jpg)


![ sch ](https://github.com/gavinlyonsrepo/pic_16F18446_projects/blob/master/images/TM1638_2.jpg)
