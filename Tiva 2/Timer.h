#ifndef __TIMER_H__
#define	__TIMER_H__

#include"micro_config.h"
#include"Timer.h"

#define TIMER_LOAD_VAL 0x00F42400 // 16,000,000 in decimal = microcontroller's clock freq. therefore equivalent to one second

void Periodic_Timer_Init(uint32_t TimerNo);
#endif


