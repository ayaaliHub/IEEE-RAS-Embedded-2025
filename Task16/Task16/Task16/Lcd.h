/*
 * Lcd.h
 *
 * Created: 9/7/2025 4:39:25 PM
 *  Author: ayaal
 */ 


#include"../include/gpio.h"
#include "stdtypes.h"

void LCD_Init(void);
void LCD_Clear(void);
void LCD_WriteChar(char c);
void LCD_WriteString(const char* str);
void LCD_WriteInteger(int num);
void LCD_CreateCustomChar(uint8_t location, uint8_t *pattern);
void LCD_GoTo(uint8_t row, uint8_t col);

#define LCD_PORT PORTB
#define LCD_DDR  DDRB

#define EN PIN0
#define RS PIN1


#endif 