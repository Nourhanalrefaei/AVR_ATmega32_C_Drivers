/*
 * EXTI.c
 *
 * Created: 3/7/2022 12:37:46 PM
 *  Author: NourhalAlrefaei
 */ 
#include "EXTI.h"
void (*CallBackFunc)(void)=NULL_POINTER;

#define INT0       6
#define INT1       7
#define INT2       5

#define INTF0       6
#define INTF1       7
#define INTF2       5


#define ISC00       0
#define ISC01       1
#define ISC10       2
#define	ISC11       3

#define ISC2	    6

/*Function to Initialize External Interrupt*/
void EXTI_initialize(void)
{
	/*************Clearing all Source Modes *****************/
	CLEAR_BIT(REG_MCUCR,ISC00);
	CLEAR_BIT(REG_MCUCR,ISC01);
	CLEAR_BIT(REG_MCUCR,ISC10);
	CLEAR_BIT(REG_MCUCR,ISC11);
	//CLEAR_BIT(REG_MCUCSR,ISC2);
/*****************************************************************/
	
/****************Initializing Interrupts Source Mode**************/
	#if   EXTI0_MODE==EXTI_LOW_LEVEL
		REG_MCUCR |= EXTI_LOW_LEVEL;
	#elif EXTI0_MODE==EXTI_ANY_LOGICAL_CHANGE
		REG_MCUCR |= EXTI_ANY_LOGICAL_CHANGE;
	#elif EXTI0_MODE==EXTI_FALLING_EDGE
		REG_MCUCR |= EXTI_FALLING_EDGE;
	#elif EXTI0_MODE==EXTI_RISING_EDGE
		REG_MCUCR |= EXTI_RISING_EDGE;	
	#endif
	
	#if   EXTI1_MODE==EXTI_LOW_LEVEL
		REG_MCUCR |= (EXTI_LOW_LEVEL<<2);
	#elif EXTI1_MODE==EXTI_ANY_LOGICAL_CHANGE
		REG_MCUCR |= (EXTI_ANY_LOGICAL_CHANGE<<2);
	#elif EXTI1_MODE==EXTI_FALLING_EDGE
		REG_MCUCR |= (EXTI_FALLING_EDGE<<2);
	#elif EXTI1_MODE==EXTI_RISING_EDGE
		REG_MCUCR |= (EXTI_RISING_EDGE<<2);
	#endif
	
	#if EXTI2_MODE==EXTI_FALLING_EDGE
		CLEAR_BIT(REG_MCUCSR,ISC2);
	#elif EXTI2_MODE==EXTI_RISING_EDGE
		SET_BIT(REG_MCUCSR,ISC2);
	#endif
/*****************************************************************/


/************Initializing External Interrupts States**************/

	#if EXTI0_INT_STATE==EXTI_ENABLE_STATE
		SET_BIT(REG_GICR,INT0);
	#elif EXTI0_INT_STATE==EXTI_DISABLE_STATE
		CLEAR_BIT(REG_GICR,INT0);
	#endif
	
	
	#if EXTI1_INT_STATE==EXTI_ENABLE_STATE
		SET_BIT(REG_GICR,INT1);
	#elif EXTI1_INT_STATE==EXTI_DISABLE_STATE
		CLEAR_BIT(REG_GICR,INT1);
	#endif
	
	
	#if EXTI2_INT_STATE==EXTI_ENABLE_STATE
		SET_BIT(REG_GICR,INT2);
	#elif EXTI2_INT_STATE==EXTI_DISABLE_STATE
		CLEAR_BIT(REG_GICR,INT2);
	#endif
/*****************************************************************/
	
/**********************Clear Interrupts Flags*********************/
	SET_BIT(REG_GIFR,INTF0);
	SET_BIT(REG_GIFR,INTF1);
	SET_BIT(REG_GIFR,INTF2);
	
}


/*Function to Enable EXTI0 ISR*/
void EXTI_enableInt0(void)
{
	SET_BIT(REG_GICR,INT0);
}

/*Function to Disable EXTI0 ISR*/
void EXTI_disableInt0(void)
{
	CLEAR_BIT(REG_GICR,INT0);
}



/*Call Back Function*/
void EXTI_setCallBack(void(*CopyFunctionPtr)(void))
{
	CallBackFunc=CopyFunctionPtr;
}

void __vector_1(void)
{
	if(CallBackFunc !=NULL_POINTER)
	{
		CallBackFunc();
	}
	
}
