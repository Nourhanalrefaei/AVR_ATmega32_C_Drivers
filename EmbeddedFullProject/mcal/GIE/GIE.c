/*
 * GIE.c
 *
 * Created: 3/8/2022 4:54:45 PM
 *  Author: NourhanAlrefaei
 */ 
#include "GIE.h"

/*Function to Enable Global Interrupt*/
void GIE_Enable(void)
{
	SET_BIT(REG_SREG,GIE_ENABLE_BIT);
}

/*Function to Disable Global Interrupt*/
void GIE_Disnable(void)
{
	CLEAR_BIT(REG_SREG,GIE_ENABLE_BIT);
}
