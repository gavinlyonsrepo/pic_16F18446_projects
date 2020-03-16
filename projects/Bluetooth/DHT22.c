/*
* Project Name: OLED_DHT22
* File: DHT22.c
* Description: src file to read sensor DHT22
* Author: Gavin Lyons.
* Complier: xc8 v2.10 compiler
* PIC: 
* IDE:  MPLAB X v5.30
* Created: Feb 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/
*/

#include "mcc_generated_files/mcc.h"
#include "DHT22.h" 

void DHT22_init(void){
    TRIS_DHT = 0;      
    LAT_DHT = 1;       
}

uint8_t DHT22_read(int16_t *dht_temperature, int16_t *dht_humdity){

    uint8_t Data[5];
	uint8_t i,j=0;
     
    LAT_DHT = 0;        
    __delay_ms(18);  
    
    LAT_DHT = 1;       
    __delay_us(40);
    
    TRIS_DHT = 1;       
    
    if(PORT_DHT){
        TRIS_DHT = 0;      
        PORT_DHT = 1;       
        return 3;
    }    
    __delay_us(80);
    
    if(!PORT_DHT){
        TRIS_DHT = 0;       
        PORT_DHT = 1;       
        return 3;
    }
    __delay_us(80);
    
     for (j=0; j<5; j++)
	{
	uint8_t result=0;
		for (i=0; i<8; i++)
		{
			while (!PORT_DHT);
				__delay_us(35);

			if (PORT_DHT)
				result |= (1<<(7-i));
					
			while(PORT_DHT);
		}
		Data[j] = result;
	}
    
    TRIS_DHT = 0;       
    PORT_DHT = 1;       
    
    //checksum check
    if ((uint8_t) (Data[0] + Data[1] + Data[2] +Data[3]) == Data[4])		
	{
                
		uint16_t rawhumidity = Data[0]<<8 | Data[1];
		uint16_t rawtemperature = Data[2] <<8 | Data[3];
        
		if (rawtemperature & 0x8000){
			*dht_temperature = rawtemperature & 0x7fff * -1;
		}else{
			*dht_temperature =rawtemperature;
		}

		*dht_humdity = rawhumidity;
        return 1;  	// All good
	}else
    {
        return 2; //check sum bad 
    }
    return 3; //no response
}
