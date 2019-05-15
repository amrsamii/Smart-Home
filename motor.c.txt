#include "motor2.h"
#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "port.h"
#include "delay.h"


#define CLOCK_CYCLES_PER_MS 16000

void systick_waitMS(void){
	NVIC_ST_RELOAD_R = CLOCK_CYCLES_PER_MS - 1;
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R&NVIC_ST_CTRL_COUNT) != NVIC_ST_CTRL_COUNT);
}

/*void systick_wait1ms(void){
	uint32_t elapsedTime;
  uint32_t startTime = NVIC_ST_CURRENT_R;
  do{
    elapsedTime = (startTime - NVIC_ST_CURRENT_R)&0x00FFFFFF;
  }
  while(elapsedTime <= CLOCK_CYCLES_PER_MS);
}*/




void motor_init(void)
{
  Port_Init(3);
	Port_Init(5);
	Port_SetPinDirection(3 , 0x0F , PORT_PIN_OUT);
	Port_SetPinDirection(5 , 0x11 , PORT_PIN_IN);
	Port_SetPinPullUp( 5 , 0x11 ,1);
	
}



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

