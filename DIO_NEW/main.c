/*
 * main.c
 *
 *  Created on: Dec 6, 2023
 *      Author: LENOVO
 */
#include <avr/io.h>
#include <util/delay.h>

int main ()
{
	DDRA  = 0b00001111;

	while(1)
	{
		PORTA = 1;
		for (char i = 0 ; i < 3 ; i++)
		{
			_delay_ms(250);
			PORTA <<= 1;
		}
		for (char i = 0 ; i < 3 ; i++)
		{
			_delay_ms(250);
			PORTA >>= 1;
		}
	}

	return 0;
}

