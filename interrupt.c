#include"interrupt.h"
uint8_t flag;
void interrupt_init()
{
		volatile unsigned long delay;
	SYSCTL_RCGCGPIO_R |= 0x20;
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R= 0x1F;
	GPIO_PORTF_DIR_R &=~(0x11);
	GPIO_PORTF_DIR_R |=(0x6);
	GPIO_PORTF_AFSEL_R &=~(0x11);
	GPIO_PORTF_DEN_R |= 0x1F;
	GPIO_PORTF_AMSEL_R &=~(0x11);
	GPIO_PORTF_PUR_R |=0x11;
	GPIO_PORTF_IS_R &=~ (0x11);
	GPIO_PORTF_IBE_R &=~ (0x11);
	GPIO_PORTF_IEV_R &=~ (0x11);
	GPIO_PORTF_ICR_R |= 0x11;
	GPIO_PORTF_IM_R |=0x11;
  NVIC_PRI7_R = (NVIC_PRI7_R & 0xFF00FFFF) | 0xa0000;
	NVIC_EN0_R = 0x40000000;	
}

void GPIOF_Handler(void)
{
	if((GPIO_PORTF_RIS_R & 0x01)==0x01)
	{
		flag=1;


	}
	else 
		flag=0;
  if((GPIO_PORTF_RIS_R & 0x10)==0x10)
	{
		flag=2;

	}
	else
		flag=0;

}

