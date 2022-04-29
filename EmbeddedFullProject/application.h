/*
 * application.h
 *
 * Created: 2/2/2022 10:01:12 AM
 *  Author: NourhanAlrefaei
 */ 

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "common_types.h"
#include "hal/led/hal_led.h"
#include "hal/button/hal_button.h"
#include "hal/relay/hal_relay.h"
#include "hal/dc_motor/hal_dc_motor.h"
#include "hal/char_lcd/hal_char_lcd.h"
#include "hal/Keybad/hal_keybad.h"
#include "hal/7_Segmant/hal_7_Segment.h"
#include "mcal/ADC/adc.h"
#include "mcal/Timers/Timer_0.h"
#include "mcal/Timers/Timer_1.h"
#include "mcal/UART/uart.h"
#include "mcal/SPI/SPI.h"
#include "Services_RTOS/RTO_interface.h"

void application_init(void);
void Timer_1_ISR(void);
/*Section: Macro Definitions*/
#define LED_SEQ_NUM  8
#endif /* APPLICATION_H_ */