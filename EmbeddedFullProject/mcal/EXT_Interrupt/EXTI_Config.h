/*
 * EXTI_Config.h
 *
 * Created: 3/7/2022 12:38:53 PM
 *  Author: NourhalAlrefaei
 */ 


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*
*Configure The External Interrupt 0 mode
*Range:
* EXTI_LOW_LEVEL         
* EXTI_ANY_LOGICAL_CHANGE
* EXTI_FALLING_EDGE      
* EXTI_RISING_EDGE       
*/
#define  EXTI0_MODE                EXTI_FALLING_EDGE

/*
*Configure The External Interrupt 1 mode
*Range:
* EXTI_LOW_LEVEL
* EXTI_ANY_LOGICAL_CHANGE
* EXTI_FALLING_EDGE
* EXTI_RISING_EDGE
*/
#define  EXTI1_MODE                EXTI_FALLING_EDGE

/*
*Configure The External Interrupt 2 mode
*Range:
* EXTI_FALLING_EDGE
* EXTI_RISING_EDGE
*/
#define  EXTI2_MODE                EXTI_FALLING_EDGE

/*
*Configure The External Interrupt Initial State
*Range:
*EXTI_ENABLE_STATE    
*EXTI_DISABLE_STATE   
*/
#define  EXTI0_INT_STATE           EXTI_DISABLE_STATE
#define  EXTI1_INT_STATE           EXTI_DISABLE_STATE
#define  EXTI2_INT_STATE           EXTI_DISABLE_STATE

#endif /* EXTI_CONFIG_H_ */