#pragma once
#define CLEAN_MOD 0
#define NEW_MOD 1
#define DOWN_C 0
#define LEFT_C 1
#define RIGHT_C 2
struct GameObject
{
	char image[4][4];
	int position_x, position_y;
};
int init_ge(void(*re)());
void make_gameobject(GameObject* object);
void Update(char*);
void g_left();
void g_up();
void g_right();
void g_down();
