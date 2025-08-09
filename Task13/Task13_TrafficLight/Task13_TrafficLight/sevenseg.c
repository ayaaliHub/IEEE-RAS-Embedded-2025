#include "sevenseg.h"
#include "gpio.h"
#include <util/delay.h>

uint8_t segDigits[10] = {
	0x3F, 0x06, 0x5B, 0x4F, 0x66,
	0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

void SevenSeg_Init(void) {
	DDRC = 0xFF;
	DDRB |= (1 << PB0) | (1 << PB1);
}

void SevenSeg_DisplayNumber(uint8_t num) {
	uint8_t tens = num / 10;
	uint8_t ones = num % 10;

	PORTB |= (1 << PB0) | (1 << PB1);
	PORTC = segDigits[tens];
	PORTB &= ~(1 << PB0);
	_delay_ms(3);
	PORTB |= (1 << PB0);

	PORTC = segDigits[ones];
	PORTB &= ~(1 << PB1);
	_delay_ms(3);
	PORTB |= (1 << PB1);
}
