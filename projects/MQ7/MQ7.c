/*!
	@file MQ7.c
    @brief MQ7 sensor library
	@notes based on arduino library by  Fergus Baker
*/

#include "MQ7.h"

float picVCC = 5.0;
float  MQ7_R0 = 8.0;

float MQ7readPpm() {
	return (float) _COEF_A0 * pow(
		MQ7readRs() / MQ7_R0,
		_COEF_A1
	);
}

void MQ7calibrate() {
     char dataStr[16];
	for (int i = 0; i <= _CALIBRATION_SECONDS; i++) {
		__delay_ms(1000);
		 MQ7_R0 = (float)(MQ7readRs() / _CALIBRATION_CONSTANT);
	}
    
    PCF8574_LCDGOTO(LCDLineNumberOne, 0);
    sprintf(dataStr, "ADC =   %u", ADCC_GetSingleConversion(SENSOR_ANC0));
    PCF8574_LCDSendString(dataStr);
    PCF8574_LCDGOTO(LCDLineNumberTwo, 0);
    sprintf(dataStr, "R0= %.4f", MQ7_R0);
    PCF8574_LCDSendString(dataStr);
    __delay_ms(3000);
    
}

float MQ7readRs() {
	return (float)_LOAD_RES * MQ7readRsRL();
}

float MQ7readRsRL() {
	float voltage = MQ7convertVoltage(
        (int)ADCC_GetSingleConversion(SENSOR_ANC0)
	);

	return (picVCC - voltage) / voltage;
}

float MQ7convertVoltage(int voltage) {
	return (float) voltage * (picVCC / _MQ7_ADC_RESOLUTION);
}


