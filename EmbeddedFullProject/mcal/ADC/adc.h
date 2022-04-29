/*
 * hal_adc.h
 *
 * Created: 3/1/2022 8:29:07 PM
 *  Author: NourhanAlrefaei
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "../gpio/mcal_gpio.h"
#include "adc_config.h"
#include "adc_types.h"


typedef enum{
	ADC_CHANNEL_0,
	ADC_CHANNEL_1,
	ADC_CHANNEL_2,
	ADC_CHANNEL_3,
	ADC_CHANNEL_4,
	ADC_CHANNEL_5,
	ADC_CHANNEL_6,
	ADC_CHANNEL_7
}ADC_chunnel_types;

void adc_init(ADC_chunnel_types channel_num);
void adc_start_conversion(ADC_chunnel_types channel_num);
uint16_type adc_read_value(void);

/*Function to Enable ADC ISR*/
void ADC_enableInt(void);

/*Function to Disable ADC ISR*/
void ADC_disableInt(void);

/*Call Back Function*/
void ADC_setCallBack(void(*CopyFunctionPtr)(void));
void __vector_16(void) __attribute__ ((signal,used));

#endif /* ADC_H_ */