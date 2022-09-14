/*
 * oled_draw.c
 *
 * Created: 6.9.22 16:50:11
 *  Author: user
 */ 
#include "oled_draw.h"
#include "digits_24x72.h"
#include "oled_display.h"
#include "twi_module.h"
#include <stdint.h>
//uint8_t oled_buffer[OLED_PAGES_AMOUNT][OLED_SEGMENTS_AMOUNT] = 0x00u;

//void print_buffer(void) {
	//int i, j;
	//
	//oled_area(0x00u, 127u, 0x00u, 7u);
//
	//for (i = 0; i < OLED_PAGES_AMOUNT; i++) {
		//for (j = 0; j < OLED_SEGMENTS_AMOUNT; j++) {
			//oled_data(oled_buffer[i][j]);
		//}
	//}
//}
void print_digit(uint8_t seg_begin, uint8_t page_begin, uint8_t digit[]) {
	int i = 0;
	
	oled_area(seg_begin, seg_begin + 7u, page_begin, page_begin + 5u);
	for (i = 0; i < 8; i++)
		oled_data(particles_1pg[digit[0]][i]);
	for (i = 0; i < 8; i++)	
		oled_data(particles_1pg[digit[1]][i]);
	for (i = 0; i < 16; i++)
		oled_data(particles_2pg[digit[2]][i]);
	for (i = 0; i < 8; i++)
		oled_data(particles_1pg[digit[3]][i]);
	for (i = 0; i < 8; i++)
		oled_data(particles_1pg[digit[4]][i]);
	
	oled_area(seg_begin + 16u, seg_begin + 23u, page_begin, page_begin + 5u);
	for (i = 0; i < 8; i++)
		oled_data(particles_1pg[digit[5]][i]);
	for (i = 0; i < 8; i++)
		oled_data(particles_1pg[digit[6]][i]);
	for (i = 0; i < 16; i++)
		oled_data(particles_2pg[digit[7]][i]);
	for (i = 0; i < 8; i++)
		oled_data(particles_1pg[digit[8]][i]);
	for (i = 0; i < 8; i++)
		oled_data(particles_1pg[digit[9]][i]);
	
	oled_area(seg_begin + 8, seg_begin + 15, page_begin, page_begin);
	for (i = 0; i < 8; i++)
		oled_data(particles_1pg[digit[10]][i]);
	oled_area(seg_begin + 8, seg_begin + 15, page_begin + 2, page_begin + 3);
	for (i = 0; i < 16; i++)
		oled_data(particles_2pg[digit[11]][i]);
	oled_area(seg_begin + 8, seg_begin + 15, page_begin + 5, page_begin + 5);
	for (i = 0; i < 8; i++)
		oled_data(particles_1pg[digit[12]][i]);
}
void form_number_from_digits(uint8_t num) {
	int i;
	int offset[3];
	int num_size = 0; //how much digits
	uint8_t tmp_n = num;
	uint8_t digits[3];
	
	if (num > 180)
		return ;
	
	digits[2] = tmp_n / 100;
	tmp_n %= 100;
	digits[1] = tmp_n / 10;
	tmp_n %= 10;
	digits[0] = tmp_n;
	
	if (digits[2] == 0) {
		if (digits[1] == 0) {
			num_size = 1;
			offset[0] = -12;
		}
		else {
			num_size = 2;
			offset[0] = 4;
			offset[1] = -28;
		}
	}
	else {
		num_size = 3;
		offset[0] = 20; 
		offset[1] = -12; 
		offset[2] = -44;
	}
	
	for (i = 0; i < num_size; i++) {
		switch(digits[i]) {
			case 0:  print_digit(128/2 + offset[i], 1u, digit_0); break;
			case 1:  print_digit(128/2 + offset[i], 1u, digit_1); break;
			case 2:  print_digit(128/2 + offset[i], 1u, digit_2); break;
			case 3:  print_digit(128/2 + offset[i], 1u, digit_3); break;
			case 4:  print_digit(128/2 + offset[i], 1u, digit_4); break;
			case 5:  print_digit(128/2 + offset[i], 1u, digit_5); break;
			case 6:  print_digit(128/2 + offset[i], 1u, digit_6); break;
			case 7:  print_digit(128/2 + offset[i], 1u, digit_7); break;
			case 8:  print_digit(128/2 + offset[i], 1u, digit_8); break;
			case 9:  print_digit(128/2 + offset[i], 1u, digit_9); break;
		}
	}
}	
//void print_number(uint8_t num) {
	//uint8_t buffer[OLED_PAGES_AMOUNT][OLED_SEGMENTS_AMOUNT] = 0x00u;
	//
	//form_buffer_from_digits(num);
	//
	//print_buffer();
//}
//
void clear_digit_field(void) {
	int i;
	oled_area(20u, 107u, 1u, 6u);
	
	oled_start_wtxn();
	twi_write(0x40u);
	for (i = 0; i < 528; i++) {
		twi_write(0x00u);
	}
	oled_stop_txn();
}
void clear_screen(void) {
	int i;
	
	oled_area(0x00u, 127u, 0x00u, 7u);

	for (i = 0; i < 1024; i++) {
		oled_data(0x00u);
	}
}