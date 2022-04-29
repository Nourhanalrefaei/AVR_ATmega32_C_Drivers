/*
 * hal_button.h
 *
 * Created: 2/7/2022 7:08:36 PM
 *  Author: DELL
 */ 


#ifndef HAL_BUTTON_H_
#define HAL_BUTTON_H_
#include "../../mcal/gpio/mcal_gpio.h"

/*Section:Data Type Definitions*/
typedef enum{
	BUTTON_NOT_PRESSED,
	BUTTON_PRESSED
}button_status;

typedef struct{
		enum_port_type  port_type:4;  
		enum_pin_type   pin_type:3;
		button_status   button_stat:1;
}button_t;

/*Section:Function Decelerations*/

ret_status button_init(button_t *btn);
ret_status button_get_status(button_t *btn,button_status* btn_status);


#endif /* HAL_BUTTON_H_ */