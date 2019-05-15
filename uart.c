#include"uart.h"



uint8_t UART0_Available(void){
	return ((UART0_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
}

uint8_t UART0_Read(void){
	while(UART0_Available() != 1);
	return (uint8_t)(UART0_DR_R&0xFF);
}


void UART_receiveString(uint8_t *Str)

{
	uint8_t i = 0;
	Str[i] = UART0_Read();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART0_Read();
	}
	Str[i] = '\0';
}