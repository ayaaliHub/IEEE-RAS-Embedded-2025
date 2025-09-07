/*
 * EXTI1_REGISTER.h
 *
 * Created: 9/7/2025 7:25:16 PM
 *  Author: ayaal
 */ 


#ifndef EXTI1_REGISTER_H_
#define EXTI1_REGISTER_H_

#include "register.h"

/* MCU Control Register */
#define MCUCR   (*(volatile uint8_t*)0x55)
/* MCU Control and Status Register */
#define MCUCSR  (*(volatile uint8_t*)0x54)
/* General Interrupt Control Register */
#define GICR    (*(volatile uint8_t*)0x5B)
/* General Interrupt Flag Register */
#define GIFR    (*(volatile uint8_t*)0x5A)

/* Bit positions */
#define ISC10   2
#define ISC11   3
#define INT1    7

#endif 
