/*
 * font.h
 *
 * Created: 02.04.2013 15:15:48
 *  Author: itchy
 */ 


#ifndef FONT_H_
#define FONT_H_

void font_get_char(char chr, uint8_t tmp[5]);
void font_get_extra(uint8_t number, uint8_t tmp[5]);
void font_shift();

#endif /* FONT_H_ */