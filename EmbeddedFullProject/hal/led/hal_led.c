/*
 * hal_led.c
 *
 * Created: 2/2/2022 11:49:45 AM
 *  Author: NourhanAlrefaei
 */ 
#include "hal_led.h"

/**
 * @brief Initialize the assigned pin to be OUTPUT and turn the led off.
 * @param led pointer to the led module
 * @return Status of the function 
 *    (R_OK) : The function done successfully
 */
ret_status led_init(led_t* led)
{
	ret_status ret=R_NOK;
	if((led !=NULL_POINTER)&&((led->port_info.port_type)<PORT_INVALID)&&((led->port_info.pin_type)<PIN_INVALID))
	{
		gpio_pin_direction_initialize(led->port_info.port_type,led->port_info.pin_type,DIRECTION_OUTPUT);
		gpio_write_pin(led->port_info.port_type,led->port_info.pin_type,VALUE_LOW);
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	
	return ret;
}

/**
 * @brief Turn the led on
 * @param led pointer to the led module
 * @return Status of the function 
 *      (R_OK) : The function done successfully
 */

ret_status led_turn_on(led_t* led)
{
	ret_status ret=R_NOK;
	if((led !=NULL_POINTER)&&((led->port_info.port_type)<PORT_INVALID)&&((led->port_info.pin_type)<PIN_INVALID))
	{
		gpio_write_pin(led->port_info.port_type,led->port_info.pin_type,VALUE_HIGH);
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
	
}
/**
 * @brief Turn the led off
 * @param led pointer to the led module
 * @return Status of the function 
 *         (R_OK) : The function done successfully
 */

ret_status led_turn_off(led_t* led)
{
	ret_status ret=R_NOK;
	if((led !=NULL_POINTER)&&((led->port_info.port_type)<PORT_INVALID)&&((led->port_info.pin_type)<PIN_INVALID))
	{
		gpio_write_pin(led->port_info.port_type,led->port_info.pin_type,VALUE_LOW);	
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
/**
 * @brief Toggle the led
 * @param led pointer to the led module
 * @return Status of the function 
 *         (R_OK) : The function done successfully
 */

ret_status led_turn_toggle(led_t* led)
{
	ret_status ret=R_NOK;
	if((led !=NULL_POINTER)&&((led->port_info.port_type)<PORT_INVALID)&&((led->port_info.pin_type)<PIN_INVALID))
	{
		gpio_toggle_pin(led->port_info.port_type,led->port_info.pin_type);
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}