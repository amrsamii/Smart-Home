#include"pwm.h"
#include"port.h"
void _delay_ms(uint32_t y)
{

	 unsigned long volatile t;
	 t= 1000*y;
 	 while(t){t--;}
 }
void pwm_init()
{
	
	SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;
	SYSCTL_RCGCGPIO_R |= 0x20;
	SYSCTL_RCC_R |= 0x00100000;
	SYSCTL_RCC_R |= 0xA0000; // PWM Clock = 1.25 MHz
	PWM1_3_CTL_R = 0x00000000;
	PWM1_3_GENA_R = 0x0000008C; // Drive PWM High at reload value and drive it to zero when it matches CMP
	PWM1_3_LOAD_R = 1250 - 1; // 1ms periodic time
	PWM1_3_CMPA_R = 1248; // 0% Duty Cycle
	PWM1_3_CTL_R = 0x01;	
	GPIO_PORTF_AFSEL_R |= 0x04;
	GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF0FF) | (GPIO_PCTL_PF2_M1PWM6);
	GPIO_PORTF_DIR_R |= 0x04;
	GPIO_PORTF_DEN_R |= 0x04;
	PWM1_ENABLE_R = 0x40; // M1PWM6 (PF2)
}
void pwm_setDutycycle(uint8_t duty_cycle)
{
	if(duty_cycle == 100){
		PWM1_3_CMPA_R = 1;
	} else if(duty_cycle == 0) {
		PWM1_3_CMPA_R = 1248;
	}else {
		PWM1_3_CMPA_R = (uint16_t)(1250 * (1 - (duty_cycle / 100.0)) - 1);
	}
}