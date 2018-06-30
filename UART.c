/*
 * UART.c
 *
 *  Created on: Jun 27, 2018
 *      Author: Amro
 */


#include <avr/io.h>
#include "UART.h"
#include "Macros.h"

void UART_Init(){
		setBit(UCSRA,U2X); //asynchronous double speed mode(double transfer rate)
		setBit(UCSRB,TXEN); //enable transmit
		//8-bit data mode:
		setBit(UCSRC,URSEL);
		setBit(UCSRC,UCSZ0);
		setBit(UCSRC,UCSZ1);

		UBRRH = (baudPrescaler>>8);
		UBRRL= baudPrescaler;
}

void UART_sendByte(unsigned char character){
	while(bit_Is_Clear(UCSRA,UDRE)); //wait until buffer is empty
	UDR = character;
}

void UART_sendString(unsigned char* str){
	while(*str != '\0'){
		UART_sendByte(*str);
		str++;
	}

}
