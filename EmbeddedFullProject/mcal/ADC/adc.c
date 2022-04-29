/*
 * hal_adc.c
 *
 * Created: 3/1/2022 8:28:41 PM
 *  Author: NourhanAlrefaei
 */ 
#include "adc.h"

static void (*adc_call_Back)(void)=NULL_POINTER;

#define REFS_1		7
#define REFS_0		6
#define ADLAR		5
#define ADEN		7

#define ADPS_2		2
#define ADPS_1   	1
#define ADPS_0   	0

#define MUX_0    	0
#define MUX_1    	1
#define MUX_2    	2
#define MUX_3    	3
#define MUX_4    	4

#define ADIE		3
#define ADIF		4

#define ADSC		6

#define ADATE       5


void adc_init(ADC_chunnel_types channel_num)
{
	gpio_pin_direction_initialize(PORT_A, channel_num, DIRECTION_INPUT);
	/***********************Selecting Voltage Reference******************************/
	REG_ADMUX &=ADC_VREF_CLR_MSK;
	REG_ADMUX |= ADC_VREF_SELECTOR_MSK;
	/********************************************************************************/
	/*****************************Selecting ADC Mode*********************************/
	#if ADC_MODE_SELECTOR==ADC_MODE_AUTO_TRIGGER
	SET_BIT(REG_ADCSRA,ADATE);
	REG_SFIOR &=ADC_AUTO_TRIGGER_SRC_CLR_MSK;
	REG_SFIOR |=ADC_TRIGGER_SRC_SELECTOR;
	#elif ADC_MODE_SELECTOR==ADC_MODE_SINGLE_CONVERSION
	CLEAR_BIT(REG_ADCSRA,ADATE);
	#endif


	/********************************************************************************/
	/****************************Selecting Adjustment********************************/
	#if ADC_ADJUSTMENT_SELECTOR==ADC_RIGHT_ADJUSTED
	CLEAR_BIT(REG_ADMUX,ADLAR);
	#elif ADC_ADJUSTMENT_SELECTOR==ADC_LEFT_ADJUSTED
	SET_BIT(REG_ADMUX,ADLAR);
	#endif
	/********************************************************************************/
	/**************************Clearing Interrupt Flag*******************************/
	//CLEAR_BIT(REG_ADCSRA, ADIE);
	//CLEAR_BIT(REG_ADCSRA,ADIF);
	/********************************************************************************/
	/****************************Enabling ADC****************************************/
	SET_BIT(REG_ADCSRA,ADEN);
	/********************************************************************************/
	/****************************Selecting Prescaler*********************************/
	REG_ADCSRA |=ADC_PRESCALER_SELECTOR;
	
}
void adc_start_conversion(ADC_chunnel_types channel_num)
{
	/*************ADC Select Channel***********/
	REG_ADMUX &= ADC_CLEATR_CHANNEL_MASK;
	REG_ADMUX |=channel_num;
	/*************ADC Start Conversion********/
	SET_BIT(REG_ADCSRA,ADSC);
}
uint16_type adc_read_value(void)
{
		#if ADC_MODE_SELECTOR==ADC_MODE_AUTO_TRIGGER
			uint8_type low_value = ZERO_INIT;
			uint16_type high_value = ZERO_INIT;
			uint16_type uint16_adc_value=ZERO_INIT;
			low_value =  REG_ADCL;
			high_value = REG_ADCH;
			#if ADC_ADJUSTMENT_SELECTOR==ADC_RIGHT_ADJUSTED
			uint16_adc_value=low_value | (high_value << 8);
			#elif ADC_ADJUSTMENT_SELECTOR==ADC_LEFT_ADJUSTED
			uint16_adc_value=(low_value>>6) | (high_value >> 6);
			#endif
			return uint16_adc_value;
		#elif ADC_MODE_SELECTOR==ADC_MODE_SINGLE_CONVERSION
			while(REG_ADCSRA& (1<<ADSC));
			uint8_type low_value = ZERO_INIT;
			uint16_type high_value = ZERO_INIT;
			uint16_type uint16_adc_value=ZERO_INIT;
			low_value =  REG_ADCL;
			high_value = REG_ADCH;
			#if ADC_ADJUSTMENT_SELECTOR==ADC_RIGHT_ADJUSTED
			uint16_adc_value=low_value | (high_value << 8);
			#elif ADC_ADJUSTMENT_SELECTOR==ADC_LEFT_ADJUSTED
			uint16_adc_value=(low_value>>6) | (high_value >> 6);
			#endif
			return uint16_adc_value;
		#endif
	
}
/*Function to Enable ADC ISR*/
void ADC_enableInt(void)
{
	SET_BIT(REG_ADCSRA,ADIE);
}

/*Function to Disable ADC ISR*/
void ADC_disableInt(void)
{
	CLEAR_BIT(REG_ADCSRA,ADIE);
}

/*Call Back Function*/
void ADC_setCallBack(void(*CopyFunctionPtr)(void))
{
	adc_call_Back=CopyFunctionPtr;
}
void __vector_16(void)
{
	if(adc_call_Back!=NULL_POINTER)
	{
		adc_call_Back();
	}
	
}	

