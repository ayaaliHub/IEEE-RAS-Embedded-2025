/*
 * lcd.c
 *
 * Created: 9/7/2025 5:00:46 PM
 *  Author: ayaal
 */ 

#include "lcd.h"
#include "stdtypes.h"

#define LCD_DATA_DDR   DDRB
#define LCD_DATA_PORT  PORTB

#define DATA_SHIFT 2 

static void lcd_enable_pulse(void) {
	gpio_write(&LCD_PORT, EN, HIGH);
	_delay_us(1);
	gpio_write(&LCD_PORT, EN, LOW);
	_delay_us(100);
}

static void lcd_send_nibble(uint8_t data) {
	for (uint8_t i = 0; i < 4; i++) {
		if (data & (1 << i)) SET_BIT(LCD_DATA_PORT, DATA_SHIFT + i);
		else CLR_BIT(LCD_DATA_PORT, DATA_SHIFT + i);
	}
	lcd_enable_pulse();
}

static void lcd_send_command(uint8_t cmd) {
	gpio_write(&LCD_PORT, RS, LOW);
	lcd_send_nibble(cmd >> 4);
	lcd_send_nibble(cmd & 0x0F);
	_delay_ms(2);
}

static void lcd_send_data(uint8_t data) {
	gpio_write(&LCD_PORT, RS, HIGH);
	lcd_send_nibble(data >> 4);
	lcd_send_nibble(data & 0x0F);
	_delay_ms(2);
}

void LCD_Init(void) {
	LCD_DDR |= (1 << RS) | (1 << EN);
	LCD_DATA_DDR |= 0xFC; // D2..D7

	_delay_ms(20);

	lcd_send_command(0x28); // 4-bit, 2 line
	lcd_send_command(0x0C); // Display ON
	lcd_send_command(0x06); // Entry mode
	lcd_send_command(0x01); // Clear
}

void LCD_Clear(void) {
	lcd_send_command(0x01);
	_delay_ms(2);
}

void LCD_WriteChar(char c) {
	lcd_send_data(c);
}

void LCD_WriteString(const char* str) {
	while (*str) {
		LCD_WriteChar(*str++);
	}
}

void LCD_WriteInteger(int num) {
	char buffer[10];
	itoa(num, buffer, 10);
	LCD_WriteString(buffer);
}

void LCD_GoTo(uint8_t row, uint8_t col) {
	uint8_t address = (row == 0 ? 0x00 : 0x40) + col;
	lcd_send_command(0x80 | address);
}

void LCD_CreateCustomChar(uint8_t location, uint8_t *pattern) {
	location &= 0x7; // 0-7 only
	lcd_send_command(0x40 | (location << 3));
	for (uint8_t i = 0; i < 8; i++) {
		LCD_WriteChar(pattern[i]);
	}
}
