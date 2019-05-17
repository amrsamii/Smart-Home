#include "Timer.h"

void Periodic_Timer_Init(uint32_t TimerNo)
{	
	//initialize clock for timer0 module
	SYSCTL_RCGCTIMER_R |= 0x00000001; 
	//disable timer before altering settings
	TIMER0_CTL_R &= ~(0x00000001);
	//initialize the configuration register of timer0
	TIMER0_CFG_R = 0x00000000;
	//set the timer mode to be periodic
	TIMER0_TAMR_R |= 0x00000002;
	//choose the timer to be a count-down timer (deassert bit 4)
	TIMER0_TAMR_R &= ~(0x00000010);
	//set the value at which the timer would start counting : TIMER_LOAD_VAL
	TIMER0_TAILR_R = TimerNo-1;
	//enable timer0 match interrupt (assert bit 5)
	TIMER0_TAMR_R |= 0x00000020;
	//enable timer0 time-out interrupt mask
	TIMER0_IMR_R |= 0x00000001;
	//enable interrupt ISR in the nested vector interrupt controller where 19 is the Timer0 IRQn
	NVIC_EN0_R  |= (1<<19);
	//enable the timer and start the counter
	TIMER0_CTL_R |= 0x00000001;
}

/*
//clears the interrupt flag
TIMER0_ICR_R |= 0x00000001;
write this at the beginning of the ISR
*/
