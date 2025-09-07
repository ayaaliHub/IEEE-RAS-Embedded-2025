/*
 * EXTI1.h
 *
 * Created: 9/7/2025 7:27:32 PM
 *  Author: ayaal
 */ 


#ifndef EXTI1_H_
#define EXTI1_H_

#include "EXTI1_REGISTER.h"
#include "stdtypes.h"

typedef enum {
	LOW_LEVEL1,
	ANY_LOGICAL_CHANGE1,
	FALLING_EDGE1,
	RISING_EDGE1
} EXTI1_Sense_t;

void EXTI1_init(EXTI1_Sense_t sense);
void EXTI1_enable(void);
void EXTI1_disable(void);
void EXTI1_setCallback(void (*callback)(void));

#endif 
