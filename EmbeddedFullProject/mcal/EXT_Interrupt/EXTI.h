/*
 * EXTI.h
 *
 * Created: 3/7/2022 12:38:11 PM
 *  Author: NourhalAlrefaei
 */ 


#ifndef EXTI_H_
#define EXTI_H_
#include "../gpio/mcal_gpio.h"
#include "EXTI_Types.h"
#include "EXTI_Config.h"



/*Function to Initialize External Interrupt*/
void EXTI_initialize(void);

/*Function to Enable EXTI0 ISR*/
void EXTI_enableInt0(void);

/*Function to Disable EXTI0 ISR*/
void EXTI_disableInt0(void);

/*Call Back Function*/
void EXTI_setCallBack(void(*CopyFunctionPtr)(void));
void __vector_1(void) __attribute__ ((signal,used));
#endif /* EXTI_H_ */