#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "TWI.h"
#include "LCD_I2C.h"
int main(void)
{
	I2C_Init();//������������� ������
	lcd_init();//������������� LCD
	char i=0;// ���������� �������� ������
	char buf[10];//�������� ������ ��� LCD
	lcd_clear();//������� LCD � ������� ������� � 0.0
	lcd_putstring("Hello World!");//������ �����
	while (1)
	{
		sprintf(buf,"%03d sec",i);//��������� � ������
		lcd_gotoxy(0,1);//��������� ������
		lcd_putstring(buf);//������ ������
		_delay_ms(1000);//��������
		i+=1;//��������� ��������
	}
}