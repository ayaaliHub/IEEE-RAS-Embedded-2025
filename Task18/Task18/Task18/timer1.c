/*
 * timer1.c
 *
 * Created: 9/7/2025 10:37:04 PM
 *  Author: ayaal
 */ 

#include "timer1.h"
#include "register.h"

void TIMER1_initICU(void) {
	// Normal mode, Prescaler = 8
	TCCR1A = 0;
	TCCR1B = (1<<ICES1) | (1<<CS11); // Rising edge capture, clk/8
	TCNT1 = 0;
}

uint16_t TIMER1_getPulse(void) {
	uint16_t t1, t2;
	TIFR |= (1<<ICF1);              // Clear flag
	while(!(TIFR & (1<<ICF1)));     // Wait rising
	t1 = ICR1;
	
	TCCR1B &= ~(1<<ICES1);          // Switch to falling
	TIFR |= (1<<ICF1);
	while(!(TIFR & (1<<ICF1)));     // Wait falling
	t2 = ICR1;

	TCCR1B |= (1<<ICES1);           // Reset to rising
	return (t2 - t1);               // Pulse width in ticks
}
