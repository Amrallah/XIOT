/*
 * Timer.c
 *
 *  Created on: Jun 29, 2018
 *      Author: Amro
 */

#include <avr/io.h>
#include "Macros.h"

void Timer0_normalMode_Init(){
	//non PWM mode, 1024 prescaler:
	TCCR0 = (1<<FOC0);
	setBit(TCCR0,CS02);
	setBit(TCCR0,CS00);

	TCNT0 = 0; //initial value 0
	setBit(TIMSK,TOIE0); //enable overflow interrupt
	setBit(SREG,7); //enable interrupts by setting I-bit
}
