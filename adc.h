#ifndef __ADC_H__
#define __ADC_H__

#include"micro_config.h"

#define PIN0 1
#define PIN1 2
#define PIN2 4
#define PIN3 8
#define PIN4 16
#define PIN5 32
#define PIN6 64
#define PIN7 128

#define AIN0 0   //PE3
#define AIN1 1   //PE2
#define AIN2 2   //PE1
#define AIN3 3   //PE0
#define AIN4 4   //PD3
#define AIN5 5   //PD2
#define AIN6 6   //PD1
#define AIN7 7   //PD0
#define AIN8 8   //PE5
#define AIN9 9   //PE4
#define AIN10 10 //PB5
#define AIN11 11 //PB4

#define ENABLE 1
#define DISABLE 0

//Prototypes
void ADC0_Init(uint8_t channel);
void ADC0_SS3_Init(uint8_t channel, uint16_t mode, uint8_t temp_en);
uint16_t ADC0_SS3_Read(void);

#endif // __ADC_H__
