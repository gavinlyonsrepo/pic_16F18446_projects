/*!
	@file MQ7.h
    @brief MQ7 sensor library
	@notes based on arduino library by  Fergus Baker
*/

#ifndef MQ7SENSOR_H
#define MQ7SENSOR_H

#include "math.h" // for pow
#include "mcc_generated_files/mcc.h"
#include "HD44780_I2C_lcd.h"

/* CONFIGURATION OPTIONS  */

#define _CALIBRATION_SECONDS 15
	// uncomment to define hard-coded R0 value
					// may be desirable if no calibration delay wanted

/*
Calibration takes CALIBRATION_SECONDS + 1 seconds to let the device heat up! Else faulty readings.

Datasheet:
https://www.parallax.com/sites/default/files/downloads/605-00007-MQ-7-Datasheet.pdf

Datasheet has a graph for sensitivity characteristic, following the equation

	ppm(Rs/R0) = A0 * Rs/R0 ^ (A1)

with fitted parameters
	A0
	A1
and variable
	Rs	surface resistance at various gas concentrations
	R0	sensor resistance at 100ppm CO in clean air

NB: ppm == 100 defines Rs/R0 == 1.

The device reads analog pin, which can be translated into Rs/RL where RL is a resistance load.
In the datasheet, RL is said to be ~10 kOhm, thus we use 
	Rs = (Rs/RL) * RL

Calculated fitted parameters using inverse of ppm(Rs/R0) and plot in datasheet:
*/

#define _COEF_A0 100.0
#define _COEF_A1 -1.513

/* 
Datasheet provides typical load resistance RL to be ~10 kOhm
*/
#define _LOAD_RES 10.0

/*
Need to calibrate device by knowing MQ7_R0 -- in clean air, approx 10ppm,
 ratio is Rs / R0 = 5.0
*/
#define _CALIBRATION_CONSTANT 5.0

// Resolution of ADC in bits 
#define _MQ7_ADC_RESOLUTION 4096

float MQ7readPpm(void);
void MQ7calibrate(void);

float MQ7readRs(void);
float MQ7readRsRL(void);	// Rs / RL
float MQ7convertVoltage(int voltage);
    


#endif
