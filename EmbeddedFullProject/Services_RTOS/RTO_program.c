/*
 * RTO_program.c
 *
 * Created: 4/20/2022 3:09:23 PM
 *  Author: NourhanAlrefaei
 */ 
#include "RTO_interface.h"
#include "RTO_config.h"
#include "RTO_private.h"

Task_TCB Tasks[RTO_NUM_OF_TASKS];


void RTO_voidInit(void)
{
	/*Initialize Timer_0*/
	Timer_0_init();
	/**/
	Timer_0_SetOverFlowCallBack(RTO_voidSchedular);
}
void RTO_voidStart(void)
{
	/*Start Timer_0*/
	Timer_0_Start();
	/*Start Timer0 and enter Timer0 ISR every Tick time*/
	Timer_0_set_time_ms(RTO_TICK_TIME);
}

void RTO_voidCreate_task(uint8_type copy_u8_priority,uint16_type copy_u16_periodicity,uint16_type copy_u16_first_delay,void(*copy_ptr_to_function)(void))
{
	Tasks[copy_u8_priority].periodicity=copy_u16_periodicity;
	Tasks[copy_u8_priority].first_delay=copy_u16_first_delay;
	Tasks[copy_u8_priority].ptr_to_func=copy_ptr_to_function;
}
static void RTO_voidSchedular(void)
{
	uint8_type counter=ZERO_INIT;
	/*Loop all tasks in queue*/
	for(counter=0;counter<RTO_NUM_OF_TASKS;counter++)
	{
		if(Tasks[counter].first_delay==0)
		{
			/*Call Function*/
			Tasks[counter].ptr_to_func();
			Tasks[counter].first_delay=Tasks[counter].periodicity-1;
		}
		else
		{
			Tasks[counter].first_delay--;
		}
	}
}