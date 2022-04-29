/*
 * hal_char_lcd.c
 *
 * Created: 2/16/2022 4:59:15 PM
 *  Author: NourhanAlrefaei
 */ 
#include "hal_char_lcd.h"

#if CHAR_LCD_MODE==4
static void lcd_4bit_lcd_initialize(const char_lcd_t* _lcd)
{
	gpio_pin_direction_initialize(_lcd->lcd_en_port,_lcd->lcd_en_pin,DIRECTION_OUTPUT);
	gpio_pin_direction_initialize(_lcd->lcd_rs_port,_lcd->lcd_rs_pin,DIRECTION_OUTPUT);
	gpio_pin_direction_initialize(_lcd->lcd_rw_port,_lcd->lcd_rw_pin,DIRECTION_OUTPUT);
	gpio_pin_direction_initialize(_lcd->lcd_data_port,_lcd->lcd_data_pin4,DIRECTION_OUTPUT);
	gpio_pin_direction_initialize(_lcd->lcd_data_port,_lcd->lcd_data_pin5,DIRECTION_OUTPUT);
	gpio_pin_direction_initialize(_lcd->lcd_data_port,_lcd->lcd_data_pin6,DIRECTION_OUTPUT);
	gpio_pin_direction_initialize(_lcd->lcd_data_port,_lcd->lcd_data_pin7,DIRECTION_OUTPUT);
	_delay_ms(40);
	gpio_write_pin(_lcd->lcd_en_port,_lcd->lcd_en_pin,VALUE_LOW);
	gpio_write_pin(_lcd->lcd_rs_port,_lcd->lcd_rs_pin,VALUE_LOW);
	gpio_write_pin(_lcd->lcd_rw_port,_lcd->lcd_rw_pin,VALUE_LOW);
	gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin4,VALUE_HIGH);
	gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin5,VALUE_HIGH);
	gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin6,VALUE_LOW);
	gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin7,VALUE_LOW);
	lcd_send_enable(_lcd);
	_delay_ms(5);
	gpio_write_pin(_lcd->lcd_en_port,_lcd->lcd_en_pin,VALUE_LOW);
	gpio_write_pin(_lcd->lcd_rs_port,_lcd->lcd_rs_pin,VALUE_LOW);
	gpio_write_pin(_lcd->lcd_rw_port,_lcd->lcd_rw_pin,VALUE_LOW);
	gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin4,VALUE_HIGH);
	gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin5,VALUE_HIGH);
	gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin6,VALUE_LOW);
	gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin7,VALUE_LOW);
	lcd_send_enable(_lcd);
	_delay_us(150);
	gpio_write_pin(_lcd->lcd_en_port,_lcd->lcd_en_pin,VALUE_LOW);
	gpio_write_pin(_lcd->lcd_rs_port,_lcd->lcd_rs_pin,VALUE_LOW);
	gpio_write_pin(_lcd->lcd_rw_port,_lcd->lcd_rw_pin,VALUE_LOW);
	gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin4,VALUE_HIGH);
	gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin5,VALUE_HIGH);
	gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin6,VALUE_LOW);
	gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin7,VALUE_LOW);
	lcd_send_enable(_lcd);
	
	lcd_send_command(_lcd,_LCD_CLEAR);
	_delay_ms(1);
	lcd_send_command(_lcd,_LCD_RETURN_HOME);
	_delay_ms(1);
	lcd_send_command(_lcd,_LCD_ENTRY_MODE);
	_delay_ms(1);
	lcd_send_command(_lcd,_LCD_CURSOR_OFF_DISPLAY_ON);
	_delay_ms(1);
	lcd_send_command(_lcd,_LCD_CURSOR_DISPLAY_SHIFT_RIGHT);
	_delay_ms(1);
	lcd_send_command(_lcd,_LCD_4BIT_MODE_2LINE);
	_delay_ms(1);
	lcd_send_command(_lcd,_LCD_DDRAM_START);
	_delay_ms(1);
}

