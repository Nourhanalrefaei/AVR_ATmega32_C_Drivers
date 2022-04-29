/*
 * adc_types.h
 *
 * Created: 3/6/2022 12:25:30 PM
 *  Author: NourhanAlrefaei
 */ 


#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

/*ADC Voltage Select*/
#define ADC_VREF_CLR_MSK               0x3F
#define ADC_VREF_AREF                  0x00
#define ADC_VREF_AVCC                  0x40
#define ADC_VREF_2_56V                 0xC0

/*ADC Mode Select*/
#define ADC_MODE_AUTO_TRIGGER          1
#define ADC_MODE_SINGLE_CONVERSION     0

/*ADC Adjust Select*/
#define ADC_RIGHT_ADJUSTED             0
#define ADC_LEFT_ADJUSTED              1

/*ADC Prescaler Select*/
#define ADC_PRESCALER_CLR_MSK          0xF8
#define ADC_PRESCALER_2_MSK            0x00
#define ADC_PRESCALER_4_MSK            0x02
#define ADC_PRESCALER_8_MSK            0x03
#define ADC_PRESCALER_16_MSK           0x04
#define ADC_PRESCALER_32_MSK           0x05
#define ADC_PRESCALER_64_MSK           0x06
#define ADC_PRESCALER_128_MSK          0x07

/*ADC Auto Trigger Select*/
#define ADC_AUTO_TRIGGER_SRC_CLR_MSK                    0x1F
#define ADC_AUTO_TRIGGER_SRC_FREE_RUNNING_MSK           0x00
#define ADC_AUTO_TRIGGER_SRC_ANALOG_COMP_MSK            0x20
#define ADC_AUTO_TRIGGER_SRC_EXIT0_MSK                  0x40
#define ADC_AUTO_TRIGGER_SRC_TIMER0_COMP_MSK            0x60
#define ADC_AUTO_TRIGGER_SRC_TIMER0_OVF_MSK             0x80
#define ADC_AUTO_TRIGGER_SRC_TIMER1_COMP_MSK            0xA0
#define ADC_AUTO_TRIGGER_SRC_TIMER1_OVF_MSK             0xC0
#define ADC_AUTO_TRIGGER_SRC_TIMER1_CAPT_MSK            0xE0

/*ADC Mask to Clear Channel*/
#define ADC_CLEATR_CHANNEL_MASK                         0xE0
#endif /* ADC_TYPES_H_ */