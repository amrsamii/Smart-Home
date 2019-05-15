#include "tm4c123gh6pm.h"
#include "port.h"
#include "motor_init.h"


void motor_init(void)
{
  Port_Init(3);
	Port_Init(5);
	Port_SetPinDirection(3 , 0x0F , PORT_PIN_OUT);
	Port_SetPinDirection(5 , 0x11 , PORT_PIN_IN);
	Port_SetPinPullUp( 5 , 0x11 ,1);
	
}

