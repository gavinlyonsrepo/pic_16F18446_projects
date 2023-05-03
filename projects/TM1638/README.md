# TM1638

Table of contents
---------------------------

  * [Overview](#overview)
  * [Hardware](#hardware)
  * [Software](#software)
  * [Notes](#notes)

Overview
--------------------------------------------
* Name: TM1638
* Description: 

A library to display data on 8-digit TM1638 seven segment LED module's.

* Author: Gavin Lyons.
* Complier: xc8 v2.40 compiler
* PIC: PIC16F18446
* IDE:  MPLAB X v6.00

Hardware
----------------------

This library supports three variants of the TM1638, which for purposes of this documentation, 
will be named Model 1 ,Model 2 and Model 3.  Pictured left to right. 

![ module pics ](https://github.com/gavinlyonsrepo/TM1638plus/blob/master/extra/images/tm16383.jpg)

| Model Name | PCB Labels | LEDs | Push buttons | 
| ------ | ------ |  ------ | ------ |
| Model 1 | TM1638 LED & KEY | 8 red only | 8 |
| Model 2 | TM1638 KEYS, QYF  | 0 | 16 |
| Model 3 | TM1638 V1.3 or LKM1638  | 8 bi color,  red or green  | 8 |

Connections to PIC: 

1. RC0 = STB
2. RC1 = CLK
3. RC2 = DIO


Software
--------------------------------------------------

In order to switch between model 1 & model 3 in the main.c test file 
change the boolean LKM1638 at start.

| Model No | file Name | flag LKM1638 | 
| ------ | ------ | ------ | 
| One | main.c | false |
| Two | main_Model2.c  | n/a | 
| Three | main.c | true |

Note 
--------------------------

This library is a C fork  of the [Arduino C++ library](https://github.com/gavinlyonsrepo/TM1638plus) 
"TM1638plus" which is also written by Author and can be found in Arduino library manger. 

There you will find extensive documentation.
