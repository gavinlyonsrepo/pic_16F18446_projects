

Overview
--------------------------------------------
* Name: TM1638
* Description: A library to display data on a 8-digit TM1638 seven segment module
This module is the (KEY & LED) variant which has 8 LED's and 8 Push  buttons.
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F18446
* IDE:  MPLAB X v5.05
* Foundation services library: 0.1.31 (I2C)
* MCC version: 3.75
* Development board: Microchip Curiosity Board DM164137, PIC16F18446

Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)

Features
----------------------


**TM1638 Module 8 Push buttons 8 LEDS (LED & KEY)**

These Tm1638 modules are commonly available. 
I have seen two variants, this library is for the one marked LED & KEY.
It will not work with the push buttons only module without some modification.

1. LED & KEY , 8 LEDS and 8 Push Buttons
2. KEY 16  Push buttons

Two 4 digit 3461AS (common anode , RED ) are used in this module
giving a total of 8 digits. A TM1638 controller chip drives the unit.
The unit is marked (LED & KEY) 
The library is contained in two files.

Connections to PIC: 

1. RC0 = STB
2. RC1 = CLK
3. RC2 = DIO


![ module ](https://github.com/gavinlyonsrepo/pic_16F18446_projects/blob/master/images/TM1638.jpg)


![ sch ](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/TM1638_2.jpg)

Schematic
------------------------

![schematic](https://github.com/gavinlyonsrepo/pic_16F18446_projects/blob/master/images/LM35.png)
