/*
 * sevenseg.h
 *
 * Created: 9/7/2025 4:38:19 PM
 *  Author: ayaal
 */ 


#ifndef SEVENSEG_H_
#define SEVENSEG_H_
#include "stdtypes.h"

#define SEG_PORT PORTC
#define SEG_DDR  DDRC

void sevenseg_init(void);
void sevenseg_show(uint8_t digit);

#endif 

