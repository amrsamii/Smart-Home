#include "ADC.h"

//This Driver was created by returning to this pages in the datasheet
//799->817

/*
An analog-to-digital converter (ADC) is a peripheral that converts a continuous analog voltage to a
discrete digital number. Two identical converter modules are included, which share 12 input channels.

12-bit conversion resolution and supports 12 input channels.

Flexible trigger control
– Controller (software)
– Timers
– Analog Comparators
– PWM
– GPIO

each FIFO entry is a 32-bit word, with the lower 12 bits containing the conversion result.

ADC Sample Sequence
Input Multiplexer Select (ADCSSMUXn) and ADC Sample Sequence Control (ADCSSCTLn)
registers, where "n" corresponds to the sequence number. The ADCSSMUXn fields select the input
pin, while the ADCSSCTLn fields contain the sample control bits corresponding to parameters such
as temperature sensor selection, interrupt enable, end of sequence

Sample sequencers are enabled by setting the respective ASENn bit in the ADC Active Sample
Sequencer (ADCACTSS) register and should be configured before being enabled. Sampling is
then initiated by setting the SSn bit in the ADC Processor Sample Sequence Initiate (ADCPSSI)
register.

After a sample sequence completes execution, the result data can be retrieved from the ADC
Sample Sequence Result FIFO (ADCSSFIFOn) registers. The FIFOs are simple circular buffers
that read a single address to "pop" result data.

ADC Sample Sequence FIFO Status (ADCSSFSTATn)
registers along with FULL and EMPTY status flags. If a write is attempted when the FIFO is full, the
write does not occur and an overflow condition is indicated. Overflow and underflow conditions are
monitored using the ADCOSTAT and ADCUSTAT registers.


The ADC module's interrupt signals are controlled by the state of the MASK bits
in the ADC Interrupt Mask (ADCIM) register. Interrupt status can be viewed at two locations: the
ADC Raw Interrupt Status (ADCRIS) register, which shows the raw status of the various interrupt
signals

The BUSY bit of the ADCACTSS register is used to indicate when the ADC is busy with a current
conversion. When there are no triggers pending which may start a new conversion in the immediate
cycle or next few cycles, the BUSY bit reads as 0. Software must read the status of the BUSY bit as
clear before disabling the ADC clock by writing to the Analog-to-Digital Converter Run Mode
Clock Gating Control (RCGCADC) register.



*/

//Pre-Initilizaton
/*

the PLL must be enabled and programmed to a supported
crystal frequency in the RCC register (see page 254). Using unsupported frequencies can cause
faulty operation in the ADC module.

*/

//ADC Initilization

void ADC0_Init(uint8_t channel)
{
    //1. Enable the ADC clock using the RCGCADC register (see page 352).
    SYSCTL_RCGCADC_R |= SYSCTL_RCGCADC_R0;

    switch (channel)
    {
    case AIN0:
        //2. Enable the clock to the appropriate GPIO modules via the RCGCGPIO register (see page 340).
        //To find out which GPIO ports to enable, refer to “Signal Description” on page 801.
        SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
        //Delay for the clock
        channel = 0;
        //3. Set the GPIO AFSEL bits for the ADC input pins (see page 671). To determine which GPIOs to
        //configure, see Table 23-4 on page 1344.
        GPIO_PORTE_AFSEL_R |= PIN3;
        //4. Configure the AINx signals to be analog inputs by clearing the corresponding DEN bit in the
        //GPIO Digital Enable (GPIODEN) register (see page 682).
        GPIO_PORTE_DEN_R &= ~(PIN3);
        //5. Disable the analog isolation circuit for all ADC input pins that are to be used by writing a 1 to
        //the appropriate bits of the GPIOAMSEL register (see page 687) in the associated GPIO block.
        GPIO_PORTE_AMSEL_R |= PIN3;
        //6.If required by the application, reconfigure the sample sequencer priorities in the ADCSSPRI
        //register. The default configuration has Sample Sequencer 0 with the highest priority and Sample
        //Sequencer 3 as the lowest priority.
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
    //1. Ensure that the sample sequencer is disabled by clearing the corresponding ASENn bit in the
    //ADCACTSS register. Programming of the sample sequencers is allowed without having them
    //enabled. Disabling the sequencer during programming prevents erroneous execution if a trigger
    //event were to occur during the configuration process.
    //Ensure ADC is not busy
    while (ADC0_ACTSS_R & ADC_ACTSS_BUSY)
        ;
    ADC0_ACTSS_R &= ~ADC_ACTSS_ASEN3;
    //2. Configure the trigger event for the sample sequencer in the ADCEMUX register.
    //Use the defines to use a certain trigger, we clear the mask first before setting the mode
    ADC0_EMUX_R &= ~ADC_EMUX_EM3_ALWAYS;
    ADC0_EMUX_R |= mode;
    //3. When using a PWM generator as the trigger source, use the ADC Trigger Source Select
    //(ADCTSSEL) register to specify in which PWM module the generator is located. The default
    //register reset selects PWM module 0 for all generators.
    //No PWM will be running in this project
    //-------------------------------------------------------------------------------------
    //4. For each sample in the sample sequence, configure the corresponding input source in the
    //ADCSSMUXn register.

    ADC0_SSMUX3_R |= channel;

    //5. For each sample in the sample sequence, configure the sample control bits in the corresponding
    //nibble in the ADCSSCTLn register. When programming the last nibble, ensure that the END bit
    //is set. Failure to set the END bit causes unpredictable behavior.
    //Configure the Temprature, Enable Raw Interrupt, Enable End of sequence, Disable diffrential input
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

    //6. If interrupts are to be used, set the corresponding MASK bit in the ADCIM register.
    //Disable the ISR
    ADC0_IM_R &= ~(ADC_IM_MASK3);
    //7. Enable the sample sequencer logic by setting the corresponding ASENn bit in the ADCACTSS
    //register.
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
