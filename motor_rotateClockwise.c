#include "motor_rotateClockwise.h"
#include "tm4c123gh6pm.h"
#include "delay.h"


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

	
	
