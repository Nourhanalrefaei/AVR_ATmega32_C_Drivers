/*
 * hal_7_Segment.c
 *
 * Created: 2/21/2022 12:12:08 PM
 *  Author: NourhanAlrefaei
 */ 
#include "hal_7_Segment.h"

static uint8_type common_anode_values[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
static uint8_type common_cathode_values[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void seven_segment_direct_connection_initialize(const segment_t *_seg){
	gpio_port_direction_initialize(_seg->port, PORT_DIRECTION_OUTPUT);
	gpio_write_port(_seg->port,PORT_ALL_OFF);
}

void seven_segment_direct_connection_write_number(const segment_t *_seg, uint8_type value){
	if(_seg->type == COMMON_ANODE){
		gpio_write_port(_seg->port, common_anode_values[value]);
	}
	else{
		gpio_write_port(_seg->port, common_cathode_values[value]);
	}
}