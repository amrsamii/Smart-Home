#include "motor.h"
#include "systick.h"









void motor_rotateClockwise(void){
int j;
	for( j=0 ; j<4 ; j++ )
	{
		GPIO_PORTD_DATA_R =0x03;
		_delay_ms(10);
		GPIO_PORTD_DATA_R =0x6;
		_delay_ms(10);
		GPIO_PORTD_DATA_R =0x0c;
		_delay_ms(10);
		GPIO_PORTD_DATA_R =0x09;
		_delay_ms(10);
		
	}

}



void motor_init(void)
{
  Port_Init(3);
	Port_SetPinDirection(3 , 0x0F , PORT_PIN_OUT);
	
}



void motor_rotateAnticlockwise(void)
{
	int i; 
	
for(i=0;i<4;i++)
	{
		GPIO_PORTD_DATA_R =0x09;
		_delay_ms(10);
		GPIO_PORTD_DATA_R =0xC;
		_delay_ms(10);
		GPIO_PORTD_DATA_R =0x06;
		_delay_ms(10);
		GPIO_PORTD_DATA_R =0x03;
		_delay_ms(10);
		
	}
}


