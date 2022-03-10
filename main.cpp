#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<memory>
#include"ThreadPool.h"
#include"output_controller.h"
#include"input_controller.h"
#include"Game_Engine.h"
#include"mox.h"
#include <string>
GameObject* game;
void m() {
	
	srand((unsigned)time(NULL));
	switch (rand() % 5 + 1) {
	case 1:memcpy(game->image, L, 16); break;
	case 2:memcpy(game->image, I, 16); break;
	case 3:memcpy(game->image, Z, 16); break;
	case 4:memcpy(game->image, R, 16); break;
	case 5:memcpy(game->image, T, 16); break;
	}
	game->position_x = 5; game->position_y = 0;
}
void mk(char* cp) {
	make_gameobject((GameObject*)cp);
}
int main() {
	init_threadpool();
	init_controller();
	init_ge(m);
	game = (GameObject*)malloc(sizeof(GameObject));
	memcpy(game->image, L, 16);
	game->position_x = 5; game->position_y = 0;
	make_gameobject(game);
	threadpool_work();
	return 0;
}

