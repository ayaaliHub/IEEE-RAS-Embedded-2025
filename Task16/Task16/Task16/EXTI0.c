/*
 * EXTI0.c
 *
 * Created: 9/7/2025 7:26:56 PM
 *  Author: ayaal
 */ 
#include "EXTI0.h"

static void (*EXTI0_callback)(void) = 0;

void EXTI0_init(EXTI0_Sense_t sense) {
	switch(sense) {
		case LOW_LEVEL:
		CLR_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);
		break;
		case ANY_LOGICAL_CHANGE:
		SET_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);
		break;
		case FALLING_EDGE:
		CLR_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);
		break;
		case RISING_EDGE:
		SET_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);
		break;
	}
}

void EXTI0_enable(void) {
	SET_BIT(GICR, INT0);
}

void EXTI0_disable(void) {
	CLR_BIT(GICR, INT0);
}

void EXTI0_setCallback(void (*callback)(void)) {
	EXTI0_callback = callback;
}

ISR(INT0_vect) {
	if (EXTI0_callback) {
		EXTI0_callback();
	}
}
