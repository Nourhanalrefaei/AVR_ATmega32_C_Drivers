/*
 * EXT_EEPROM.c
 *
 * Created: 3/31/2022 2:43:47 PM
 *  Author: NourhanAlrefaei
 */ 
#include "EXT_EEPROM.h"


void EEPROM_Init()
{
	MI2C_voidInit();
}
uint8_type EEPROM_WriteByte(uint16_type Addr,uint8_type data)
{
	MI2C_voidSendStartCondition();
	if(~(MI2C_u8CheckStatus(MI2C_START_SENT)))
		return ERROR;
	MI2C_voidSendByte((uint8_type)(0xA0 | ((Addr & 0x0700) >> 7)));
	if(~(MI2C_u8CheckStatus(MI2C_SLA_W_SENT_WITH_ACK)))
		return ERROR;
	MI2C_voidSendByte((uint8_type)Addr);
	if(~(MI2C_u8CheckStatus(MI2C_DATA_SENT_WITH_ACK)))
		return ERROR;
	MI2C_voidSendByte(data);
	if(~(MI2C_u8CheckStatus(MI2C_DATA_SENT_WITH_ACK)));
		return ERROR;
    MI2C_voidSendStopCondition();
	
  return SUCCESS;
}
uint8_type EEPROM_ReadByte(uint16_type Addr,uint8_type *data)
{
	MI2C_voidSendStartCondition();
	if(~(MI2C_u8CheckStatus(MI2C_START_SENT)))
		return ERROR;
	MI2C_voidSendByte((uint8_type)(0xA0 | ((Addr & 0x0700) >> 7)));
	if(~(MI2C_u8CheckStatus(MI2C_SLA_W_SENT_WITH_ACK)))
		return ERROR;
	MI2C_voidSendByte((uint8_type)Addr);
	MI2C_voidSendStartCondition();
	if(~(MI2C_u8CheckStatus(MI2C_REPEATED_START_SENT)))
		return ERROR;
	MI2C_voidSendByte((uint8_type)(0xA0 | ((Addr & 0x0700) >> 7) | 1));
	if(~(MI2C_u8CheckStatus(MI2C_SLA_R_RECEIVED_WITH_ACK)))
		return ERROR;
	*data=MI2C_u8ReceiveDataWithNoAck();
	if(~(MI2C_u8CheckStatus(MI2C_DATA_RECEIVED_WITHOUT_ACK)))
		return ERROR;
	MI2C_voidSendStopCondition();

	return SUCCESS;
}
