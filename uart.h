#ifndef __UART_H__
#define	__UART_H__

#include "micro_config.h"
void UART0_Init(void);

uint8_t UART0_Available(void);

uint8_t UART0_Read(void);

void UART0_Write(uint8_t data);

void UART_sendString(const uint8_t *Str);

void UART_receiveString(uint8_t *Str);


#endif // __UART_H__