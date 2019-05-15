#include"interrupt.h"
uint8_t flag;
void interrupt_init()
{
	GPIO_PORTF_IS_R &=~ (0x11);
	GPIO_PORTF_IBE_R &=~ (0x11);
	GPIO_PORTF_IEV_R &=~ (0x11);
	GPIO_PORTF_ICR_R |= 0x11;
	GPIO_PORTF_IM_R |=0x11;
  //NVIC_PRI7_R = (NVIC_PRI7_R & 0xFF00FFFF) | 0xa0000;
	NVIC_EN0_R = 0x40000000;	
}

void GPIOF_Handler(void)
{
	if((GPIO_PORTF_RIS_R & 0x01)==0x01)
	{
		UART_Write(7,20);
    GPIO_PORTF_ICR_R=0x01; //clears values of RIS and MIS
	}
  else if((GPIO_PORTF_RIS_R & 0x10)==0x10)
	{
		UART_Write(7,0);
		GPIO_PORTF_ICR_R=0x10; //clears values of RIS and MIS
	}
}

