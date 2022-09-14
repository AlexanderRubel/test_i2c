/*
 * oled_display.h
 *
 * Created: 4.9.22 11:09:26
 *  Author: user
 */ 


#ifndef OLED_DISPLAY_H_
#define OLED_DISPLAY_H_

#include <stdint.h>

#define OLED_ADDRESS_W 0x3Cu
#define OLED_ADDRESS_R 0x3Du

void oled_init(void);
void oled_data(uint8_t data);
void oled_cmd(uint8_t cmd);
void oled_area(uint8_t seg_begin, uint8_t seg_end, uint8_t page_begin, uint8_t page_end);
void oled_start_wtxn(void);
void oled_stop_txn(void);


#endif /* OLED_DISPLAY_H_ */