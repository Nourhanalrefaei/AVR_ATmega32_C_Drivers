/*
 * I2C.c
 *
 * Created: 3/23/2022 1:04:27 PM
 *  Author: NourhanArefaei
 */ 
#include "I2C.h"

void MI2C_voidInit(void)
{
	SET_BIT(REG_TWCR,MI2C_TWEN_BIT);     //Enable TWI
	REG_TWBR = MI2C_TWBR_VALUE;          //Set TWBR = 8
	//Prepare TWSR for masking TWPS0,TWPS1
	CLEAR_BIT(REG_TWSR,MI2C_TWPS0_BIT);
	CLEAR_BIT(REG_TWSR,MI2C_TWPS1_BIT);
	//Put MI2C TWPS Value in Reg TWSR
	REG_TWSR &= ((MI2C_TWPS_VALUE)|(MI2C_TWSR_REG_MASK)) ;
	// Set My slave address
	REG_TWAR = (MI2C_SLAVE_ADDRESS<<1);
	//general call
	if (MI2C_GENERAL_CALL_MODE == MI2C_ENABLE_GENERAL_CALL)
	{
		SET_BIT(REG_TWAR,MI2C_TWGCE_BIT);
	}
}
void MI2C_voidSendStartCondition(void)
{
	REG_TWCR = (1<<MI2C_TWINT_BIT)|(1<<MI2C_TWSTA_BIT)|(1<<MI2C_TWEN_BIT);  //Send Start condition + clear TWINT flag to start TWI operation
	while(READ_BIT(REG_TWCR,MI2C_TWINT_BIT)==0);                            //wait until start is transmitted
	//while((REG_TWSR & 0xF8)!=MI2C_START_SENT);								//check for acknowledgment
	REG_TWCR = (1<<MI2C_TWEN_BIT);
}
void MI2C_voidSendStopCondition(void)
{
	REG_TWCR = (1<<MI2C_TWINT_BIT)|(1<<MI2C_TWSTO_BIT)|(1<<MI2C_TWEN_BIT);  //Send Stop condition + clear TWINT flag to start TWI operation
	while(READ_BIT(REG_TWCR,MI2C_TWINT_BIT)==0);                             //wait until stop is transmitted
}
uint8_type MI2C_u8CheckStatus(uint8_type Copy_u8ExpectedStatus)
{
	if ((REG_TWSR & MI2C_TWSR_REG_MASK) == Copy_u8ExpectedStatus)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void MI2C_voidSendSlaveAddress(uint8_type Copy_u8SlaveAdd,uint8_type Copy_u8Operation)
{
	REG_TWDR = (Copy_u8SlaveAdd<<1)|(Copy_u8Operation);  //Put address and operation in TWDR Reg
	REG_TWDR = (1<<MI2C_TWINT_BIT)|(1<<MI2C_TWEN_BIT);   // reset flag Start sending address and operation
	while((READ_BIT(REG_TWCR,MI2C_TWINT_BIT))==0);       //wait until operation complete
}
void MI2C_voidSendByte(uint8_type Copy_u8Data)
{
	REG_TWDR = Copy_u8Data;
	REG_TWDR = (1<<MI2C_TWINT_BIT)|(1<<MI2C_TWEN_BIT);    // reset flag Start sending Data
	while((READ_BIT(REG_TWCR,MI2C_TWINT_BIT))==0);        //wait until operation complete
}
uint8_type   MI2C_u8ReceiveDataWithNoAck(void)
{
	REG_TWCR = (1<<MI2C_TWINT_BIT)|(1<<MI2C_TWEN_BIT);   // reset flag Start Receiving data
	while((READ_BIT(REG_TWCR,MI2C_TWINT_BIT))==0);        //wait until operation complete
	return 	REG_TWDR;
}

