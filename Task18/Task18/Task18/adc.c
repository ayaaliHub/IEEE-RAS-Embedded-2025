/*
 * adc.c
 *
 * Created: 9/7/2025 9:14:09 PM
 *  Author: ayaal
 */ 

#include "adc.h"
#include "register.h"

void ADC_Init(void) {
	// Reference = AVCC, Right Adjust, channel 0 by default
	ADMUX = (1 << REFS0);
	// Enable ADC, Prescaler = 128
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t ADC_Read(uint8_t channel) {
	channel &= 0x07; // 0-7 only
	ADMUX = (ADMUX & 0xF8) | channel;
	ADCSRA |= (1 << ADSC); // Start conversion
	while (ADCSRA & (1 << ADSC)); // Wait
	return ADC; // Return ADC value (10-bit)
}

