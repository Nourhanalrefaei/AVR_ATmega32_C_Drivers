/*
 * hal_keybad.c
 *
 * Created: 2/18/2022 2:02:40 PM
 *  Author: NourhanAlrefaei
 */ 
#include "hal_keybad.h"

static uint8_type btn_values[KEYPAD_ROWs][KEYPAD_COLUMNS]={
															{'1','2','3','A'},
															{'4','5','6','B'},
															{'7','8','9','C'},
															{'*','0','#','D'}
                                                          };
ret_status keypad_initialize(const keypad_t* _keypad)
{
	uint8_type l_counter=ZERO_INIT;
	ret_status ret=R_NOK;
	if(_keypad!=NULL_POINTER)
	{
		for(l_counter;l_counter<KEYPAD_ROWs;l_counter++)
		{
			gpio_pin_direction_initialize(_keypad->keypad_raws[l_counter].port_name,_keypad->keypad_raws[l_counter].pin_name,DIRECTION_OUTPUT);
			gpio_write_pin(_keypad->keypad_raws[l_counter].port_name,_keypad->keypad_raws[l_counter].pin_name,VALUE_LOW);
		}
		for(l_counter;l_counter<KEYPAD_COLUMNS;l_counter++)
		{
			gpio_pin_direction_initialize(_keypad->keypad_columns[l_counter].port_name,_keypad->keypad_columns[l_counter].pin_name,DIRECTION_INPUT);
		}
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
uint8_type keypad_read_value(const keypad_t *_keypad){
	uint8_type l_row_counter = ZERO_INIT, l_col_counter = ZERO_INIT, l_counter = ZERO_INIT;
	enum_pin_value_type logic = VALUE_LOW;
	for(l_row_counter=ZERO_INIT; l_row_counter<KEYPAD_ROWs; l_row_counter++){
		for(l_counter=ZERO_INIT; l_counter<KEYPAD_ROWs; l_counter++){
			gpio_write_pin(_keypad->keypad_raws[l_counter].port_name, _keypad->keypad_raws[l_counter].pin_name, VALUE_LOW);
		}
		gpio_write_pin(_keypad->keypad_raws[l_row_counter].port_name, _keypad->keypad_raws[l_row_counter].pin_name, VALUE_HIGH);
		_delay_ms(10);
		for(l_col_counter=ZERO_INIT; l_col_counter<KEYPAD_COLUMNS; l_col_counter++){
			gpio_read_pin(_keypad->keypad_columns[l_col_counter].port_name, _keypad->keypad_columns[l_col_counter].pin_name, &logic);
			if(VALUE_HIGH == logic){
				while(VALUE_HIGH == logic){
					gpio_read_pin(_keypad->keypad_columns[l_col_counter].port_name, _keypad->keypad_columns[l_col_counter].pin_name, &logic);
				}
				return btn_values[l_row_counter][l_col_counter];
			}
		}
	}
	return 0;
}
