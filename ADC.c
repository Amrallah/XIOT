/*
 * ADC.c
 *
 *  Created on: Jun 28, 2018
 *      Author: Amro
 */

#include <avr/io.h>
#include <stdio.h>
#include "Macros.h"
#include "ADC.h"

void ADC_Init(){
	ADMUX=0; //reference voltage from AREF, ADC result right adjusted,ADC0 on
	//enable ADC,Division factor 8 for ADC prescaler:
	ADCSRA = (1<<ADEN);
	setBit(ADCSRA,ADPS1);
	setBit(ADCSRA,ADPS0);

}

int ADC_readChannel(unsigned int channelNumber){
	channelNumber &= 0x07; //channel number must be between 0 and 7
	ADMUX &= 0xE0; //clear the previous channel before setting the required channel
	ADMUX |= channelNumber;
	setBit(ADCSRA,ADSC); //start conversion
	while(bit_Is_Clear(ADCSRA,ADIF)); //wait for conversion to be complete
	setBit(ADCSRA,ADIF); //clear conversion completion flag
	return ADC;
}

void ADC_tempAsString(unsigned int channelNumber1, unsigned int channelNumber2){
	channelNumber1 &= 0x07;
	channelNumber2 &= 0x07;
	ADC0reading = ADC_readChannel(channelNumber1);
	ADC1reading = ADC_readChannel(channelNumber2);
	temperature = (ADC0reading-ADC1reading)/2;
	//to adjust some temperature offsets caused by error ratio of the LM35 sensor:
	if (temperature>=26&&temperature<=59){
		temperature--;
	}
	else if(temperature>=60&&temperature<=97){
		temperature -=2;
	}
	else if(temperature>=98&&temperature<=134){
		temperature -=3;
	}
	else if(temperature>=135){
		temperature-=4;
	}
	sprintf (temperatureString, "Temperature = %d\r",temperature); //convert temperature integer value to string
}
