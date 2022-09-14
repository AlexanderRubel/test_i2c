/*
 * twi_module.h
 *
 * Created: 4.9.22 11:08:26
 *  Author: user
 */ 


#ifndef TWI_MODULE_H_
#define TWI_MODULE_H_

void twi_init(void);
void twi_start(void);
void twi_write(unsigned char data);
unsigned char twi_read(unsigned char isLast);
void twi_stop(void);

#endif /* TWI_MODULE_H_ */
