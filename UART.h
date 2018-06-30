/*
 * UART.h
 *
 *  Created on: Jun 27, 2018
 *      Author: Amro
 */

#ifndef UART_H_
#define UART_H_

#define F_CPU 1000000UL
#define baudRate 9600
#define baudPrescaler ((F_CPU/(8UL*baudRate))-1)

void UART_Init();
void UART_sendByte(unsigned char character);
void UART_sendString(unsigned char* str);

#endif /* UART_H_ */
