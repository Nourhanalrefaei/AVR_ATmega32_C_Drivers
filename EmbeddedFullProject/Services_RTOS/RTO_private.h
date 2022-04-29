/*
 * RTO_private.h
 *
 * Created: 4/20/2022 3:08:49 PM
 *  Author: NourhanAlrefaei
 */ 


#ifndef RTO_PRIVATE_H_
#define RTO_PRIVATE_H_

typedef struct  
{
	uint16_type periodicity;
	uint16_type first_delay;
	void (*ptr_to_func)();
}Task_TCB;

/*only the timer ISR will call this function so it should be static to prevent it from calling anywhere*/
static void RTO_voidSchedular(void);

#endif /* RTO_PRIVATE_H_ */