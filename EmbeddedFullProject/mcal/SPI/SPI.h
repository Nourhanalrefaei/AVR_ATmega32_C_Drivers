/*
 * SPI.h
 *
 * Created: 3/16/2022 3:43:08 PM
 *  Author: NourhanAlrefaei
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "../gpio/mcal_gpio.h"

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_SendChar(uint8_type idata);
uint8_type SPI_GetChar(void);



#endif /* SPI_H_ */