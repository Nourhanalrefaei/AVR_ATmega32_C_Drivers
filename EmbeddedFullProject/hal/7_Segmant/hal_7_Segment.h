/*
 * hal_7_Segment.h
 *
 * Created: 2/21/2022 12:12:44 PM
 *  Author: NourhanAlrefaei
 */ 


#ifndef HAL_7_SEGMENT_H_
#define HAL_7_SEGMENT_H_
#include "../../mcal/gpio/mcal_gpio.h"


typedef enum{
	COMMON_ANODE,
	COMMON_CATHODE
}segment_type_t;

typedef struct{
	enum_port_type port;
	segment_type_t type;
}segment_t;

void seven_segment_direct_connection_initialize(const segment_t *_seg);
void seven_segment_direct_connection_write_number(const segment_t *_seg, uint8_type value);


#endif /* HAL_7_SEGMENT_H_ */