/*
 * GIE.h
 *
 * Created: 3/8/2022 4:55:03 PM
 *  Author: NourhanAlrefaei
 */ 


#ifndef GIE_H_
#define GIE_H_
#include "../gpio/mcal_gpio.h"
#include "GIE_Types.h"

/*Function to Enable Global Interrupt*/
void GIE_Enable(void);

/*Function to Disable Global Interrupt*/
void GIE_Disnable(void);

#endif /* GIE_H_ */