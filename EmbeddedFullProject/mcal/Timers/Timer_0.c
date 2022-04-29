/*
 * Timer_0.c
 *
 * Created: 4/19/2022 10:00:21 AM
 *  Author: NourhanAlrefaei
 */ 
#include "Timer_0.h"
/*====================================================================
 * Timer0 Interrupt ISRs
 *====================================================================*/
void __vector_10 (void) __attribute__ ((signal,used));
void __vector_11 (void) __attribute__ ((signal,used));

/*====================================================================
 * Call back pointers 
 *====================================================================*/
static void (*Timer_0_OverFlowCallBackPointer)(void);
static void (*Timer_0_CTCCallBackPointer)(void);


/***************************Global Variables********************************/
static volatile float32_type Timer_0_no_of_overflow        = ZERO_INIT;
static uint8_type           Timer_0_TCNT_preload_value     = ZERO_INIT;

void Timer_0_Start(void)
{
	/*Enable 1024 Prescaler on the MC clock source*/
	REG_TCCR0 |= 0x05;
}

void Timer_0_Stop(void)
{
	/*Shut down the clock on the timer clock source*/
	CLEAR_BIT(REG_TCCR0,CS00);
	CLEAR_BIT(REG_TCCR0,CS01);
	CLEAR_BIT(REG_TCCR0,CS02);
}

void Timer_0_init(void)
{
	#if Timer_0_Mode == Timer_0_NORMAL_Mode
	/*Enable Timer0 Normal Mode*/
	CLEAR_BIT(REG_TCCR0,WGM00);
	CLEAR_BIT(REG_TCCR0,WGM01);
		#if Timer_0_interrupt_status == Timer_0_interrupt_enable
		/*Enable global Interrupt*/
		SET_BIT(REG_SREG,7);
		/*Overflow Interrupt Enable*/
		SET_BIT(REG_TIMSK,TOIE0);
		#endif
		
	#elif Timer_0_Mode == Timer_0_CTC_Mode
	/*Enable Timer0 CTC Mode*/
	CLEAR_BIT(REG_TCCR0,WGM00);
	SET_BIT(REG_TCCR0,WGM01);
		#if Timer_0_interrupt_status == Timer_0_interrupt_enable
		/*Enable global Interrupt*/
		SET_BIT(REG_SREG,GIE_ENABLE_BIT);
		/*Output Compare Match Interrupt Enable*/
		SET_BIT(REG_TIMSK,OCIE0);
		#endif
	#endif 
}


void Timer_0_set_time_ms(uint32_type copy_time_ms)
{
	uint8_type tick_time= (1024*1000000)/F_CPU;        /*tick time in micro second*/
	uint8_type time_overflow= (tick_time*256)/1000;    /*over flow time in Milli second*/
	float32_type no_of_overflow_reminder =ZERO_INIT;
	Timer_0_no_of_overflow=copy_time_ms/time_overflow;
	no_of_overflow_reminder=Timer_0_no_of_overflow-(uint32_type)Timer_0_no_of_overflow;
	
	#if Timer_0_Mode == Timer_0_NORMAL_Mode
	Timer_0_TCNT_preload_value=256-(no_of_overflow_reminder*256);
	REG_TCNT0=Timer_0_TCNT_preload_value;
	Timer_0_no_of_overflow=(uint32_type)Timer_0_no_of_overflow++;
	#elif Timer_0_Mode == Timer_0_CTC_Mode
	/*TODO*/
	#endif
}

 void Timer_0_SetOverFlowCallBack(void(*Copy_Ptr)(void))
 {
	 Timer_0_OverFlowCallBackPointer = Copy_Ptr;
 }
 
 void __vector_11(void) /*Timer0 over flow ISR*/
 {
	static uint32_type Local_u32Counter = 0;
	Local_u32Counter++;
	if(Local_u32Counter == Timer_0_no_of_overflow)
	{
		/*Run call back function for Timer0 over flow interrupt*/
		Timer_0_OverFlowCallBackPointer();
		Local_u32Counter=0;
	}
}

void Timer_0_PWM_START(void)
{
	/*Set Timer Clock Prescaler 256*/
	CLEAR_BIT(REG_TCCR0,CS00);
	CLEAR_BIT(REG_TCCR0,CS01);
	SET_BIT(REG_TCCR0,CS02);
}

void Timer_0_PWM_STOP(void)
{
	/*shut down Timer Clock*/
	CLEAR_BIT(REG_TCCR0,CS00);
	CLEAR_BIT(REG_TCCR0,CS01);
	CLEAR_BIT(REG_TCCR0,CS02);
}
void Timer_0_PWM_init(void)
{
	//to enable output circuit
	SET_BIT(REG_DDRB,3); 
	#if Timer_0_PWM_Mode == Fast_PWM_Mode
	/*Enable the Fast PWM Mode*/
	 SET_BIT(REG_TCCR0,WGM00);
	 SET_BIT(REG_TCCR0,WGM01);
	 
		 #if FAST_PWM_0_MODE     == NON_INVERTED
		 /*to select non inverted mode*/
		 CLEAR_BIT(REG_TCCR0,COM00);
		 SET_BIT(REG_TCCR0,COM01);
		 #elif FAST_PWM_0_MODE     == INVERTED
		 SET_BIT(REG_TCCR0,COM00);
		 SET_BIT(REG_TCCR0,COM01);
		 #endif
	#elif Timer_0_PWM_Mode== Phase_Correct_Mode
	/*TODO*/
	#endif
	
}

void Timer_0_PWM_set_duty_cycle(uint8_type duty_cycle)

{
	/*Equation from data sheet. Subtracting 1 to handle the corner case of 100% DC*/
	REG_OCR0 = ((duty_cycle * 256 ) /100 ) - 1;
}