#pragma once
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
int init_input_controller(void (*left_e)(void), void (*right_e)(void), void (*up_e)(void), void (*down_e)(void));