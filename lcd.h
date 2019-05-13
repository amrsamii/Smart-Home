#ifndef LCD_H
#define LCD_H

void LCD_DATA_CHAR (char data);
void LCD_intgerToString(uint32_t data);
void LCD_CLEAR (void);
char* itoa1(int i, char b[]);
void LCD_init(void);
void LCD_COMMAND (char com);
void LCD_DATA_STRING (char s[]);
#endif