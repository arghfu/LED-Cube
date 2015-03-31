/*
 * main.h
 *
 * Created: 27.03.2013 09:51:53
 *  Author: itchy
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define CUBE_MAX 8
#define CUBE_MIN 0

#ifndef F_CPU
#define F_CPU 16000000UL
#endif


#define DATA_BUS PORTA
#define LAYER_SELECT PORTC
#define LATCH_ADDR PORTB
#define LATCH_MASK 0x07
#define LATCH_MASK_INV 0xf8
#define OE_PORT PORTB
#define OE_MASK 0x08


volatile unsigned char cube [8][8]; // Axis [Z][Y],  1 << X Coord

volatile unsigned char current_layer;

void ioinit ();


#endif /* MAIN_H_ */