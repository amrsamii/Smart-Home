#include"micro_config.h"
#include"lcd.h"
void SystemInit(){
}
void TIMER0A_Handler(void);
	int main()
	{
		uint8_t delay=0;
		EnableInterrupts();
		PLL_Init();
		Port_Init(5);
		Port_SetPinDirection(5 , 0x11 , PORT_PIN_IN);
   	Port_SetPinPullUp( 5 , 0x11 ,1);
    interrupt_init();

		systick_init();
		LCD_init();
		UART_Init(7);
		Pot_Init(AIN8, ADC_EMUX_EM3_PROCESSOR);
		LCD_displayString ("Temp is:");
		LCD_sendCommand(0xC0);
		Periodic_Timer_Init(200000);
		while(1)
		{
		LCD_intgerToString(UART_Read(7));

		}
		
	}
	
	void TIMER0A_Handler(void)
	{
			uint16_t pot;
	    uint8_t pot2;
	   	pot = Pot_Read();
		  pot2= (pot/4095.0)*100;
		  pot2 |=0x80;
		  UART_Write(7,pot2);
		
			TIMER0_ICR_R |= 0x00000001;
	}
