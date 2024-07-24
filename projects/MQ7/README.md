
# MQ7

## Overview

* Description: Display the PPM data from a  MQ7 carbon monoxide(CO) sensor and display it on a 
to an LCD display HD44780 via the I2C bus and a PCF8574 Interface "backpack" board
using a PIC16F18446.

## Features

We use a power MOSFET to PWM pulse the Sensor on/off at different voltages as per heating cycle described in datasheet. 

1. 60 seconds at 5 volt , Status LED OFF
2. 90 seconds at 1.4V, Status LED ON
3.  read sensor

An optional Calibration sequence is carried out at start-up , to skip this hold the push button down on power up. This calibration calculates R0. The R0 is calculated by assuming clean air (approx 10 ppm of carbon monoxide) -- it is therefore best to perform this calibration outside. If Calibration is skipped an R0 of 8.0 is assumed. 

 ![Mq](https://github.com/gavinlyonsrepo/MQ7Bluetooth/blob/main/doc/images/mq7.jpg)

**HD44780-based character LCD**

The HD44780  LCD is controlled via the 2-pin I2C bus.

In this example code, a 4-pin PCF8574 Interface "backpack" board is attached to LCD. It is controlled via the two pin I2C bus. 

1. RB4 = SDA
2. RB6 = SCLK 

The LCD code are in a separate library files. The Library supports both 16x02 and 20x04 LCD's.
The Data is sent in 4-bit mode. The upper nibble holds the data and lower nibble of byte manipulates the control bits of LCD. 

![PCF8574 & LCD ](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/LCDPCF.jpg)

## Pin Assignments

![Pic 1](https://github.com/gavinlyonsrepo/pic_16F18446_projects/blob/master/images/mq7.jpg)

## Schematic 

![Pic 2](https://github.com/gavinlyonsrepo/pic_16F18446_projects/blob/master/images/mq7sch.jpg)


## See Also

See also for more details 
* [MQ7 library](https://github.com/fjebaker/MQ7) 
* [Unified sensor library](https://github.com/miguel5612/MQSensorsLib)
* [Datasheet](https://www.sparkfun.com/datasheets/Sensors/Biometric/MQ-7.pdf)
* [AReResearch](http://www.areresearch.net/2017/03/detect-co-with-mq-7-sensor-module.html)
