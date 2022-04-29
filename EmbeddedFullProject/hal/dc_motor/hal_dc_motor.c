/*
 * hal_dc_motor.c
 *
 * Created: 2/8/2022 11:33:13 AM
 *  Author: NourhanAlrefaei
 */ 
#include "hal_dc_motor.h"
ret_status dc_motor_initialize(dc_motor_t *dc_motor)
{
	ret_status ret = R_NOK;
	if(NULL_POINTER == dc_motor){
		return ret;
	}
	else{
		relay_initialize(&(dc_motor->relay1));
		relay_initialize(&(dc_motor->relay2));
		ret = R_OK;
	}
	return ret;
}
ret_status dc_motor_rotate_right(dc_motor_t *dc_motor)
{
	ret_status ret = R_NOK;
	if(NULL == dc_motor){
		return ret;
	}
	else{
		relay_turn_on(&(dc_motor->relay1));
		relay_turn_off(&(dc_motor->relay2));
		ret = R_OK;
	}
	return ret;
}
ret_status dc_motor_rotate_left(dc_motor_t *dc_motor)
{
	ret_status ret = R_NOK;
	if(NULL == dc_motor){
		return ret;
	}
	else{
		relay_turn_off(&(dc_motor->relay1));
		relay_turn_on(&(dc_motor->relay2));
		ret = R_OK;
	}
	return ret;
}
ret_status dc_motor_stop(dc_motor_t *dc_motor)
{
	ret_status ret = R_NOK;
	if(NULL == dc_motor){
		return ret;
	}
	else{
		relay_turn_off(&(dc_motor->relay1));
		relay_turn_off(&(dc_motor->relay2));
		ret = R_OK;
	}
	return ret;
}