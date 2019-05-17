#ifndef PWM_H_
#define PWM_H_

#include "micro_config.h"


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void pwm_init();
void pwm_setDutycycle(uint8_t duty_cycle);
void _delay_ms(uint32_t y);
#endif