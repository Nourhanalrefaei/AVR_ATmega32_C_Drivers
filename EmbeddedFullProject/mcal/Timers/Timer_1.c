/*
* Timer_1.c
*
* Created: 4/12/2022 8:09:34 PM
*  Author: NourhanAlrefaei
*/
#include "Timer_1.h"

/* Timer1 Interrupt ISRs
*====================================================================*/
void __vector_9 (void) __attribute__ ((signal,used));
void __vector_6 (void) __attribute__ ((signal,used));

/*====================================================================
* Call back pointers
*====================================================================*/
static void (*Timer_1_OverFlowCallBackPointer)(void);
static void (*Timer_1_CaptureEventCallBackpointer)(void);

/*****************************Global Variables************************/
static volatile float32_type Timer_1_number_of_overflow=ZERO_INIT;
static uint16_type TCNT_preload_value=ZERO_INIT;
static volatile uint32_type Cap_edge_1=ZERO_INIT;
static volatile uint32_type Cap_edge_2=ZERO_INIT;
static volatile uint32_type Capture_ticks=ZERO_INIT;
static volatile uint32_type capture_clk=ZERO_INIT;
static volatile uint32_type capture_freq=ZERO_INIT;
volatile uint8_type cap_num=ZERO_INIT;

void Timer_1_init(void)
{
	/*Enable Timer_1 Normal Mode*/
	CLEAR_BIT(REG_TCCR1A,WGM10);
	CLEAR_BIT(REG_TCCR1A,WGM11);
	CLEAR_BIT(REG_TCCR1B,WGM12);
	CLEAR_BIT(REG_TCCR1B,WGM13);
	
	/*Enable Timer_1 Interrupt Overflow Flag*/
	SET_BIT(REG_TIMSK,TOIE1);
	
	/*Enable Global Interrupt*/
	SET_BIT(REG_SREG,7);
}
void Timer_1_start(void)
{
	/*Prescaler 1024*/
	SET_BIT(REG_TCCR1B,CS10);
	SET_BIT(REG_TCCR1B,CS12);
	CLEAR_BIT(REG_TCCR1B,CS11);
	
}
void Timer_1_stop(void)
{
	/*Shut down Timer_1 Clock*/
	CLEAR_BIT(REG_TCCR1B,CS10);
	CLEAR_BIT(REG_TCCR1B,CS11);
	CLEAR_BIT(REG_TCCR1B,CS12);
}
void Timer_1_set_delay(uint32_type u32_delay_ms)
{
	
	uint8_type tick_time=(1024*1000000)/16000000;     /*Tick time in micro second*/
	float32_type time_overflow=(64*65536)/1000000;      /*Time of overflow in seconds*/
	float32_type no_of_overflow_reminder =ZERO_INIT;
	u32_delay_ms=u32_delay_ms/1000;                   /*Time_delay in seconds*/
	if(u32_delay_ms>time_overflow)
	{
		Timer_1_number_of_overflow=u32_delay_ms/time_overflow;
		no_of_overflow_reminder=Timer_1_number_of_overflow-(uint32_type)Timer_1_number_of_overflow;
		TCNT_preload_value=65536-(no_of_overflow_reminder*65536);
		
		REG_TCNT1L=(uint8_type)(TCNT_preload_value&0x00ff);
		REG_TCNT1H=(uint8_type)((TCNT_preload_value&0xff00)>>8);
		
		Timer_1_number_of_overflow=(uint32_type)Timer_1_number_of_overflow++;
	}
	else if(u32_delay_ms<=time_overflow)
	{
		Timer_1_number_of_overflow=u32_delay_ms/time_overflow;
		TCNT_preload_value=65536-(uint32_type)Timer_1_number_of_overflow*65536;
		REG_TCNT1L=(uint8_type)(TCNT_preload_value&0x00ff);
		REG_TCNT1H=(uint8_type)((TCNT_preload_value&0xff00)>>8);
		
		Timer_1_number_of_overflow=(uint32_type)Timer_1_number_of_overflow++;
	}
	else
	{
		
	}
}
void Timer_1_set_Overflow_Callback(void(*copy_pointer)(void))
{
	Timer_1_OverFlowCallBackPointer=copy_pointer;
}

