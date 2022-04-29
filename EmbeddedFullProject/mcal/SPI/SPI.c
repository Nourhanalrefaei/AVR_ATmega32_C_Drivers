/*
 * SPI.c
 *
 * Created: 3/16/2022 3:43:29 PM
 *  Author: NourhanAlrefaei
 */ 
#include "SPI.h"


void SPI_MasterInit(void)
{
	gpio_pin_direction_initialize(PORT_B,PIN_4,DIRECTION_OUTPUT); /*configure ss direction (output)*/
	gpio_pin_direction_initialize(PORT_B,PIN_5,DIRECTION_OUTPUT); /*Configure MOSI direction (output)*/
	gpio_pin_direction_initialize(PORT_B,PIN_6,DIRECTION_INPUT); /*Configure MISO direction (input)*/
	gpio_pin_direction_initialize(PORT_B,PIN_7,DIRECTION_OUTPUT); /*Configure SCK direction(output)*/
	
	/*To be a master*/
	SET_BIT(REG_SPCR,4);
	/*To enable SPI Circuit*/
	SET_BIT(REG_SPCR,6);
	
	/*Disable interrupt*/
	CLEAR_BIT(REG_SPCR,7);
	
	/*MSB is transmitted first*/
	CLEAR_BIT(REG_SPCR,5);
	
	/*Prescaler 128   --- Used only with master because it sends c/k*/
	SET_BIT(REG_SPCR,0);
	SET_BIT(REG_SPCR,1);
	
	/*Clock polarity (low when idle)*/
	CLEAR_BIT(REG_SPCR,3);
	
	/*Sample in leading age*/
	CLEAR_BIT(REG_SPCR,2);
	
	/*flag is reset and FOCS/128 is used*/
	REG_SPSR=0x00;
}
void SPI_SlaveInit(void)
{
		gpio_pin_direction_initialize(PORT_B,PIN_4,DIRECTION_INPUT); /*configure ss direction (input)*/
		gpio_pin_direction_initialize(PORT_B,PIN_5,DIRECTION_INPUT); /*Configure MOSI direction (input)*/
		gpio_pin_direction_initialize(PORT_B,PIN_6,DIRECTION_OUTPUT); /*Configure MISO direction (output)*/
		gpio_pin_direction_initialize(PORT_B,PIN_7,DIRECTION_INPUT); /*Configure SCK direction(input)*/
		
	/*To be slave*/
	CLEAR_BIT(REG_SPCR,4);
	/*To enable SPI Circuit*/
	SET_BIT(REG_SPCR,6);
	
	/*Disable interrupt*/
	CLEAR_BIT(REG_SPCR,7);
	
	/*MSB is transmitted first*/
	CLEAR_BIT(REG_SPCR,5);
	
	/*Prescaler 128   --- Used only with master because it sends c/k*/
	SET_BIT(REG_SPCR,0);
	SET_BIT(REG_SPCR,1);
	
	/*Clock polarity (low when idle)*/
	CLEAR_BIT(REG_SPCR,3);
	
	/*Sample in leading age*/
	CLEAR_BIT(REG_SPCR,2);
	
	/*flag is reset and FOCS/128 is used*/
	REG_SPSR=0x00;
}
void SPI_SendChar(uint8_type idata)
{
	REG_SPDR = idata;                /*Send input data to the data register*/
	while(READ_BIT(REG_SPSR,7)==0);  /*While transmission not complete wait(to avoid overlapping of data transmission)*/
}
uint8_type SPI_GetChar(void)
{
	while(READ_BIT(REG_SPSR,7)==0);  /*While transmission not complete wait(to avoid overlapping of data transmission)*/
	return REG_SPDR;                 /*return the data found in data register*/
}