/*
 * hal_relay.h
 *
 * Created: 2/8/2022 10:34:13 AM
 *  Author: NourhanAlrefaei
 */ 


#ifndef HAL_RELAY_H_
#define HAL_RELAY_H_
#include "../../mcal/gpio/mcal_gpio.h"

typedef enum{
	RELAY_OFF,
	RELAY_ON
}relay_status;

typedef struct{
	enum_port_type port_name : 4;
	enum_pin_type pin : 3;
	uint8_type relay_status : 1;
}relay_t;

ret_status relay_initialize(relay_t *relay);
ret_status relay_turn_on(relay_t *relay);
ret_status relay_turn_off(relay_t *relay);


#endif /* HAL_RELAY_H_ */