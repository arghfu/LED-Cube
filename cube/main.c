/*
 * main.c
 *
 * Created: 26.03.2013 09:17:06
 *  Author: itchy
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"
#include "cube.h"
#include "effect.h"
#include "font.h"


int main(void)
{
	ioinit(); //IO-Interrupt initialization 
	
	sei(); // enable interrupt
	
	current_layer=0;
		
	while (1)
 	{
		/*cube_effect_stairs(1000);
		cube_effect_planes(1000);*/
 		cube_effect_string_arround(2000, "Das ist ein Test");
	}		 
}

void ioinit	()
{
	DDRA=0xff;	//Set PORTA AS output
 	DDRB=0xff;	//Set PORTB AS output
 	DDRC=0xff;	//Set PORTC as output
	
	
	
	
 	PORTB=0x00;	//Set PORTB B#00000000
	PORTA=0x00;	//Set PORTA B#00000000
 	PORTC=0x00;	//Set PORTC B#00000000
	
	
	
	
	//Timer 2
	// Frame buffer interrupt
	// 14745600/128/11 = 10472.72 interrupts per second
	// 10472.72/8 = 1309 frames per second
	OCR2 = 10; 	// interrupt at counter = 10
	TCCR2 |= (1 << CS20) | (1 << CS22); // Prescaler = 128.
	TCCR2 |= (1 << WGM21); // CTC mode. Reset counter when OCR2 is reached.
	TCNT2 = 0x00;	// initial counter value = 0;
	TIMSK |= (1 << OCIE2); // Enable CTC interrupt
}

ISR(TIMER2_COMP_vect)
{

	LAYER_SELECT = 0x00; // Turn all cathode layers off. (all transistors off)
	OE_PORT |= OE_MASK; // Set OE high, disabling all outputs on latch array

	// Loop through all 8 bytes of data in the current layer
	// and latch it onto the cube.
	for (int i = 0; i < 8; i++)
	{
		// Set the data on the data-bus of the latch array.
		DATA_BUS = cube[current_layer][i];
		// Increment the latch address chip, 74HC138, to create
		// a rising edge (LOW to HIGH) on the current latch.
		LATCH_ADDR = (LATCH_ADDR & LATCH_MASK_INV) | (LATCH_MASK & (i+1));
	}

	OE_PORT &= ~OE_MASK; // Set OE (OC) low, enabling outputs on the latch array
	LAYER_SELECT = (0x01 << current_layer); // Transistor ON for current layer

	// Increment the current_layer counter so that the next layer is
	// drawn the next time this function runs.
	current_layer++;
	// We want to count from 0-7, so set it to 0 when it reaches 8.
	if (current_layer == 8)
	{
		current_layer = 0;
	}
}