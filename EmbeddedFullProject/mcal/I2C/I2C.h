/*
 * I2C.h
 *
 * Created: 3/23/2022 1:19:08 PM
 *  Author: NourhanArefaei
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "../gpio/mcal_gpio.h"
#include "I2C_Config.h"

//TWCR REG
#define MI2C_TWIE_BIT     0
#define MI2C_TWEN_BIT     2
#define MI2C_TWWC_BIT     3
#define MI2C_TWSTO_BIT    4
#define MI2C_TWSTA_BIT    5
#define MI2C_TWEA_BIT     6
#define MI2C_TWINT_BIT    7

#define MI2C_TWPS0_BIT    0
#define MI2C_TWPS1_BIT    1

#define MI2C_TWGCE_BIT    0

//TWPS Values
#define MI2C_TWPS_1   0
#define MI2C_TWPS_4   1
#define MI2C_TWPS_16  2
#define MI2C_TWPS_64  3

#define MI2C_DISABLE_GENERAL_CALL 0
#define MI2C_ENABLE_GENERAL_CALL  1

#define MI2C_TWSR_REG_MASK 0xF8

//I2C Expected status
#define MI2C_START_SENT                   0x08
#define MI2C_REPEATED_START_SENT          0x10
#define MI2C_SLA_W_SENT_WITH_ACK          0x18
#define MI2C_SLA_W_SENT_WITHOT_ACK        0x20
#define MI2C_DATA_SENT_WITH_ACK           0x28
#define MI2C_DATA_SENT_WITHOUT_ACK        0x30
#define MI2C_ARBITRATION_LOST             0x38
#define MI2C_SLA_R_RECEIVED_WITH_ACK      0x40
#define MI2C_SLA_R_RECEIVED_WITHOT_ACK    0x48
#define MI2C_DATA_RECEIVED_WITH_ACK       0x50
#define MI2C_DATA_RECEIVED_WITHOUT_ACK    0x58

#define MI2C_WRITE_OP  0
#define MI2C_READ_OP   1

void MI2C_voidInit(void);
void MI2C_voidSendStartCondition(void);
void MI2C_voidSendStopCondition(void);
uint8_type MI2C_u8CheckStatus(uint8_type Copy_u8ExpectedStatus);
void MI2C_voidSendSlaveAddress(uint8_type Copy_u8SlaveAdd,uint8_type Copy_u8Operation);
void MI2C_voidSendByte(uint8_type Copy_u8Data);
uint8_type   MI2C_u8ReceiveDataWithNoAck(void);



#endif /* I2C_H_ */