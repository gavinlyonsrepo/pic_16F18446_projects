
Overview
--------------------------------------------
* Name: FourteenSegDisplay
* Description: A  library to display data on a 14 segment LED module.
It requires 3 Daisy chained shift registers.
Library is also designed to work with common anode and common cathode module.
Library includes ASCII font and also supports Hexadecimal, Decimal point, strings.
Optimised low memory footprint. It also provides a function for manually setting
segments to any user defined pattern. 
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: PIC16F18446
* IDE:  MPLAB X v5.30
* Development board: Microchip Curiosity Board DM164137
* Copyright: (C) 2019 G Lyons This program is free software; 
you can redistribute it and/or modify it under the terms of the GNU General Public License 
as published by the Free Software Foundation, see license.md for more details

Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)
  * [Pictures](#pictures)


Features
----------------------
A fourteen-segment display (FSD) sometimes referred to as a Starburst, Alphanumeric or Union Jack display.
is a type of display based on 14 segments that can be turned on or off to produce letters and numerals.
It is an expansion of the more common seven-segment display, having an additional four diagonal and 
two vertical segments with the middle horizontal segment broken in half. 
A seven-segment display suffices for numerals and certain letters, 
but unambiguously rendering the ISO basic Latin alphabet requires more detail. 


This is a fork of the Arduino library I wrote. 
"FourteenSegDisplay" 14 segment (Model2 section).,
It can be found in Arduino librarymanger or at [link](https://github.com/gavinlyonsrepo/FourteenSegDisplay).

A PIC library to display data on a 14 segment LED module.
It requires three daisy chained shift registers.
Tested with 74HC595 shift registers.
The library was tested with a two digit LDD-F5406RI common cathode module.
Library is also designed to work with common anode. It also provides a function for manually setting
segments to any user defined pattern. It requires 3 Digital GPIO pins.

The LDD-F5406RI short-form datasheet is in the extra folder.

Use transistors to switch Digits on/off unless using high value of 
current limit resistors: For example 2.2K resistors will ((1.44mA) * 15= 21.6mA )will 
give total current per digit of 21.6mA with all segments on. Check your datasheet to see current limit
of GPIO for given microcontroller. 

When displaying a large number of digts 4-8,Run at a "fast" clock freq (8mhz plus ) 
to avoid flickering in the display and/or adjust shift delay parameter
in header file. In included config runs at 16Mhz HF internal.

**Connections**

This model supports a  maximum of 8 digits (eg for eight digits (D8D7D65D4D3D2D1). 
For purposes of my schematic and software D1
is the Least significant or right most Digit. 
The table below can be expanded by 6 more digits if more LED modules added
for digits 3-8. 

| PIC , SW | IC 1 | IC 2 | IC 3 | LDD-F5406RI | 
| ---  | --- | --- | --- | --- | 
| RC2 , SCLK | SCLK  | SCLK | SCLK |  |
| RC1 , RCLK | RCLK  | RCLK | RCLK |  |
| RC0 , SER | SER  |  |   |   |
|    | QH'  | SER  |  |   |
|    |   |  QH' | SER |   |
|   | QA |    |     | a 12 |
|   | QB |    |     | b 10 |
|   | QC |    |     | c 9 |
|   | QD |    |     | d 7 |
|   | QE |    |     | e 1 |
|   | QF |    |     | f 18 |
|   | QG |    |     | g1 13 |
|   | QH |    |     |  g2 6 |
|   |    | QA |     | h 17 |
|   |    | QB |     | j 15 |
|   |    | QC |     | k 14 |
|   |    | QD |     | l 2  |
|   |    | QE |     | m 4 |
|   |    | QF |     | n 5 |
|   |    | QG |     | DP 8 |
|   |    |    | QA  | Digit1 11 |
|   |    |    | QB  | Digit2 16 |
|   |    |    | QC-QH | extra digits as needed |

![ schematic ](https://github.com/gavinlyonsrepo/FourteenSegDisplay/blob/master/extra/image/14segModel2.png)


**Files table**

| Test file | Font file | Header file | C code file |
| --- | --- | --- |  --- | 
| main.c | 14SegDisplayFont.h | 14SegDisplay.h | 14SegDisplay.c |


**Library Functions**

The commented functions can be found in library header files *.h.
See these file for more details on functions.
The font is in a separate file *DisplayFont.h.

The main.c files contains a set of tests demonstrating library functions.

1. FourteenSegDisplay(uint8_t rclk, uint8_t sclk, uint8_t data, bool common, bool model2);
2. void displayASCII(uint8_t ascii, uint8_t digits);  // 7 and 14 seg only 
3. void displayASCIIwDot(uint8_t ascii, uint8_t digits ); //  7 and 14 seg only 
4. void displayHex(uint8_t hex, uint8_t digits ;
5. void displaySeg(uint16_t value, uint8_t digits);
6. void displayString(const char* str, uint8_t startPos); 

Pictures
------------------------------

16 , 14 and 7 displays segments layout.

![ layout ](https://github.com/gavinlyonsrepo/FourteenSegDisplay/blob/master/extra/image/14seg2.png)

14 segment font.

![ font ](https://github.com/gavinlyonsrepo/FourteenSegDisplay/blob/master/extra/image/14seg5.jpg)


