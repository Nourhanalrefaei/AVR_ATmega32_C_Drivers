/*
 * hal_button.c
 *
 * Created: 2/7/2022 7:08:16 PM
 *  Author: DELL
 */ 
#include "hal_button.h"

ret_status button_init(button_t *btn)
{
	ret_status ret=R_NOK;
	if((btn!=NULL_POINTER)&&(btn->port_type<PORT_INVALID)&&(btn->pin_type<PIN_INVALID))
	{
		gpio_pin_direction_initialize(btn->port_type,btn->pin_type,DIRECTION_INPUT);
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
ret_status button_get_status(button_t *btn,button_status* btn_status)
{
	ret_status ret=R_NOK;
	if((btn!=NULL_POINTER)&&(btn->port_type<PORT_INVALID)&&(btn->pin_type<PIN_INVALID))
	{
		gpio_read_pin(btn->port_type,btn->pin_type,btn_status);
		btn->button_stat=*btn_status;
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}