#include "lcd.h"
void LCD_DATA_CHAR (char data)
{
	GPIO_PORTA_DATA_R = 0x20;
	sysTick_wait10ms(1);
	GPIO_PORTA_DATA_R|=0x80;
	sysTick_wait10ms(1);
	GPIO_PORTB_DATA_R=data;
	sysTick_wait10ms(1);
	GPIO_PORTA_DATA_R&=~(0x80);
	sysTick_wait10ms(1);
}

char* itoa1(int i, char b[])
{
    char const digit[] = "0123456789";
    char* p = b;
	 int shifter = i;
    if(i<0){
        *p++ = '-';
        i *= -1; }
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}

void LCD_intgerToString(uint32_t data)
{
    char string [32];
    itoa1(data,string);
	  LCD_DATA_STRING(string);
}

void LCD_CLEAR (void)
{
	LCD_COMMAND(0x01);
}