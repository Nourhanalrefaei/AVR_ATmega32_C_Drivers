/*
 * mcal_gpio.h
 *
 * Created: 2/2/2022 11:46:52 AM
 *  Author: NourhanAlrefaei
 */ 


#ifndef MCAL_GPIO_H_
#define MCAL_GPIO_H_
#include "../../common_types.h"
#include "../../device_config.h"

/*Section:Macro Decelerations*/
#define  PIN_MASK_VALUE                 (1U)
#define  PORT_MASK_VALUE                (0xFFU)
#define  PORT_DIRECTION_INPUT           (0x00U)
#define  PORT_DIRECTION_OUTPUT          (0xFFU)
#define  PORT_ALL_CLEAR                 (0x00)
#define  PORT_ALL_OFF                   (0x00)

/*Section Macro Functions Decelerations*/
#define CLEAR_BIT(REG,PIN_POS)          (REG &= ~(PIN_MASK_VALUE <<PIN_POS))
#define SET_BIT(REG,PIN_POS)            (REG |= (PIN_MASK_VALUE <<PIN_POS))
#define TOGGLE_BIT(REG,PIN_POS)         (REG ^= (PIN_MASK_VALUE <<PIN_POS))
#define READ_BIT(REG,PIN_POS)           (REG=((REG>>PIN_POS)&PIN_MASK_VALUE))
#define SET_PORT(PORT_VALUE)            (PORT_VALUE |= PORT_MASK_VALUE)
#define CLEAR_PORT(PORT_VALUE)          (PORT_VALUE &= ~PORT_MASK_VALUE)
#define TOGGLE_PORT(PORT_VALUE)         (PORT_VALUE ^= PORT_MASK_VALUE)

/*Section:Data Type Definitions*/
typedef enum
{
	PORT_A = 0,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_INVALID,
}enum_port_type;

typedef enum
{
	PIN_0 = 0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_INVALID,
}enum_pin_type;

typedef enum
{
	DIRECTION_INPUT = 0,
	DIRECTION_OUTPUT,
	DIRECTION_INVALID,
}enum_direction_type;

typedef enum
{
	NO_PULL = 0,
	PULL_UP,
	PULL_INVALID,
}enum_pull_type;

typedef enum
{
	VALUE_LOW = 0,
	VALUE_HIGH,
	VALUE_INVALID,
}enum_pin_value_type;


ret_status gpio_pin_direction_initialize(enum_port_type port_type,enum_pin_type pin_type, enum_direction_type direction_type);
ret_status gpio_port_direction_initialize(enum_port_type port_type,enum_direction_type direction_type);
ret_status gpio_pin_get_direction_status(enum_port_type port_type, enum_pin_type pin_type,enum_direction_type* direction_type);
ret_status gpio_port_get_direction_status(enum_port_type port_type,uint8_type* direction_type);
ret_status gpio_set_pin(enum_port_type port_type, enum_pin_type pin_type);
ret_status gpio_set_port(enum_port_type port_type);
ret_status gpio_clear_pin(enum_port_type port_type, enum_pin_type pin_type);
ret_status gpio_clear_port(enum_port_type port_type);
ret_status gpio_toggle_pin(enum_port_type port_type, enum_pin_type pin_type);
ret_status gpio_toggle_port(enum_port_type port_type);
ret_status gpio_read_pin(enum_port_type port_type, enum_pin_type pin_type, enum_pin_value_type* ptr_uint8_pin_value);
ret_status gpio_read_port(enum_port_type port_type,uint8_type* ptr_uint8_port_value);
ret_status gpio_write_port(enum_port_type port_type,uint8_type value);
ret_status gpio_write_pin(enum_port_type port_type,enum_pin_type pin_type,enum_pin_value_type pin_value_type);
#endif /* MCAL_GPIO_H_ */