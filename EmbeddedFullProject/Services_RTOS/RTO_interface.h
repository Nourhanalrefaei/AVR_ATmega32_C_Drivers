/*
 * RTO_interface.h
 *
 * Created: 4/20/2022 3:06:46 PM
 *  Author: NourhanAlrefaei
 */ 


#ifndef RTO_INTERFACE_H_
#define RTO_INTERFACE_H_

#include "../mcal/Timers/Timer_0.h"

void RTO_voidInit(void);
void RTO_voidStart(void);
void RTO_voidCreate_task(uint8_type copy_u8_priority,uint16_type copy_u16_periodicity,uint16_type copy_u16_first_delay,void(*copy_ptr_to_function)(void));


#endif /* RTO_INTERFACE_H_ */