/*
 * oled_display.c
 *
 * Created: 4.9.22 11:08:58
 *  Author: user
 */ 
#include "twi_module.h"
#include "oled_display.h"
#include <stdint.h>

void oled_cmd(uint8_t cmd) {
	oled_start_wtxn();
	twi_write(0x00u);
	twi_write(cmd);
	oled_stop_txn();
}
void oled_data(uint8_t data) {
	oled_start_wtxn();
	twi_write(0x40u);
	twi_write(data);
	oled_stop_txn();
}

void oled_area(uint8_t seg_begin, uint8_t seg_end, uint8_t page_begin, uint8_t page_end) {	
	oled_cmd(0x21u);
	oled_cmd(seg_begin);
	oled_cmd(seg_end);
	oled_cmd(0x22u);
	oled_cmd(page_begin);
	oled_cmd(page_end);
}

void oled_start_wtxn(void) {
	twi_start();
	twi_write(OLED_ADDRESS_W << 1);
}
void oled_stop_txn(void) {
	twi_stop();
}

void oled_init(void) {
	oled_cmd(0xAE);
	oled_cmd(0xD5);
	oled_cmd(0x80);
	oled_cmd(0xA8);
	oled_cmd(0x3F);
	oled_cmd(0xD3);
	oled_cmd(0x00);
	oled_cmd(0x40);
	oled_cmd(0x8d);
	oled_cmd(0x14);
	oled_cmd(0x20);
	oled_cmd(0x00);
	oled_cmd(0xA1);
	oled_cmd(0xC8);
	oled_cmd(0xDA);
	oled_cmd(0x12);
	oled_cmd(0x81);
	oled_cmd(0xCF);
	oled_cmd(0xD9);
	oled_cmd(0xF1);
	oled_cmd(0xDB);
	oled_cmd(0x40);
	oled_cmd(0xA4);
	oled_cmd(0xA6);
	oled_cmd(0xAF);
	//oled_cmd(0xAEu);
	//oled_cmd(0xA8u);
	//oled_cmd(0x3Fu);
	//oled_cmd(0xD3u);
	//oled_cmd(0x00u);
	//oled_cmd(0x40u);
	//oled_cmd(0xA0u);
	//oled_cmd(0xC0u);
	//oled_cmd(0xDAu);
	//oled_cmd(0x02u);
	//oled_cmd(0x81u);
	//oled_cmd(0x7Fu);
	//oled_cmd(0xA4u);
	//oled_cmd(0xA7u);
	//oled_cmd(0xD5u);
	//oled_cmd(0x80u);
	//oled_cmd(0x8Du);
	//oled_cmd(0x14u);
	//oled_cmd(0xAFu);
}