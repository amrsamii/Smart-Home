#include "tm4c123gh6pm.h"
#include "temp.h"
#include "stdint.h"


int Tempsensor_read(void)
{
	volatile long ADC_Output =0;
  volatile long temperature;
	ADC0_PSSI_R |= 0x8; //initiate ss3
	while((ADC0_RIS_R & 0x8) == 0);                    /* wait for conversion complete */
	temperature = 147.5 - (247.5 * (ADC0_SSFIFO3_R & 0xFFF ) ) / 4096;
	ADC0_ISC_R = 0x8;          /* clear completion flag ADC0_ISC_R = (1<<3) */ 
	return temperature;
}
