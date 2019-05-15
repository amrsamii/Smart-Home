#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "stdint.h"

void delay(uint32_t time);
void motor_rotateClockwise();

void systick_init(void);

#endif // __MOTOR_H__
