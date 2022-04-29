/*
*mcal_gpio.c
*
* Created: 2/2/2022 10:05:57 AM
*  Author: NourhanAlrefaei
*/
#include "mcal_gpio.h"

/* Reference to the Data Direction Control Registers */
static volatile uint8_type* ddr_register[]={&REG_DDRA,&REG_DDRB,&REG_DDRC,&REG_DDRD};
/* Reference to the Data Port Register (Read and Write to Data port) */
static volatile uint8_type* port_register[]={&REG_PORTA,& REG_PORTB,& REG_PORTC,& REG_PORTD};
/* Reference to the Pin Status Register  */
static volatile uint8_type* pin_register[]={&REG_PINA,&REG_PINB,&REG_PINC,&REG_PIND};
	
/**
 * @brief initialize pin direction to be input or output 
 * @param port
 * @param pin
 * @param direction
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_pin_direction_initialize(enum_port_type port_type,enum_pin_type pin_type, enum_direction_type direction_type)
{
	ret_status ret=R_NOK;
	if((port_type<PORT_INVALID)&&(pin_type<PIN_INVALID)&&(direction_type<DIRECTION_INVALID))
	{
		switch(direction_type)
		{
			case DIRECTION_INPUT:
			{
				CLEAR_BIT(*ddr_register[port_type],pin_type);
				break;
			}
			case DIRECTION_OUTPUT:
			{
				SET_BIT(*ddr_register[port_type],pin_type);
				break;
			}
			default:break;
		}
		
		ret=R_OK;
	}
	return ret;
}
/**
 * @brief initialize port direction to be input or output
 * @param port
 * @param direction
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_port_direction_initialize(enum_port_type port_type,enum_direction_type direction_type)
{
	ret_status ret=R_NOK;
	if((port_type<PORT_INVALID)&&(direction_type<DIRECTION_INVALID))
	{
		switch(direction_type)
		{
			case DIRECTION_INPUT:
			{
				*ddr_register[port_type]=PORT_DIRECTION_INPUT;
				break;
			}
			case DIRECTION_OUTPUT:
			{
				*ddr_register[port_type]=PORT_DIRECTION_OUTPUT;
				break;
			}
			default:break;

		}
				
		ret=R_OK;
	}
	else
	{
		return ret;
	}
return ret;
}
/**
 * @brief get pin direction status to the pointer direction_type
 * @param port
 * @param pin
 * @param direction
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_pin_get_direction_status(enum_port_type port_type, enum_pin_type pin_type,enum_direction_type* direction_type)
{
	ret_status ret=R_NOK;
	if((port_type<PORT_INVALID)&&(pin_type<PIN_INVALID)&&(direction_type!=NULL_POINTER))
	{
		*direction_type=READ_BIT(*ddr_register[port_type],pin_type);
		ret=R_OK;
	}
	else
	{
		return ret;
	}
return ret;
}
/**
 * @brief get port direction status to the pointer direction_type
 * @param port
 * @param direction
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_port_get_direction_status(enum_port_type port_type,uint8_type* direction_type)
{
	ret_status ret =R_OK;
	if((port_type<PORT_INVALID)&&(direction_type!=NULL_POINTER))
	{
		*direction_type=*ddr_register[port_type];
		ret=R_OK;
	}
	else
	{
		return ret;
	}
return ret; 	
}
/**
 * @brief set pin 
 * @param port
 * @param pin
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_set_pin(enum_port_type port_type, enum_pin_type pin_type){
	ret_status ret=R_NOK;
	if((port_type<PORT_INVALID)&&(pin_type<PIN_INVALID))
	{
		SET_BIT(*port_register[port_type],pin_type);
		ret =R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
/**
 * @brief set port 
 * @param port
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_set_port(enum_port_type port_type){
	ret_status ret=R_NOK;
	if(port_type<PORT_INVALID)
	{
		SET_PORT(port_type);
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
/**
 * @brief clear pin
 * @param port
 * @param pin
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_clear_pin(enum_port_type port_type, enum_pin_type pin_type){
	ret_status ret=R_NOK;
	if((port_type<PORT_INVALID)&&(pin_type<PIN_INVALID))
	{
		CLEAR_BIT(*port_register[port_type],pin_type);
		ret =R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
/**
 * @brief clear port
 * @param port
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_clear_port(enum_port_type port_type){
	ret_status ret=R_NOK;
	if(port_type<PORT_INVALID)
	{
		CLEAR_PORT(port_type);
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
/**
 * @brief toggle pin
 * @param port
 * @param pin
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_toggle_pin(enum_port_type port_type, enum_pin_type pin_type){
	ret_status ret=R_NOK;
	if((port_type<PORT_INVALID)&&(pin_type<PIN_INVALID))
	{
		TOGGLE_BIT(*port_register[port_type],pin_type);
		ret =R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
/**
 * @brief toggle port
 * @param port
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_toggle_port(enum_port_type port_type){
	ret_status ret=R_NOK;
	if(port_type<PORT_INVALID)
	{
		TOGGLE_PORT(port_type);
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
/**
 * @brief read pin value
 * @param port
 * @param pin
 * @param logic
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_read_pin(enum_port_type port_type, enum_pin_type pin_type, enum_pin_value_type* ptr_uint8_pin_value){
	ret_status ret=R_NOK;
	if((port_type<PORT_INVALID)&&(pin_type<PIN_INVALID)&&(ptr_uint8_pin_value!=NULL_POINTER))
	{
		*ptr_uint8_pin_value=READ_BIT(*pin_register[port_type],pin_type);
		ret =R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
/**
 * @brief read port value
 * @param port
 * @param value
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_read_port(enum_port_type port_type, uint8_type* ptr_uint8_port_value){
	ret_status ret=R_NOK;
	if((port_type<PORT_INVALID)&& (ptr_uint8_port_value!=NULL_POINTER))
	{
		*ptr_uint8_port_value=*pin_register[port_type];
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
/**
 * @brief write value on port 
 * @param port
 * @param value
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_write_port(enum_port_type port_type,uint8_type value){
	ret_status ret=R_NOK;
	if(port_type<PORT_INVALID)
	{
		*port_register[port_type]=value;
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
/**
 * @brief write pin value (high or low)
 * @param port
 * @param pin
 * @param logic
 * @return Status of the function
 *       (R_OK) : The function done successfully
 */
ret_status gpio_write_pin(enum_port_type port_type,enum_pin_type pin_type,enum_pin_value_type pin_value_type)
{
	ret_status ret=R_NOK;
	if((port_type<PORT_INVALID)&&(pin_type<PIN_INVALID)&&(pin_value_type<VALUE_INVALID))
	{
		switch(pin_value_type)
		{	case VALUE_LOW:
			{
				CLEAR_BIT(*port_register[port_type],pin_type);
				break;
			}
			case VALUE_HIGH:
			{
				SET_BIT(*port_register[port_type],pin_type);
				break;
			}
			default:break;
		}
		
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}

