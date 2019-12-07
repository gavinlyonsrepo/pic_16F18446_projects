
Overview
--------------------------------------------

* Name: Bluetooth example code.
* Description: A example program for a PIC to communicate with a PC/Phone via bluetooth Hm-10 module and the PIC's UART. 
* Author: Gavin Lyons.

Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)


Features
----------------------

Send ADC value of potentiometer on RC0 to the serial port every 2 seconds,  where it will be transmitted
by bluetooth module to PC/PHONE.
In the the event of a transmission event from the bluetooth module to the PIC( a receive event from PIC standpoint)
A receive interrupt is generated in the PIC which runs a custom routine in the UART code file.
which handles the event:

1. if H/h was sent, LED at RC2 is turned on and "LED on" send to PC/PHONE.
2. if L/l was sent, LED at RC2 is turned off and "LED off" send to PC/PHONE. 
3. Anything else FAIL is sent by PIC to PC/Phone.

Run the PIC at 3.3V or drop the voltage level down from 5v to 3.3V as blue tooth module level on transmission lines is 3.3V.

*Connections*

1. PIC RX RB5 << HM-10 TX.
2. PIC TX RB7 >> HM-10 RX.
3. Potentiometer on RC0.
4. LED on RC2.

Bluetooth module used: Bluetooth Module HM-10 BLE 4.0 CC2540 TI CC2541 Module For Arduino

![Pic 1](https://github.com/gavinlyonsrepo/pic_16F18446_projects/blob/master/images/bluetooth.jpg)

![Pic 2](https://github.com/gavinlyonsrepo/pic_16F18446_projects/blob/master/images/bluetooth1.jpg)
