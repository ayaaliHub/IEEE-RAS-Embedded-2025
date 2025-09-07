/*
 * timer0.c
 *
 * Created: 9/7/2025 10:34:41 PM
 *  Author: ayaal
 */ 

#include "timer0.h"
#include "register.h"

void TIMER0_initPWM(void) {
	// Fast PWM, Non-inverting, Prescaler = 64
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01) | (1<<CS00);
	DDRB |= (1<<PB3); // OC0 as output
}

void TIMER0_setDuty(uint8_t duty) {
	OCR0 = duty; // 0-255
}
