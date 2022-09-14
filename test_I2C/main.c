/*
 * test_I2C.c
 *
 * Created: 3.9.22 21:57:47
 * Author : Alexander
 */ 

#define F_CPU 16000000UL
//#define F_CPU 8000000UL
#define _BV(bit) (1u << (bit))



#include "twi_module.h"
#include "oled_display.h"
#include "oled_draw.h"
#include <avr/io.h>
#include <util/delay.h>
#include <util/twi.h>

int main(void)
{
	//DDRC = 0xff;

	DDRB |= _BV(5);
	PORTB &= ~_BV(5);
	
	int i = 0;
	
	twi_init();
	oled_init();
	
	oled_area(0x00u, 127u, 0x00u, 7u);

	for (i = 0; i < 1024; i++) {
		oled_data(0x55u);
	}
	
	_delay_ms(1000);
	clear_screen();
	for (i = 0; i < 181; i++) {
		clear_digit_field();
		form_number_from_digits(i);
		_delay_ms(500);
	}
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB |= _BV(5);
		_delay_ms(1000);
		PORTB &= ~_BV(5);
		_delay_ms(1000);
    }
}

