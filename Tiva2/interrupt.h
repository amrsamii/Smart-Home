#ifndef __INTERRUPT_H__
#define	__INTERRUPT_H__

#include "micro_config.h"

void interrupt_init();
void GPIOF_Handler(void);
void EnableInterrupts(void);

#endif