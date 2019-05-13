#ifndef LCD_H
#define LCD_H
void LCD_DATA_CHAR (char data);
void LCD_intgerToString(uint32_t data);
void LCD_CLEAR (void);
char* itoa1(int i, char b[]);
#endif