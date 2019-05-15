#include "motor_rotateAnticlockwise.h"
#include "tm4c123gh6pm.h"
#include "delay.h"


void motor_rotateAnticlockwise(void)
{
	int i; 
	
for(i=0;i<10;i++)
	{
		GPIO_PORTD_DATA_R =0x09;
		delay(10);
		GPIO_PORTD_DATA_R =0xC;
		delay(10);
		GPIO_PORTD_DATA_R =0x06;
		delay(10);
		GPIO_PORTD_DATA_R =0x03;
		delay(10);
		
	}
}

