
#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "port.h"
#include "stdint.h"
#include "micro_config.h"
void delay(uint32_t time);
void motor_rotateClockwise();
void systick_init(void);
void motor_init(void);
void  motor_rotateAnticlockwise(void);
void systick_waitMS(void);


#endif // __MOTOR_H__