void __vector_9(void)
{
	static uint32_type local_counter=ZERO_INIT;
	local_counter++;
	if(local_counter==Timer_1_number_of_overflow)
	{
		Timer_1_OverFlowCallBackPointer();
		local_counter=0;
	}
}

void Timer_1_PWM_init(void)
{
	/*Timer Mode operation fast mode 8 bit*/
	SET_BIT(REG_TCCR1A,WGM10);
	CLEAR_BIT(REG_TCCR1A,WGM11);
	SET_BIT(REG_TCCR1A,WGM12);
	CLEAR_BIT(REG_TCCR1A,WGM13);
	
	/*Enable non inverting mode*/
	CLEAR_BIT(REG_TCCR1A,6);
	SET_BIT(REG_TCCR1A,7);
	
	/*to activate output circuit on PDS pin*/
	SET_BIT(REG_DDRD,5);
}
void Timer_1_PWM_start(void)
{
	/*to select 256 division factor in Prescaler*/
	CLEAR_BIT(REG_TCCR1B,CS10);
	CLEAR_BIT(REG_TCCR1B,CS11);
	SET_BIT(REG_TCCR1B,CS12);
}
void Timer_1_PWM_stop(void)
{
	/*Shut down Timer_1 Clock*/
	CLEAR_BIT(REG_TCCR1B,CS10);
	CLEAR_BIT(REG_TCCR1B,CS11);
	CLEAR_BIT(REG_TCCR1B,CS12);
}
void Timer_1_PWM_set_Duty_Cycle(uint8_type duty_cycle)
{
	REG_OCR1AL = (((uint8_type) duty_cycle * 256 ) / 100 ) - 1;
	
}

void Timer_1_InputCapture_init(void)
{
	//to enable input capture circuit
	CLEAR_BIT(REG_DDRD,6);
	/*Capture at the rising edge*/
	SET_BIT(REG_TCCR1B,6);
	/*Enable input capture interrupt*/
	SET_BIT(REG_TIMSK,5);
}

void Timer_1_InputCapture_Start(void)
{
	/*Set Prescaler at 8MHZ*/
	CLEAR_BIT(REG_TCCR1B,0);
	SET_BIT(REG_TCCR1B,1);
	CLEAR_BIT(REG_TCCR1B,2);
}
void Timer_1_set_InputCapture_Callback(void(*copy_pointer)(void))
{
	Timer_1_CaptureEventCallBackpointer=copy_pointer;
}

void __vector_6(void)
{
	if(cap_num==0)
	{
		Cap_edge_1=(REG_ICR1H<<8)|REG_ICR1L;
		Timer_1_number_of_overflow=0;
	}
	else if(cap_num==1)
	{
		Cap_edge_2=(REG_ICR1H<<8)|REG_ICR1L;
		/*Disable input capture interrupt*/
		CLEAR_BIT(REG_TIMSK,5);
		/*Disable Timer_1 Interrupt Overflow Flag*/
		CLEAR_BIT(REG_TIMSK,TOIE1);
	}
	cap_num++;
	if(cap_num==2)
	{
		Timer_1_CaptureEventCallBackpointer();
		cap_num=0;
	}	
}

void Timer_1_Cap_calculate(uint32_type* signal_frequency)
{
	Capture_ticks=((uint32_type)Cap_edge_1+(uint32_type)Timer_1_number_of_overflow*65536)-(uint32_type)Cap_edge_2;
	//Tick Time = 8 / 16*10^6 = 0.5 us
	capture_clk= Capture_ticks*0.5;          //period time in micro second 
	capture_freq=(1/(float32_type)capture_clk)*1000000;    //frequency in HZ
	*signal_frequency=capture_freq;
	/*Enable input capture interrupt*/
	SET_BIT(REG_TIMSK,5);
	/*Enable Timer_1 Interrupt Overflow Flag*/
	SET_BIT(REG_TIMSK,TOIE1);
	Timer_1_number_of_overflow=0;
	
}