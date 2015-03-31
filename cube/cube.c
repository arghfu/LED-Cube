/*
 * cube.c
 *
 * Created: 26.03.2013 09:20:03
 *  Author: itchy
 */
#include <stdint.h>
#include <util/delay.h>
#include "main.h"
#include "cube.h"



void delay_ms (uint16_t delay)
{
	for (uint16_t i=0; i<delay; i++)
	{
	_delay_ms(1);	
	}	
}

uint8_t check_range_3 (uint8_t X, uint8_t Y,uint8_t Z)
{
	if (((X<CUBE_MAX) && (X>=CUBE_MIN)) && ((Y<CUBE_MAX) && (Y>=CUBE_MIN)) && ((Z<CUBE_MAX) && (Z>=CUBE_MIN)))
	{
		return 1;
	}
	else
	{
		return 0;	
	}
}

uint8_t check_range_2 (uint8_t X, uint8_t Y)
{
	if (((X<CUBE_MAX) && (X>=CUBE_MIN)) && ((Y<CUBE_MAX) && (Y>=CUBE_MIN)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

uint8_t check_size (uint8_t X)
{
	if ((X<=CUBE_MAX) && (X>=CUBE_MIN))
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

void cube_set_led (uint8_t X, uint8_t Y,uint8_t Z)
{
 	if (check_range_3 (X,Y,Z))
 	{
		cube[Z][Y] |= (1 << X);	
	}
}

void cube_set_led_row_X (uint8_t Y, uint8_t Z, uint8_t size, uint8_t start_X)
{
	if (check_size((size+start_X)))
	{
		if (check_range_2 (Y, Z))
		{
			for (uint8_t i=start_X; i<(size+start_X); i++)
			{
				cube_set_led (i,Y,Z);
			}
		}		
	}		
}

void cube_set_led_row_Y (uint8_t X, uint8_t Z, uint8_t size, uint8_t start_Y)
{
	if (check_size((size+start_Y)))
	{
		if (check_range_2 (X, Z))
		{
			for (int i=start_Y; i<(size+start_Y); i++)
			{
				cube_set_led (X,i,Z);
			}		
		}
	}		
}

void cube_set_led_row_Z (uint8_t X, uint8_t Y, uint8_t size, uint8_t start_Z)
{
	if (check_size((size+start_Z)))
	{
		if (check_range_2 (X, Y))
		{
			for (int i=start_Z; i<(size+start_Z); i++)
			{
				cube_set_led (X,Y,i);
			}
		}
	}	
}

void cube_set_led_area_X (uint8_t Y, uint8_t size, uint8_t start_X, uint8_t start_Z)
{
	
	if (check_size(size+start_Z))
	{
		for (uint8_t i=start_Z; i < (size+start_Z) ; i++)
		{
			cube_set_led_row_X(Y, i, size, start_X);
		}
	}
}

void cube_set_led_area_Y (uint8_t X, uint8_t size, uint8_t start_Y, uint8_t start_Z)
{
	if (check_size(size+start_Z))
	{
		for (uint8_t i=start_Z; i< (size+start_Z); i++)
		{
			cube_set_led_row_Y(X, i, size, start_Y);
		}
	}
}

void cube_set_led_area_Z (uint8_t Z, uint8_t size, uint8_t start_X, uint8_t start_Y)
{
	if (check_size(size+start_Y))
	{
		for (uint8_t i = start_Y; i < (size+start_Y); i++)
		{
			cube_set_led_row_X(i, Z, size, start_X);
		}
	}		
}

void cube_clr()
{
	for (int i=0; i<8; i++)
	{
		for (int j=0; j<8; j++)
		{
			cube[i][j]=0x00;
		}
	}
}

void cube_clr_led (uint8_t X, uint8_t Y,uint8_t Z)
{
	if (check_range_3 (X,Y,Z))
	{
		cube[Z][Y]&=~(1 << X);
	}
}

void cube_clr_led_row_X(uint8_t Y, uint8_t Z)
{
	if (check_range_2(Y,Z))
	{
		for (uint8_t i = 0; i < 8; i++)
		{
			cube_clr_led(i,Y,Z);
		}
	}
}

void cube_clr_led_row_Y( uint8_t X, uint8_t Z )
{
	if (check_range_2(X,Z))
	{
		for (uint8_t i = 0 ; i < CUBE_MAX; i++)
		{
			cube_clr_led(X,i,Z);
		}
	}
}

void cube_clr_led_row_Z( uint8_t X, uint8_t Y )
{
	if (check_range_2(X,Y))
	{
		for (uint8_t i = 0; i < CUBE_MAX; i++)
		{
			cube_clr_led(X,Y,i);
		}
	}
}

void cube_clr_led_area_X( uint8_t Y )
{
	for (uint8_t i = 0; i < CUBE_MAX; i++)
	{
		cube_clr_led_row_X(Y, i);
	}	
}

void cube_clr_led_area_Y( uint8_t X )
{
	for (uint8_t i = 0; i < CUBE_MAX; i++)
	{
		cube_clr_led_row_Y(X, i);
	}
}

void cube_clr_led_area_Z( uint8_t Z )
{
	for (uint8_t i=0; i< CUBE_MAX; i++)
	{
		cube_clr_led_row_X(i,Z);
	}
}

uint8_t cube_get_led_status( uint8_t X, uint8_t Y, uint8_t Z )
{
	if (cube[Z][Y] & (1 << X))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

