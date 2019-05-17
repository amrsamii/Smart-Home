#include"micro_config.h"

void SystemInit(){
}
void EnableInterrupts(void);
void TIMER0A_Handler(void);


	int main()
	{
		uint8_t Data_Recieved;
		uint8_t mode;
		uint8_t pwm;
		uint8_t i;
		EnableInterrupts();
		PLL_Init();
		pwm_init();	
		Periodic_Timer_Init(0x00F42400);
		systick_init();
		motor_init();
		ADC0_Init();
		UART_Init(7);
		while(1)
		{
			Data_Recieved = UART_Read(7);
			mode = Data_Recieved & 0x80;
			if(!mode){
			if(	Data_Recieved==0)
			{
			motor_rotateClockwise();			
		}
			else

			{
				motor_rotateAnticlockwise();
			}
		}
			else
			{
				pwm= Data_Recieved&0x7F ;
		     pwm_setDutycycle(pwm);
	    } 
}
}
void TIMER0A_Handler(void)
{
		UART_Write(7,Tempsensor_read());	
		TIMER0_ICR_R |= 0x00000001;

}