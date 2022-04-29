/*
 * hal_relay.c
 *
 * Created: 2/8/2022 10:34:34 AM
 *  Author: NourhanAlrefaei
 */ 
#include "hal_relay.h"

ret_status relay_initialize(relay_t *relay)
{
	ret_status ret=R_NOK;
	if((relay!=NULL_POINTER)&&(relay->port_name<PORT_INVALID)&&(relay->pin<PIN_INVALID))
	{
		gpio_pin_direction_initialize(relay->port_name,relay->pin,DIRECTION_OUTPUT);
		gpio_write_pin(relay->port_name,relay->pin,VALUE_LOW);
		relay->relay_status=RELAY_OFF;
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
ret_status relay_turn_on(relay_t *relay)
{
	ret_status ret=R_NOK;
	if((relay!=NULL_POINTER)&&(relay->port_name<PORT_INVALID)&&(relay->pin<PIN_INVALID))
	{
		gpio_write_pin(relay->port_name,relay->pin,VALUE_HIGH);
		relay->relay_status=RELAY_ON;
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
ret_status relay_turn_off(relay_t *relay)
{
	ret_status ret=R_NOK;
	if((relay!=NULL_POINTER)&&(relay->port_name<PORT_INVALID)&&(relay->pin<PIN_INVALID))
	{
		gpio_write_pin(relay->port_name,relay->pin,VALUE_LOW);
		relay->relay_status=RELAY_OFF;
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
