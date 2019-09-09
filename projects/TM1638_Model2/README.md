Overview
--------------------------------------------
* Name: TM1638plus
* Description: An PIC library to display data on a 8-digit TM1638 seven segment module
This library supports (16 KEY)(QFY) variant which has 16 pushbuttons.
* Author: Gavin Lyons.
* Development platform: PIC 16F18446


Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)

Features
----------------------


These TM1638 modules are commonly available. 
Connections to PIC: 

1. GPIO = STB = Strobe
2. GPIO  = CLK  = Clock
3. GPIO = DIO = Data input / output  (Configure as open drain)

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