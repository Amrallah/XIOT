/*
 * Interrupt.c
 *
 *  Created on: Jun 27, 2018
 *      Author: Amro
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Macros.h"

void Interrupt_Init(){
	clearBit(SREG,7); //disable interrupts by clearing I-bit
	clearBit(DDRD,PD3); //initialize pin PD3 as an input
	setBit(PORTD,PD3); //internal pull-up resistance enable
	setBit(GICR,INT1); //enable INT1
	setBit(MCUCR,ISC10); //any logical change will cause an interrupt
	setBit(SREG,7); //enable interrupts by setting I-bit
}

