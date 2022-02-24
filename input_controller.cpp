#include <stdio.h>
#include <conio.h>
#include"ThreadPool.h"
#include"input_controller.h"
void (*left_enter)(void);
void (*right_enter)(void);
void (*up_enter)(void);
void (*down_enter)(void);
void getkey(char*);
int init_input_controller(void (*left_e)(void),void (*right_e)(void),void (*up_e)(void),void (*down_e)(void)) {
	left_enter = left_e;
	right_enter = right_e;
	up_enter = up_e;
	down_enter = down_e;
	thread_add(getkey, NULL);
	return 0;
}

void getkey(char*) {
	if (_kbhit()) {
		char key = _getch();
		switch (key)
		{
		case LEFT:if (left_enter != NULL)(*left_enter)(); break;
		case RIGHT:if (right_enter != NULL)(*right_enter)(); break;
		case UP:if (up_enter != NULL)(*up_enter)(); break;
		case DOWN:if (down_enter != NULL)(*down_enter)(); break;
		default:
			break;
		}
	}
	return;
}
