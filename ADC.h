/*
 * ADC.h
 *
 *  Created on: Jun 28, 2018
 *      Author: Amro
 */

#ifndef ADC_H_
#define ADC_H_

int ADC0reading;
int ADC1reading;
int temperature;
char temperatureString [18];
void ADC_Init();
int ADC_readChannel(unsigned int channelNumber);

#endif /* ADC_H_ */
