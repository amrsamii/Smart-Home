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

void LCD_init(void)
{
	SYSCTL_RCGCGPIO_R = 0x03;
	while((SYSCTL_PRGPIO_R&0x03)==0);
	GPIO_PORTB_DIR_R = 0xFF;
	GPIO_PORTB_DEN_R = 0xFF;
	GPIO_PORTA_DIR_R = 0xE0;
	GPIO_PORTA_DEN_R = 0xE0;
	
	LCD_COMMAND (0x38);
	sysTick_wait10ms(1);
	LCD_COMMAND (0x0C);
	sysTick_wait10ms(1);
		LCD_COMMAND (0x01);
	sysTick_wait10ms(1);
		LCD_COMMAND (0x06);
	sysTick_wait10ms(1);

}

void LCD_COMMAND (char com)
{
	GPIO_PORTA_DATA_R = 0;
	sysTick_wait10ms(1);
	GPIO_PORTA_DATA_R|=0x80;
	sysTick_wait10ms(1);
	GPIO_PORTB_DATA_R = com;
	sysTick_wait10ms(1);
	GPIO_PORTA_DATA_R=0;
	sysTick_wait10ms(1);
}

void LCD_DATA_STRING (char s[])
{
	int i=0;
	while(s[i]!= '\0') // check for null character
	{
		LCD_DATA_CHAR(s[i++]);
	}
}

