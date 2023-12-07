/*
 * main.c
 *
 *  Created on: Dec 8, 2023
 *      Author: LENOVO
 */

#include "STD_TYPES.h"
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"


void KPD_Init (void)
{
	DDRB  = 0x0F;	//PORTB input rows output columns
	PORTB = 0xFF;	//Activate pull up resistors on inputs and deactivate every column as a start
}

u8 GetPressedKey (void)
{
	u8 pressed_key = 0;

	for (u8 col = 0 ; col < 4 ; col++)
	{
		/*Activate Current Column*/
		CLR_BIT(PORTB,col);
		for (u8 row = 0 ; row < 4 ; row++)
		{
			if (GET_BIT(PINB,row+4) == 0)	//a button is pressed
			{
				pressed_key = row+1+(col*4);//key number
			}
			while (GET_BIT(PINB,row+4) == 0){}
			_delay_ms(10);
		}
		/*Deactivate Column*/
		SET_BIT(PORTB,col);
	}

	return pressed_key;
}

int main ()
{
	KPD_Init();


	while (1)
	{


	}

	return 0;
}
