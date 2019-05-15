#include "systick_waitMS.h"

#include "delay.h"

void delay(uint32_t time){
	uint32_t i;
	for(i = 0;i < time;i++){
		systick_waitMS();
	}
}