#endif

#if CHAR_LCD_MODE==8
static void lcd_8bit_lcd_initialize(const char_lcd_t* _lcd)
{
	gpio_port_direction_initialize(_lcd->lcd_data_port,PORT_DIRECTION_OUTPUT);
	gpio_write_port(_lcd->lcd_data_port,PORT_ALL_CLEAR);
	gpio_pin_direction_initialize(_lcd->lcd_en_port,_lcd->lcd_en_pin,DIRECTION_OUTPUT);
	gpio_write_pin(_lcd->lcd_en_port,_lcd->lcd_en_pin,VALUE_LOW);
	gpio_pin_direction_initialize(_lcd->lcd_rs_port,_lcd->lcd_rs_pin,DIRECTION_OUTPUT);
	gpio_write_pin(_lcd->lcd_rs_port,_lcd->lcd_rs_pin,VALUE_LOW);
	
}
#endif

static ret_status lcd_send_enable(const char_lcd_t* _lcd)
{
	ret_status ret=R_NOK;
	if(_lcd!=NULL_POINTER)
	{
		#if CHAR_LCD_MODE==8
			gpio_write_pin(_lcd->lcd_en_port,_lcd->lcd_en_pin,VALUE_HIGH);
			_delay_ms(200);
			gpio_write_pin(_lcd->lcd_en_port,_lcd->lcd_en_pin,VALUE_LOW);
		#elif CHAR_LCD_MODE==4
			gpio_write_pin(_lcd->lcd_en_port,_lcd->lcd_en_pin,VALUE_HIGH);
			_delay_ms(200);
			gpio_write_pin(_lcd->lcd_en_port,_lcd->lcd_en_pin,VALUE_LOW);
		#endif
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}

ret_status lcd_initialize(const char_lcd_t* _lcd)
{
	ret_status ret=R_NOK;
	if(_lcd !=NULL_POINTER)
	{
		#if CHAR_LCD_MODE==8
			lcd_8bit_lcd_initialize(_lcd);
		#elif CHAR_LCD_MODE==4
			lcd_4bit_lcd_initialize(_lcd);
		#endif
		
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}

#if CHAR_LCD_MODE==4
static ret_status lcd_send_4bits(const char_lcd_t* _lcd,uint8_type data)
{
	ret_status ret =R_NOK;
	if(_lcd !=NULL_POINTER)
	{
		gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin4,((data>>0)&0x1));
		gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin5,((data>>1)&0x1));
		gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin6,((data>>2)&0x1));
		gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_data_pin7,((data>>3)&0x1));
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;	
}
#endif
ret_status lcd_send_command(const char_lcd_t* _lcd,uint8_type command)
{
	ret_status ret=R_NOK;
	if(_lcd !=NULL_POINTER)
	{
		#if CHAR_LCD_MODE==8
			gpio_write_pin(_lcd->lcd_data_port,_lcd->lcd_rs_pin,VALUE_LOW);
			gpio_write_port(_lcd->lcd_data_port,command);
			lcd_send_enable(_lcd);
		#elif CHAR_LCD_MODE==4
			gpio_write_pin(_lcd->lcd_rs_port,_lcd->lcd_rs_pin,VALUE_LOW);
			lcd_send_4bits(_lcd,command>>4);
			lcd_send_enable(_lcd);
			lcd_send_4bits(_lcd,command&0x0F);
			lcd_send_enable(_lcd);
			_delay_ms(2);
		#endif
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
ret_status lcd_send_char_data(const char_lcd_t* _lcd,uint8_type _data)
{
	ret_status ret=R_NOK;
	if(_lcd !=NULL_POINTER)
	{
		#if CHAR_LCD_MODE==8
		gpio_write_pin(_lcd->lcd_rs_port,_lcd->lcd_rs_pin,VALUE_HIGH);
		gpio_write_port(_lcd->lcd_data_port,_data);
		lcd_send_enable(_lcd);
		#elif CHAR_LCD_MODE==4
		gpio_write_pin(_lcd->lcd_rs_port,_lcd->lcd_rs_pin,VALUE_HIGH);
		lcd_send_4bits(_lcd,_data>>4);
		lcd_send_enable(_lcd);
		lcd_send_4bits(_lcd,_data&0x0F);
		lcd_send_enable(_lcd);
		#endif
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
ret_status lcd_clear_display(const char_lcd_t* _lcd)
{
	ret_status ret=R_NOK;
	if(_lcd !=NULL_POINTER)
	{
		lcd_send_command(_lcd,_LCD_CLEAR);
		ret=R_OK;
	}
	else
	{
		return ret;
	}
	return ret;
}
static void lcd_set_cursor(const char_lcd_t *_lcd, uint8_type row, uint8_type coulmn){
	coulmn--;
	switch(row){
		case 1 : lcd_send_command(_lcd, (0x80 + coulmn)); break;
		case 2 : lcd_send_command(_lcd, (0xC0 + coulmn)); break;
		case 3 : lcd_send_command(_lcd, (0x94 + coulmn)); break;
		case 4 : lcd_send_command(_lcd, (0xD4 + coulmn)); break;
		default : ;
	}
}
ret_status lcd_send_char_data_pos(const char_lcd_t *_lcd, uint8_type row, uint8_type coulmn, uint8_type _data){
	ret_status ret = R_NOK;
	if(NULL_POINTER == _lcd){
		return ret;
	}
	else{
		lcd_send_command(_lcd, _LCD_RETURN_HOME);
		lcd_set_cursor(_lcd, row, coulmn);
		lcd_send_char_data(_lcd, _data);
		ret = R_OK;
	}
	return ret;
}
ret_status lcd_send_string_data_pos(const char_lcd_t *_lcd, uint8_type row, uint8_type coulmn, uint8_type *_data){
	ret_status ret = R_NOK;
	if(NULL_POINTER != _lcd){
		lcd_send_command(_lcd, _LCD_RETURN_HOME);
		lcd_set_cursor(_lcd, row, coulmn);
		while(*_data){
			lcd_send_char_data(_lcd, *_data++);
			_delay_ms(1);
			ret = R_OK;
		}
	}
	else{
			return ret;
		}
		
	return ret;
}
ret_status lcd_send_string_data_current_pos(const char_lcd_t *_lcd, uint8_type *_data){
	ret_status ret = R_NOK;
	if(NULL_POINTER != _lcd){
		while(*_data){
			lcd_send_char_data(_lcd, *_data++);
			_delay_ms(1);
		}
		ret = R_OK;
	}
	else{
		return ret;
	}
	return ret;
}
ret_status lcd_send_custome_char(const char_lcd_t *_lcd, uint8_type row, uint8_type coulmn, const char arr[], uint8_type _pos){
	ret_status ret = R_NOK;
	uint8_type l_counter = ZERO_INIT;
	if(NULL_POINTER != _lcd){
		lcd_send_command(_lcd, _LCD_CGRAM_START+(_pos*8));
		lcd_send_command(_lcd, _LCD_RETURN_HOME);
		lcd_send_char_data_pos(_lcd, row, coulmn, _pos);
		for(l_counter=0; l_counter<=7; l_counter++){
			lcd_send_char_data(_lcd, arr[l_counter]);
		}
		
		ret = R_OK;
	}
	else{
		return ret;
	}
	return ret;
}
void byte_to_string(uint8_type number, uint8_type *_output){
	sprintf(_output, "%i", number);
}

void short_to_string(uint16_type number, uint8_type *_output){
	sprintf(_output, "%i", number);
}

void int_to_string(uint32_type number, uint8_type *_output){
	sprintf(_output, "%i", number);
}