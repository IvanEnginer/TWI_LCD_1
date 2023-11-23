#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "TWI.h"
#include "LCD_I2C.h"
int main(void)
{
	I2C_Init();//инициализация модуля
	lcd_init();//инициализация LCD
	char i=0;// переменная хранения секунд
	char buf[10];//хранение строки для LCD
	lcd_clear();//очистка LCD и перевод курсора в 0.0
	lcd_putstring("Hello World!");//рисуем фразу
	while (1)
	{
		sprintf(buf,"%03d sec",i);//переводим в строку
		lcd_gotoxy(0,1);//переводим курсор
		lcd_putstring(buf);//рисуем строку
		_delay_ms(1000);//задержка
		i+=1;//изменение значения
	}
}