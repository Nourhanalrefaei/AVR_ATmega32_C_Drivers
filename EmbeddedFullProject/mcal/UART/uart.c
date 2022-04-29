/*
 * uart.c
 *
 * Created: 3/15/2022 6:27:40 PM
 *  Author: NourhanAlrefaei
 */ 
#include "uart.h"

/*==============================================================================================================================================
 * Global Variables
 *==============================================================================================================================================*/


/*==============================================================================================================================================
 * Driver Modules implementations
 *==============================================================================================================================================*/


/* 
 * Prototype   : void MUART_voidInitializeUART(void);
 * Description : initialize UART with pre configured parameter
 * Arguments   : void
 * return      : void  
 */
 void MUART_voidInitializeUART(void)
 {
	 /*initialize the TX,RX pins Direction*/
	 gpio_pin_direction_initialize(PORT_D,PIN_0,DIRECTION_OUTPUT);
	 gpio_pin_direction_initialize(PORT_D,PIN_1,DIRECTION_INPUT);
	 /*Receive enable config*/
	SET_BIT(REG_UCSRB,MUART_RXEN);
	 /*Send enable config*/
	SET_BIT(REG_UCSRB,MUART_TXEN);
	 /*Mode config (Asynchronous)*/
	 CLEAR_BIT(REG_UCSRC,MUART_URSEL);
	 CLEAR_BIT(REG_UCSRC,MUART_UMSEL);
	 /*Parity Mode (Disable)*/
	 CLEAR_BIT(REG_UCSRC,MUART_UPM1);
	 CLEAR_BIT(REG_UCSRC,MUART_UPM0);
	 /*Stop Bits config(1_bit)*/
	 CLEAR_BIT(REG_UCSRC,MUART_USBS);
	  /*Character size config(8_bits)*/
	 SET_BIT(REG_UCSRC,MUART_UCSZ1);
	 SET_BIT(REG_UCSRC,MUART_UCSZ0);
	 CLEAR_BIT(REG_UCSRC,MUART_UCSZ2);
	 /*Send the low 8 bits of UBRR*/
	 REG_UBRRL=(uint8_type)(MYUBRR);
	 /*Send the high 4 bits of UBRR*/
	 REG_UBRRH=(uint8_type)(MYUBRR>>8); 
 }

/* 
 * Prototype   : void MUART_voidSendByteSynch(u8 Copy_u8Byte);
 * Description : send 1 byte over UART
 * Arguments   : void
 * return      : void  
 */
 void MUART_voidSendByteSynch(uint8_type Copy_u8Byte)
 {
	 while(READ_BIT(REG_UCSRA,MUART_UDRE)==0); /*Wait until the buffer is empty*/
	 REG_UDR=Copy_u8Byte;
 }

/* 
 * Prototype   : uint8_type MUART_voidRecieveByteSynch(void);
 * Description : synchronous function that receive 1 byte over UART  
 * Arguments   : void
 * return      : uint8_type received byte  
 */
 uint8_type MUART_voidRecieveByteSynch(void)
 {
	 while(READ_BIT(REG_UCSRA,MUART_RXC)==0);
	 return REG_UDR;
 }
 
 /* 
 * Prototype   : uint8_type MUART_Send_String(uint8_type *str);
 * Description : function that send string over UART 
 * Arguments   : uint8_type *str
 * return      : void  
 */
 
 void MUART_Send_String(uint8_type *str)
 {
	 uint8_type iter=ZERO_INIT;
	 while(str[iter] != 0)
	 {
		 MUART_voidSendByteSynch(str[iter]);
		 iter++;
	 }
 }
 