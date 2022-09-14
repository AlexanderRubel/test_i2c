#include <avr/io.h>

void twi_init(void) {
	TWSR = 0x00; //set prescaler bits to zero
	TWBR = 0x39; //SCL Frequency is 50k for XTAL=8M
	TWCR = 0x04; //enable the TWI module
}

void twi_start(void) {
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while ((TWCR & (1 << TWINT)) == 0);
}

void twi_write(unsigned char data) {
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while ((TWCR & (1 << TWINT)) == 0);
}

unsigned char twi_read(unsigned char isLast) {
	if (isLast == 0)
	TWCR = (1 << TWINT) | (1 << TWEN);
	else
	TWCR = (1 << TWINT) | (1 << TWEN);
	
	while ((TWCR & (1 << TWINT)) == 0);
	
	return TWDR;
}

void twi_stop(void) {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}