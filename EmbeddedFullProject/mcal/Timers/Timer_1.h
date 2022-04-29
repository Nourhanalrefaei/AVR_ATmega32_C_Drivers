/*
 * Timer_1.h
 *
 * Created: 4/12/2022 8:10:11 PM
 *  Author: NourhanAlrefaei
 */ 


#ifndef TIMER_1_H_
#define TIMER_1_H_

#include "../gpio/mcal_gpio.h"

#define F_CPU      16000000
/*bits to set Timer_1 Mode*/
#define WGM10                0
#define WGM11                1
#define WGM12                3
#define WGM13                4

/*bit to enable Timer_1 Interrupt Overflow Flag*/
#define TOIE1                2

/*bits to set timer_1 clock Prescaler*/
#define  CS10                0
#define  CS11                1
#define  CS12                2

void Timer_1_init(void);
void Timer_1_start(void);
void Timer_1_stop(void);
void Timer_1_set_delay(uint32_type u32_delay_ms);
void Timer_1_set_Overflow_Callback(void(*copy_pointer)(void));
void Timer_1_PWM_init(void);
void Timer_1_PWM_start(void);
void Timer_1_PWM_stop(void);
void Timer_1_PWM_set_Duty_Cycle(uint8_type duty_cycle);
void Timer_1_InputCapture_init(void);
void Timer_1_InputCapture_Start(void); 
void Timer_1_set_InputCapture_Callback(void(*copy_pointer)(void));
void Timer_1_Cap_calculate(uint32_type* signal_frequency);

#endif /* TIMER_1_H_ */