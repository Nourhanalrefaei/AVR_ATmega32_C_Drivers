/*
 * hal_dc_motor.h
 *
 * Created: 2/8/2022 11:33:57 AM
 *  Author: NourhanAlrefaei
 */ 


#ifndef HAL_DC_MOTOR_H_
#define HAL_DC_MOTOR_H_
#include "../relay/hal_relay.h"

typedef struct{
	relay_t relay1;
	relay_t relay2;
}dc_motor_t;

ret_status dc_motor_initialize(dc_motor_t *dc_motor);
ret_status dc_motor_rotate_right(dc_motor_t *dc_motor);
ret_status dc_motor_rotate_left(dc_motor_t *dc_motor);
ret_status dc_motor_stop(dc_motor_t *dc_motor);

#endif /* HAL_DC_MOTOR_H_ */