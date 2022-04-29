/*
 * Timer_0.h
 *
 * Created: 4/19/2022 10:00:40 AM
 *  Author: NourhanAlrefaei
 */ 


#ifndef TIMER_0_H_
#define TIMER_0_H_
#include "../gpio/mcal_gpio.h"
#include "Timer_0_config.h"

/*Waveform Generation Mode TCCR0 bits*/
#define WGM00                     6
#define WGM01                     3

/*Compare Match Output Mode TCCR0 bits*/
#define COM00                     4
#define COM01                     5

/*Prescaler Clock Select TCCR0 bits*/
#define  CS00                     0
#define  CS01                     1
#define  CS02                     2

/* Overflow Interrupt Enable TIMSK bit*/
#define TOIE0                     0
/*Output Compare Match Interrupt Enable TIMSK bit*/
#define OCIE0                     1


void Timer_0_init(void);

void Timer_0_Start(void);

void Timer_0_Stop(void);


void Timer_0_set_time_ms(uint32_type copy_time_ms);


void Timer_0_SetOverFlowCallBack(void(*Copy_Ptr)(void));
 
 
void Timer_0_PWM_init(void);


void Timer_0_PWM_START(void);


void Timer_0_PWM_STOP(void);


void Timer_0_PWM_set_duty_cycle(uint8_type duty_cycle);

#endif /* TIMER_0_H_ */