#include "temp.h"
#define GPIO_E_M 0x10
#define ADC0_CLK_M 0x01
#define GPIO_PE2_M  (0x1<<2)
#define ADC0_ACTSS_SS3 0x8
#define ADC0_SS3_TRIG 0x0FFF
#define ADC0_SSMUX3  0x0
#define ADC0_SSCTL3_IEO (0x1 << 2)
#define ADC0_SSCTL3_END0 (0x1 << 1)
#define ADC0_SSCTL3_TS0 (0x1 << 3)


void ADC0_Init(void){
	SYSCTL_RCGCADC_R|=  ADC0_CLK_M;
	SYSCTL_RCGCGPIO_R|= GPIO_E_M;
	ADC0_ACTSS_R&=~(ADC0_ACTSS_SS3);
	ADC0_EMUX_R&=~(ADC0_SS3_TRIG);
	ADC0_SSMUX3_R = ADC0_SSMUX3;
	ADC0_SSCTL3_R |= (ADC0_SSCTL3_IEO|ADC0_SSCTL3_END0|ADC0_SSCTL3_TS0);
	ADC0_ACTSS_R|=ADC0_ACTSS_SS3;
        GPIO_PORTE_AFSEL_R|= GPIO_PE2_M;
	GPIO_PORTE_DEN_R &=~(GPIO_PE2_M);
	GPIO_PORTE_AMSEL_R |= GPIO_PE2_M;
}

uint16_t Tempsensor_read(void)
{
	volatile long ADC_Output =0;
        volatile long temperature=0;
	ADC0_PSSI_R |= 0x8; //initiate ss3
	while((ADC0_RIS_R & 0x8) == 0);                    /* wait for conversion complete */
	temperature = 147.5 - (247.5 * (ADC0_SSFIFO3_R & 0xFFF ) ) / 4096;
	ADC0_ISC_R = 0x8;          /* clear completion flag ADC0_ISC_R = (1<<3) */ 
	return temperature;
}

