/*
 * main.c
 *
 *  Created on: Jun 27, 2018
 *      Author: Amro
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Macros.h"
#include "Interrupt.h"
#include "UART.h"
#include "ADC.h"
#include "Timer.h"

unsigned char timerOverflows=0;

ISR(INT1_vect){
	toggleBit(PORTA,PA7);
	if(bit_Is_Set(PORTA,PA7)){
		UART_sendString("Pressed,LED ON\r");
	}
	else{
		UART_sendString("Pressed,LED OFF\r");
	}
}

ISR(TIMER0_OVF_vect)
{
	timerOverflows++;
	if(timerOverflows == requiredOverflowsFor3Seconds)
	{
		UART_sendString(temperatureString);
		timerOverflows = 0; //clear the overflows counter again to count a new 3 seconds
	}
}


int main(void){
	setBit(DDRA,PA7); //PA7 is an output
	Interrupt_Init();
	UART_Init();
	ADC_Init();
	Timer0_normalMode_Init();
	while(1){
		ADC_tempAsString(0,1);
	}
	return 0;
}

