/*
 * oled_draw.h
 *
 * Created: 6.9.22 16:49:55
 *  Author: user
 */ 


#ifndef OLED_DRAW_H_
#define OLED_DRAW_H_

#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_PAGES_AMOUNT 8
#define OLED_SEGMENTS_AMOUNT 128
#include <stdint.h>
//void print_buffer(void);
//void print_number(uint8_t num);
void clear_screen(void);
void clear_digit_field(void);
void print_digit(uint8_t seg_begin, uint8_t page_begin, uint8_t digit[]);
void form_number_from_digits(uint8_t num);

#endif /* OLED_DRAW_H_ */