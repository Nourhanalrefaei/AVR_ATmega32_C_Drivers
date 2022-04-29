/*
 * hal_keybad.h
 *
 * Created: 2/18/2022 2:01:54 PM
 *  Author: NourhanAlrefaei
 */ 


#ifndef HAL_KEYBAD_H_
#define HAL_KEYBAD_H_
#include "../../mcal/gpio/mcal_gpio.h"

#define  KEYPAD_ROWs          4
#define  KEYPAD_COLUMNS       4


typedef struct{
	uint8_type port_name:     4;
	uint8_type pin_name:      4;
}keypad_pin_t;

typedef struct {
	keypad_pin_t keypad_raws[KEYPAD_ROWs];
	keypad_pin_t keypad_columns[KEYPAD_COLUMNS];
}keypad_t;


ret_status keypad_initialize(const keypad_t* _keypad);
uint8_type keypad_read_value(const keypad_t *_keypad);

#endif /* HAL_KEYBAD_H_ */