/*
 * MPU_6050.h
 *
 * Created: 14.9.22 14:53:32
 *  Author: user
 */ 


#ifndef MPU_6050_H_
#define MPU_6050_H_

#define MPU_ADDRESS_W 0x68u
#define MPU_ADDRESS_R 0x69u

void mpu_start_w_txn(void);
void mpu_start_r_txn(void);
void mpu_stop_txn(void);


#endif /* MPU_6050_H_ */