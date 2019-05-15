#include "motor.h"
#include "tm4c123gh6pm.h"
#include "delay.h"

void systick_init(void){
	NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;
	NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;
	NVIC_ST_CURRENT_R = NVIC_ST_CURRENT_S;
	NVIC_ST_CTRL_R |= (NVIC_ST_CTRL_CLK_SRC | NVIC_ST_CTRL_ENABLE);
}



void motor_rotateClockwise(void){
int j;
	for( j=0 ; j<10 ; j++ )
	{
		GPIO_PORTD_DATA_R =0x03;
		delay(10);
		GPIO_PORTD_DATA_R =0x6;
		delay(10);
		GPIO_PORTD_DATA_R =0x0c;
		delay(10);
		GPIO_PORTD_DATA_R =0x09;
		delay(10);
		
	}

}



void delay(uint32_t time){
	uint32_t i;
	for(i = 0;i < time;i++){
		systick_waitMS();
	}
}
