/*
 * effect.c
 *
 * Created: 27.03.2013 09:40:15
 *  Author: itchy
 */ 
#include <stdint.h>
#include <util/delay.h>
#include "main.h"
#include "cube.h"
#include "font.h"

void cube_effect_planes( uint16_t delay )
{
	for (int8_t i = 0; i < CUBE_MAX; i++)
	{
		cube_set_led_area_Z(i,8,0,0);
		delay_ms(delay);
	}
	for (int8_t i = 0; i<(CUBE_MAX-1);i++)
	{
		cube_clr_led_area_Z(i);
		delay_ms(delay);
	}
	for (int8_t i = 6, j=6 , k=1; i >= 4; i--,j-=2, k++)
	{		
		cube_set_led_area_Z(i,j,k,k);
		delay_ms(delay);				
	}
	for (int8_t i = 3, j=2, k=3 ; i >= CUBE_MIN; i--, j+=2, k--)
	{		
		cube_set_led_area_Z(i,j,k,k);
		delay_ms(delay);
	}
	for (int8_t i = 7; i >CUBE_MIN ; i--)
	{
		cube_clr_led_area_Z(i);
		delay_ms(delay);
	}
	for (int8_t i=0;i<(CUBE_MAX-1); i++)
	{
		cube_clr_led_row_Y(i,0);
		delay_ms(delay);
	}
	for (int8_t i=1;i<CUBE_MAX;i++)
	{
		cube_set_led_row_Y(7,i,8,0);
		delay_ms(delay);
	}
	for (int8_t i=6; i>=CUBE_MIN;i--)
	{
		cube_set_led_area_Y(i,8,0,0);
		delay_ms(delay);
	}
	for (int8_t i = 7; i > CUBE_MIN; i--)
	{
		cube_clr_led_area_Y(i);
		delay_ms(delay);
	}
	for (int8_t i = 1, j=6 , k=1; i <= 3; i++,j-=2, k++)
	{
		cube_set_led_area_Y(i,j,k,k);
		delay_ms(delay);
	}
	for (int8_t i = 4, j=2, k=3 ; i < CUBE_MAX ; i++, j+=2, k--)
	{
		cube_set_led_area_Y(i,j,k,k);
		delay_ms(delay);
	}
	for (int8_t i = 0; i < CUBE_MAX-1; i++)
	{
		cube_clr_led_area_Y(i);
		delay_ms(delay);
	}
	for (int8_t i=7; i>CUBE_MIN; i--)
	{
		cube_clr_led_row_Y(7,i);
		delay_ms(delay);
	}
	for (int8_t i=6; i>=CUBE_MIN; i--)
	{
		cube_set_led_row_Y(i,0,8,0);
		delay_ms(delay);
	}
	for(int8_t i=7; i>CUBE_MIN; i--)
	{
		cube_clr_led_row_X(i,0);
		delay_ms(delay);
	}
	
	for (int8_t i=1;i<CUBE_MAX;i++)
	{
		cube_set_led_row_X(0,i,8,0);
		delay_ms(delay);
	}
	for (int8_t i=0; i<CUBE_MAX;i++)
	{
		cube_set_led_area_X(i,8,0,0);
		delay_ms(delay);
	}
	for (int8_t i = 0; i < CUBE_MAX-1; i++)
	{
		cube_clr_led_area_X(i);
		delay_ms(delay);
	}	
	for (int8_t i = 6, j=6 , k=1; i >= 4; i--,j-=2, k++)
	{
		cube_set_led_area_X(i,j,k,k);
		delay_ms(delay);
	}
	for (int8_t i = 3, j=2, k=3 ; i >= CUBE_MIN ; i--, j+=2, k--)
	{
		cube_set_led_area_X(i,j,k,k);
		delay_ms(delay);
	}
	for (int8_t i = 7; i > CUBE_MIN; i--)
	{
		cube_clr_led_area_X(i);
		delay_ms(delay);
	}
	for (int8_t i=7; i>=CUBE_MIN; i--)
	{
		cube_clr_led_row_X(0,i);
		delay_ms(delay);		
	}
	delay_ms(delay*5);
}

void cube_effect_stairs (uint16_t delay)
{
	for (int8_t i=0; i<CUBE_MAX; i++)
	{
		for (int8_t j=0; j<(CUBE_MAX-i); j++)
		{
			cube_set_led_row_X(j,i,8,0);
		}
		delay_ms(delay);
	}
}

void cube_effect_string_arround (uint16_t delay, char* str)
{
	//copy the font data in tmp_chr, array [5] are the space between the chars
	uint8_t tmp_chr[5]={0};

	while (*str)
	{
		font_get_char(*str++, tmp_chr);

		for (int8_t j = 0; j < 6 ; j++ )
		{
			for (int8_t i = 0; i < CUBE_MAX; i++)
			{
				if (tmp_chr[j] & (0x80 >> i))
				{
					cube_set_led(0,0,i);
				}
				else
				{
					cube_clr_led(0,0,i);
				}
			}
			delay_ms(delay);
			font_shift();
		}
	}
	for (uint8_t i = 0; i <= 19; i++)
	{
		font_shift();
		delay_ms(delay);
	}
	delay_ms(delay);
}		



void cube_effect_rain( uint16_t delay )
{
	
	
}

/*void cube_effect_char_test( uint16_t delay, uint8_t number )
{
	uint8_t tmp_font[5]={0};
		
	
}*/




