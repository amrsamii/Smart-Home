#include"uart.h"


void UART0_Init(void){
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
	
	UART0_CTL_R &= ~UART_CTL_UARTEN;
	UART0_IBRD_R = 520;    
  UART0_FBRD_R = 53;
	UART0_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
	UART0_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
	
	GPIO_PORTA_AFSEL_R |= GPIO_PA10_M;
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PA1_U0TX | GPIO_PCTL_PA0_U0RX);
	GPIO_PORTA_DEN_R |= GPIO_PA10_M;
}


void UART0_Write(uint8_t data){
	while((UART0_FR_R&UART_FR_TXFF) != 0);
	UART0_DR_R = data;
}
void UART_sendString(const uint8_t *Str)
{
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		UART0_Write(Str[i]);
		i++;
	}
}
