/*
 * Macros.h
 *
 *  Created on: Jun 29, 2018
 *      Author: Amro
 */

#ifndef MACROS_H_
#define MACROS_H_

#define setBit(REG,BIT) (REG |= (1<<BIT))
#define clearBit(REG,BIT) (REG &= ~(1<<BIT))
#define toggleBit(REG,BIT) (REG ^= (1<<BIT))
#define bit_Is_Clear(REG,BIT) (!(REG & (1<<BIT)))
#define bit_Is_Set(REG,BIT) (REG & (1<<BIT))

#endif /* MACROS_H_ */
