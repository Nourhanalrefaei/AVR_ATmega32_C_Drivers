/*
 * Timer_0_config.h
 *
 * Created: 4/19/2022 10:24:56 AM
 *  Author: DELL
 */ 


#ifndef TIMER_0_CONFIG_H_
#define TIMER_0_CONFIG_H_

#define F_CPU          16000000UL

#define Timer_0_Mode              Timer_0_NORMAL_Mode

#define Timer_0_interrupt_status  Timer_0_interrupt_enable

#define Timer_0_PWM_Mode          Fast_PWM_Mode

#define FAST_PWM_0_MODE           NON_INVERTED

#endif /* TIMER_0_CONFIG_H_ */