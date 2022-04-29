/*
 * uart.h
 *
 * Created: 3/15/2022 6:28:00 PM
 *  Author: NourhanAlrefaei
 */ 


#ifndef UART_H_
#define UART_H_
#include "../gpio/mcal_gpio.h"
#include "uart_types.h"


#define F_CPU                 16000000UL
#define BOUD_RATE             9600
#define  MYUBRR               F_CPU/16/BOUD_RATE-1

/* 
 * Prototype   : void MUART_voidInitializeUART(void);
 * Description : initialize UART with pre configured parameter
 * Arguments   : void
 * return      : void  
 */
 void MUART_voidInitializeUART(void);

/* 
 * Prototype   : void MUART_voidSendByteSynch(u8 Copy_u8Byte);
 * Description : send 1 byte over UART
 * Arguments   : void
 * return      : void  
 */
 void MUART_voidSendByteSynch(uint8_type Copy_u8Byte);

/* 
 * Prototype   : uint8_type MUART_voidRecieveByteSynch(void);
 * Description : synchronous function that receive 1 byte over UART  
 * Arguments   : void
 * return      : uint8_type received byte  
 */
 uint8_type MUART_voidRecieveByteSynch(void);
 
 
 /* 
 * Prototype   : uint8_type MUART_Send_String(uint8_type *str);
 * Description : function that send string over UART 
 * Arguments   : uint8_type *str
 * return      : void  
 */
 
 void MUART_Send_String(uint8_type *str);


#endif /* UART_H_ */