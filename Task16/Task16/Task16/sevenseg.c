/*
 * sevenseg.c
 *
 * Created: 9/7/2025 4:59:50 PM
 *  Author: ayaal
 */ 

#include "sevenseg.h"
#include "stdtypes.h"

static const uint8_t seg_digits[10] = {
	0x3F, // 0
	0x06, // 1
	0x5B, // 2
	0x4F, // 3
	0x66, // 4
	0x6D, // 5
	0x7D, // 6
	0x07, // 7
	0x7F, // 8
	0x6F  // 9
};

void sevenseg_init(void) {
	SEG_DDR = 0xFF;  
	SEG_PORT = 0x00; 
}

void sevenseg_show(uint8_t digit) {
	if (digit <= 9) {
		SEG_PORT = seg_digits[digit];
	}
}
