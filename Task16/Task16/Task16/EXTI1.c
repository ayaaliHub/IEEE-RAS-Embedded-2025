/*
 * EXTI1.c
 *
 * Created: 9/7/2025 7:28:31 PM
 *  Author: ayaal
 */ 
#include "EXTI1.h"

static void (*EXTI1_callback)(void) = 0;

void EXTI1_init(EXTI1_Sense_t sense) {
	switch(sense) {
		case LOW_LEVEL1:
		CLR_BIT(MCUCR, ISC10);
		CLR_BIT(MCUCR, ISC11);
		break;
		case ANY_LOGICAL_CHANGE1:
		SET_BIT(MCUCR, ISC10);
		CLR_BIT(MCUCR, ISC11);
		break;
		case FALLING_EDGE1:
		CLR_BIT(MCUCR, ISC10);
		SET_BIT(MCUCR, ISC11);
		break;
		case RISING_EDGE1:
		SET_BIT(MCUCR, ISC10);
		SET_BIT(MCUCR, ISC11);
		break;
	}
}

void EXTI1_enable(void) {
	SET_BIT(GICR, INT1);
}

void EXTI1_disable(void) {
	CLR_BIT(GICR, INT1);
}

void EXTI1_setCallback(void (*callback)(void)) {
	EXTI1_callback = callback;
}

ISR(INT1_vect) {
	if (EXTI1_callback) {
		EXTI1_callback();
	}
}
