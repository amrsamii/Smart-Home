#ifndef __POT_H__
#define __POT_H__

#include"micro_config.h"
#include "ADC.h"

void Pot_Init(uint8_t channel, uint16_t mode);
uint16_t Pot_Read(void);

#endif // __POT_H__
