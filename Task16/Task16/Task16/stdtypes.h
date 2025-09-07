/*
 * stdtypes.h
 *
 * Created: 9/7/2025 4:45:36 PM
 *  Author: ayaal
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>

#define SET_BIT(REG,BIT)   ((REG) |= (1U << (BIT)))
#define CLR_BIT(REG,BIT)   ((REG) &= ~(1U << (BIT)))
#define TOG_BIT(REG,BIT)   ((REG) ^= (1U << (BIT)))
#define READ_BIT(REG,BIT)  (((REG) >> (BIT)) & 1U)




#endif 