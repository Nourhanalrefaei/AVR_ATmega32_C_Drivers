/*
* application.c
*
* Created: 2/2/2022 10:05:57 AM
*  Author: NourhanAlrefaei
*/

#define F_CPU 16000000UL
#include "application.h"
uint32_type freq_messure=ZERO_INIT;
uint8_type* freq_measure_str;
char_lcd_t lcd1={.lcd_en_port=PORT_B,.lcd_en_pin=PIN_3,
				 .lcd_rs_port=PORT_B,.lcd_rs_pin=PIN_1,
				 .lcd_rw_port=PORT_B,.lcd_rw_pin=PIN_2,
				 .lcd_data_port=PORT_A,.lcd_data_pin4=PIN_4,
				 .lcd_data_pin5=PIN_5,.lcd_data_pin6=PIN_6,
				 .lcd_data_pin7=PIN_7};
				 
button_t btn1={.port_type=PORT_B,.pin_type=PIN_0,.button_stat=BUTTON_NOT_PRESSED};
int main(void)
{
	application_init();

	while(1)
	{
		//lcd_send_string_data_pos(&lcd1,0,0,"Freq:");
		int_to_string(freq_messure,freq_measure_str);
		lcd_send_string_data_pos(&lcd1,0,0,freq_measure_str);
		if(btn1.button_stat==BUTTON_PRESSED)
		{
			gpio_set_pin(PORT_D,PIN_6);
		}
		else
		{
			gpio_clear_pin(PORT_D,PIN_6);
		}
	}
	return 0;
}

void application_init(void)
{
	lcd_initialize(&lcd1);	button_init(&btn1);	Timer_1_init();	Timer_1_InputCapture_init();	Timer_1_InputCapture_Start();	Timer_1_set_InputCapture_Callback(Timer_1_ISR);
}

void Timer_1_ISR(void)
{
	Timer_1_Cap_calculate(&freq_messure);

}


