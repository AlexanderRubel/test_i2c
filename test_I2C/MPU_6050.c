/*
 * MPU_6050.c
 *
 * Created: 14.9.22 14:53:02
 *  Author: user
 */ 
#include "MPU_6050.h"

void mpu_start_w_txn(void) {
	twi_start();
	twi_write(MPU_ADDRESS_W << 1);
}
void mpu_start_r_txn(void) {
	twi_start();
	twi_write(MPU_ADDRESS_R << 1);
}
void mpu_stop_txn(void) {
	twi_stop();
}

void mpu_init(void) {
	
}