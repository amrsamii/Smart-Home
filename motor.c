#include "motor.h"




#define CLOCK_CYCLES_PER_MS 16000

void systick_init(void){
	NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;
	NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;
	NVIC_ST_CURRENT_R = NVIC_ST_CURRENT_S;
	NVIC_ST_CTRL_R |= (NVIC_ST_CTRL_CLK_SRC | NVIC_ST_CTRL_ENABLE);
}



void motor_rotateClockwise(void){
int j;
	for( j=0 ; j<4 ; j++ )
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
	Port_SetPinDirection(3 , 0x0F , PORT_PIN_OUT);
	
}



void motor_rotateAnticlockwise(void)
{
	int i; 
	
for(i=0;i<4;i++)
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


