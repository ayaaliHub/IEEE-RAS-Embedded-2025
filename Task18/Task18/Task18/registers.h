/*
 * registers.h
 *
 * Created: 9/7/2025 4:36:43 PM
 *  Author: ayaal
 */ 


#ifndef INC_REGISTERS_H_
#define INC_REGISTERS_H_

//for port A
#define PORTA *((volatile uint8_t*)(0x3B))
#define DDRA *((volatile uint8_t*)(0x3A))
#define PINA *((volatile uint8_t*)(0x39))
//for port B
#define PORTB *((volatile uint8_t*)(0x38))
#define DDRB *((volatile uint8_t*)(0x37))
#define PINB *((volatile uint8_t*)(0x36))
//for port C
#define PORTC *((volatile uint8_t*)(0x35))
#define DDRC *((volatile uint8_t*)(0x34))
#define PINC *((volatile uint8_t*)(0x33))
//for port D
#define PORTD *((volatile uint8_t*)(0x32))
#define DDRD *((volatile uint8_t*)(0x31))
#define PIND *((volatile uint8_t*)(0x30))

// TIMER0 Registers
#define TCCR0   (*(volatile uint8_t*)0x53)
#define TCNT0   (*(volatile uint8_t*)0x52)
#define TIFR    (*(volatile uint8_t*)0x58)

// TCCR0 bits
#define CS00    0
#define CS01    1
#define CS02    2

// TIFR bits
#define TOV0    0


#endif /* INC_REGISTERS_H_ */