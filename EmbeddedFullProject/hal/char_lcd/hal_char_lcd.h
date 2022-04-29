/*
 * hal_char_lcd.h
 *
 * Created: 2/16/2022 4:59:51 PM
 *  Author: NourhanAlrefaei
 */ 

#ifndef HAL_CHAR_LCD_H_
#define HAL_CHAR_LCD_H_
/*Section:include*/
#include "../../mcal/gpio/mcal_gpio.h"

/*Section:Macro Decelerations*/
#define CHAR_LCD_MODE                        4 
/*********LCD Commands*********/
#define _LCD_CLEAR                           0X01
#define _LCD_RETURN_HOME                     0x02
#define _LCD_ENTRY_MODE                      0X06
#define _LCD_CURSOR_OFF_DISPLAY_ON           0x0C
#define _LCD_CURSOR_OFF_DISPLAY_OFF          0x08
#define _LCD_CURSOR_ON_BLINK_ON              0x0F 
#define _LCD_CURSOR_ON_BLINK_OFF             0x0E
#define _LCD_CURSOR_DISPLAY_SHIFT_RIGHT      0x1C
#define _LCD_CURSOR_DISPLAY_SHIFT_LEFT       0x18
#define _LCD_8BIT_MODE_2LINE                 0x38
#define _LCD_4BIT_MODE_2LINE                 0x28
#define _LCD_CGRAM_START                     0x40
#define _LCD_DDRAM_START                     0x80



/*Section:Data Type Definition*/
typedef struct{
	#if CHAR_LCD_MODE==8
	uint8_type lcd_data_port   :             4;
	uint8_type lcd_en_port     :             4;
	uint8_type lcd_rs_port     :             4;
	uint8_type lcd_en_pin      :             3;
	uint8_type lcd_rs_pin      :             3;
	uint8_type reserved        :             6;
	
	#elif CHAR_LCD_MODE==4
	uint8_type lcd_data_port   :             4;
	uint8_type lcd_en_port     :             4;
	uint8_type lcd_rs_port     :             4;
	uint8_type lcd_rw_port     :             4;
	uint8_type lcd_data_pin4   :             3;
	uint8_type lcd_data_pin5   :             3;
	uint8_type lcd_data_pin6   :             3;
	uint8_type lcd_data_pin7   :             3;
	uint8_type lcd_en_pin      :             3;
	uint8_type lcd_rs_pin      :             3;
	uint8_type lcd_rw_pin      :             3;
	uint8_type reserved        :             3;
	#else
	#error "LCD Mode Not Valid!!"
	#endif
	
}char_lcd_t; 

/*Section Function Declarations*/
ret_status lcd_initialize(const char_lcd_t* _lcd);
ret_status lcd_send_command(const char_lcd_t* _lcd,uint8_type command);
ret_status lcd_send_char_data(const char_lcd_t* _lcd,uint8_type _data);
ret_status lcd_clear_display(const char_lcd_t* _lcd);
static void lcd_4bit_lcd_initialize(const char_lcd_t* _lcd);
static void lcd_8bit_lcd_initialize(const char_lcd_t* _lcd);
static ret_status lcd_send_enable(const char_lcd_t* _lcd);
static ret_status lcd_send_4bits(const char_lcd_t* _lcd,uint8_type data);
static void lcd_set_cursor(const char_lcd_t *_lcd, uint8_type row, uint8_type coulmn);
ret_status lcd_send_char_data_pos(const char_lcd_t *_lcd, uint8_type row, uint8_type coulmn, uint8_type _data);
ret_status lcd_send_string_data_pos(const char_lcd_t *_lcd, uint8_type row, uint8_type coulmn, uint8_type *_data);
ret_status lcd_send_string_data_current_pos(const char_lcd_t *_lcd, uint8_type *_data);
void byte_to_string(uint8_type number, uint8_type *_output);
void short_to_string(uint16_type number, uint8_type *_output);
void int_to_string(uint32_type number, uint8_type *_output);
ret_status lcd_send_char_data_pos(const char_lcd_t *_lcd, uint8_type row, uint8_type coulmn, uint8_type _data);

#endif /* HAL_CHAR_LCD_H_ */