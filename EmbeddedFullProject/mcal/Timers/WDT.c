/*
 * WDT.c
 *
 * Created: 4/20/2022 11:33:39 AM
 *  Author: NourhanAlrefaei
 */ 
#include "WDT.h"

void WDT_INIT(void)
{
	SET_BIT(REG_WDTCR,3);
	SET_BIT(REG_WDTCR,0);
	SET_BIT(REG_WDTCR,1);
	SET_BIT(REG_WDTCR,2);
}
void WDT_REFRESH(void)
{
	asm("WDR");
}
