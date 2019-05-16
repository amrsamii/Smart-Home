#include "Potentiometer.h"

void Pot_Init(uint8_t channel, uint16_t mode)
{
    ADC0_Init(channel);
    ADC0_SS3_Init(channel, mode, DISABLE);
}
uint16_t Pot_Read(void)
{
    return ADC0_SS3_Read();
}
