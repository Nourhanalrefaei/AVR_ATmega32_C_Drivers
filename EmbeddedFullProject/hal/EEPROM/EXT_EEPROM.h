/*
 * EXT_EEPROM.h
 *
 * Created: 3/31/2022 2:44:26 PM
 *  Author: NourhanAlrefaei
 */ 


#ifndef EXT_EEPROM_H_
#define EXT_EEPROM_H_
#include "../../mcal/gpio/mcal_gpio.h"
#include "../../mcal/I2C/I2C.h"

#define ERROR 0
#define SUCCESS 1


void EEPROM_Init();
uint8_type EEPROM_WriteByte(uint16_type Addr,uint8_type data);
uint8_type EEPROM_ReadByte(uint16_type Addr,uint8_type *data);


#endif /* EXT_EEPROM_H_ */