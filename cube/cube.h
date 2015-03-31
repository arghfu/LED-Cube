/*
 * cube.h
 *
 * Created: 26.03.2013 09:18:07
 *  Author: itchy
 */ 

#ifndef CUBE_H_
#define CUBE_H_

void delay_ms(uint16_t delay);

uint8_t check_range_3 (uint8_t X, uint8_t Y, uint8_t Z);
uint8_t check_range_2 (uint8_t X, uint8_t Y);
uint8_t check_range_1 (uint8_t X);
uint8_t check_size (uint8_t X);

void cube_set_led (uint8_t X, uint8_t Y, uint8_t Z);
void cube_set_led_row_X (uint8_t Y, uint8_t Z, uint8_t size, uint8_t start_X);
void cube_set_led_row_Y (uint8_t X, uint8_t Z, uint8_t size, uint8_t start_Y);
void cube_set_led_row_Z (uint8_t X, uint8_t Y, uint8_t size, uint8_t start_Z);
void cube_set_led_area_X (uint8_t Y, uint8_t size, uint8_t start_X, uint8_t start_Z);
void cube_set_led_area_Y (uint8_t X, uint8_t size, uint8_t start_Y, uint8_t start_Z);
void cube_set_led_area_Z (uint8_t Z, uint8_t size, uint8_t start_X, uint8_t start_Y);

void cube_clr();
void cube_clr_led (uint8_t X, uint8_t Y, uint8_t Z);
void cube_clr_led_row_X (uint8_t Y, uint8_t Z);
void cube_clr_led_row_Y (uint8_t X, uint8_t Z);
void cube_clr_led_row_Z (uint8_t X, uint8_t Y);
void cube_clr_led_area_X (uint8_t Y);
void cube_clr_led_area_Y (uint8_t X);
void cube_clr_led_area_Z (uint8_t Z);

uint8_t cube_get_led_status (uint8_t X, uint8_t Y, uint8_t Z);



#endif  /* CUBE_H_ */
 