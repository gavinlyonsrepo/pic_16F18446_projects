
Overview
--------------------------------------------

* Name: Bluetooth.
* Description: A program for a PIC to communicate with a PC/Phone via bluetooth Hm-10 module and the PIC's UART. 
the sensor data from a DHT22 temperature and humidity sensor is sent over link.
* Author: Gavin Lyons.

Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)


Features
----------------------

The DHT22 sensor data of temperature and humidity is read every 2 seconds,  and is then transmitted
by a bluetooth module to PC/PHONE using the EUSART on PIC.

In the the event of a transmission event from the bluetooth module to the PIC( a receive event from PIC standpoint)
A receive interrupt is generated in the PIC which runs a custom routine in the EUSART code file.
which handles the event:

1. if H/h was sent, STATUS LED is turned on and "LED on" send to PC/PHONE.
2. if L/l was sent, STATUS LED is turned off and "LED off" send to PC/PHONE. 
3. Anything else FAIL is sent by PIC to PC/Phone.

NOTE:
The voltage level of the blue tooth module on communication lines is 3.3V, running 5V on these will damage it. 
So it must be level shifted from 5v to 3.3v if running PIC at 5V.

*Connections*

1. PIC RX RB5 << HM-10 TX.
2. PIC TX RB7 >> HM-10 RX.
3. Sensor line on RC2.
4. STATUS LED on RC3.

Bluetooth module used: Bluetooth Module HM-10 BLE 4.0 CC2540.

![Pic 1](https://github.com/gavinlyonsrepo/pic_16F18446_projects/blob/master/images/bluetooth.jpg)


