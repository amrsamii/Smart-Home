#include "adc.h"



//ADC Initilization

void ADC0_Init(uint8_t channel)
{
   
    SYSCTL_RCGCADC_R |= SYSCTL_RCGCADC_R0;

    switch (channel)
    {
    case AIN0:
        
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
        //Delay for the clock
        channel = 0;
        
        GPIO_PORTE_AFSEL_R |= PIN3;
				GPIO_PORTE_DEN_R &= ~(PIN3);
        GPIO_PORTE_AMSEL_R |= PIN3;
        break;

    case AIN1:
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
        channel = 0;
        GPIO_PORTE_AFSEL_R |= PIN2;
        GPIO_PORTE_DEN_R &= ~(PIN2);
        GPIO_PORTE_AMSEL_R |= PIN2;
        break;

    case AIN2:
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
        channel = 0;
        GPIO_PORTE_AFSEL_R |= PIN1;
        GPIO_PORTE_DEN_R &= ~(PIN1);
        GPIO_PORTE_AMSEL_R |= PIN1;
        break;

    case AIN3:
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
        channel = 0;
        GPIO_PORTE_AFSEL_R |= PIN0;
        GPIO_PORTE_DEN_R &= ~(PIN0);
        GPIO_PORTE_AMSEL_R |= PIN0;
        break;

    case AIN4:
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
        channel = 0;
        GPIO_PORTD_AFSEL_R |= PIN3;
        GPIO_PORTD_DEN_R &= ~(PIN3);
        GPIO_PORTD_AMSEL_R |= PIN3;
        break;

    case AIN5:
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
        channel = 0;
        GPIO_PORTD_AFSEL_R |= PIN2;
        GPIO_PORTD_DEN_R &= ~(PIN2);
        GPIO_PORTD_AMSEL_R |= PIN2;
        break;

    case AIN6:
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
        channel = 0;
        GPIO_PORTD_AFSEL_R |= PIN1;
        GPIO_PORTD_DEN_R &= ~(PIN1);
        GPIO_PORTD_AMSEL_R |= PIN1;
        break;

    case AIN7:
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
        channel = 0;
        GPIO_PORTD_AFSEL_R |= PIN0;
        GPIO_PORTD_DEN_R &= ~(PIN0);
        GPIO_PORTD_AMSEL_R |= PIN0;
        break;

    case AIN8:
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
        channel = 0;
        GPIO_PORTE_AFSEL_R |= PIN5;
        GPIO_PORTE_DEN_R &= ~(PIN5);
        GPIO_PORTE_AMSEL_R |= PIN5;
		    GPIO_PORTE_DIR_R &= ~(PIN5);
        break;

    case AIN9:
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
        channel = 0;
        GPIO_PORTE_AFSEL_R |= PIN4;
        GPIO_PORTE_DEN_R &= ~(PIN4);
        GPIO_PORTE_AMSEL_R |= PIN4;
        break;

    case AIN10:
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
        channel = 0;
        GPIO_PORTB_AFSEL_R |= PIN5;
        GPIO_PORTB_DEN_R &= ~(PIN5);
        GPIO_PORTB_AMSEL_R |= PIN5;
        break;

    case AIN11:
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
        channel = 0;
        GPIO_PORTB_AFSEL_R |= PIN4;
        GPIO_PORTB_DEN_R &= ~(PIN4);
        GPIO_PORTB_AMSEL_R |= PIN4;
        break;
    }
    return;
}

//Sample Sequencer Initilization for ADC0 Sample Sequencer 3

void ADC0_SS3_Init(uint8_t channel, uint16_t mode, uint8_t temp_en)
{
    //Ensure ADC is not busy
    while (ADC0_ACTSS_R & ADC_ACTSS_BUSY)
        ;
    ADC0_ACTSS_R &= ~ADC_ACTSS_ASEN3;
    
    ADC0_EMUX_R &= ~ADC_EMUX_EM3_ALWAYS;
    ADC0_EMUX_R |= mode;
   

    ADC0_SSMUX3_R |= channel;

    
    if (temp_en == ENABLE)
    {
        ADC0_SSCTL3_R |= ADC_SSCTL3_TS0;
    }
    else
    {
        ADC0_SSCTL3_R &= ~(ADC_SSCTL3_TS0);
    }
    ADC0_SSCTL3_R |= ADC_SSCTL3_IE0;
    ADC0_SSCTL3_R |= ADC_SSCTL3_END0;
    ADC0_SSCTL3_R &= ~(ADC_SSCTL3_D0);

   
    ADC0_IM_R &= ~(ADC_IM_MASK3);
  
    ADC0_ACTSS_R |= ADC_ACTSS_ASEN3;
    return;
}

uint16_t ADC0_SS3_Read()
{
	uint16_t result;
    //This is only if the trigger is default
    ADC0_PSSI_R |= ADC_PSSI_SS3;
    //poling on raw interrupt
    while (!(ADC0_RIS_R & ADC_RIS_INR3))
        ;
    result = ADC0_SSFIFO3_R & ADC_SSFIFO3_DATA_M;
    //Clear flag before returning the value
    ADC0_ISC_R |= ADC_ISC_IN3;
    return result;

}
