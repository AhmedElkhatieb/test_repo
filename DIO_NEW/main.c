/*
 * main.c
 *
 *  Created on: Dec 6, 2023
 *      Author: LENOVO
 */
#include "BIT_MATH.h"
#include <avr/io.h>
#include <util/delay.h>

//7-segment definition where a is the MSB
#define 	zero 	0b00000011
#define 	one  	0b10011111
#define 	two  	0b00100101
#define 	three  	0b00001101
#define 	four  	0b10011001
#define 	five  	0b01001001
#define 	six  	0b01000001
#define 	seven	0b00011111
#define 	eight  	0b00000001
#define 	nine  	0b00001001

int main ()
{
	SET_BIT(DDRA,0);
	DDRA = 1;
	PORTA = 2;

	while(1)
	{
	/*	if (GET_BIT(PINA,1) == 0)
		{
			_delay_ms(70);
			if (GET_BIT(PINA,1) == 0)
			{
				TOG_BIT(PORTA,0);
			}
		}*/
		if (GET_BIT(PINA,1) == 0)
		{
			while (GET_BIT(PINA,1) == 0){}
			_delay_ms(10);
			TOG_BIT(PORTA,0);

		}


	}

	return 0;
}

