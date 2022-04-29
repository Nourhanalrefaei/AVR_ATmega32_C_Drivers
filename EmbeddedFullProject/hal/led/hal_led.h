/*
 * hal_led.h
 *
 * Created: 2/2/2022 11:49:30 AM
 *  Author: NourhanAlrefaei
 */ 


#ifndef HAL_LED_H_
#define HAL_LED_H_
#include "../../mcal/gpio/mcal_gpio.h"

/*Section:Data Type Definitions*/
typedef enum{
	LED_OFF,
	LED_ON,
	LED_INVALID
}led_status;

typedef struct{
	struct  
	{
		enum_port_type  port_type:4;
		enum_pin_type   pin_type:4;
	}port_info;
	led_status          led_stat;
}led_t;


/*Section:Function Decelerations*/
ret_status led_init(led_t* led);
ret_status led_turn_on(led_t* led);
ret_status led_turn_off(led_t* led);
ret_status led_turn_toggle(led_t* led);


#endif /* HAL_LED_H_ */