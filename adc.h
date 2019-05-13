#ifndef ADC_H_
#define ADC_H_

#include "micro_config.h"
#define GPIO_E_M 0x10
#define ADC0_CLK_M 0x01
#define GPIO_PE2_M  (0x1<<2)
#define ADC0_ACTSS_SS3 0x8
#define ADC0_SS3_TRIG 0x0FFF
#define ADC0_SSMUX3  0x0
#define ADC0_SSCTL3_IEO (0x1 << 2)
#define ADC0_SSCTL3_END0 (0x1 << 1)
#define ACD0_PSSI_SS3 (0x1 <<3)
#define ADC0_RIS_INR3 (0x1 <<3)
void ADC0_Init(void);
uint16_t ADC_SS3_In();

#endif
