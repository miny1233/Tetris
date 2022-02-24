#include"Game_Engine.h"
#include"input_controller.h"
#include"output_controller.h"
#include"ThreadPool.h"
#include"mox.h"
#include<memory.h>
#include <malloc.h>
#include<stdio.h>
#include<string>
void render(GameObject object, int mode);
void Update(char*);
void CAC_();
GameObject* gobj;
Game_Video game_world;
char* line_t;
int i = 0;
int score = 0;
static void (*replace)();
int collision(GameObject gameo,int mode) {
	int px[4] = { -1 }, py[4] = { -1 };
	int i = 0;
	switch (mode)
	{
	case DOWN_C:
		for (int x = 0; x < 4; x++) {
			for (int y = 3; y >= 0; y--) {
				if (gameo.image[y][x]) {
					px[i] = x;
					py[i] = y;
					i++;
					break;
				}
			}
		}
		for (i = 0; i < 4; i++) {
			if (py[i] >= -1) {
				if (gameo.position_y + py[i] + 1 == g_height)return 1;
				if (game_world[py[i] + gameo.position_y + 1][px[i] + gameo.position_x])return 1;
			}
		}
		return 0;
		break;
	case LEFT_C:
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				if (gameo.image[y][x]) {
					px[i] = x;
					py[i++] = y;
					break;
				}
			}
		}
		for (i = 0; i < 4; i++) {
			if (px[i] != -1) {
				if (gameo.position_x + px[i] == 0)return 1;
				if (game_world[py[i] + gameo.position_y ][px[i] + gameo.position_x - 1])return 1;
			}
		}
		return 0;
		break;
	case RIGHT_C:
		for (int y = 0; y < 4; y++) {
			for (int x = 3; x>=0; x--) {
				if (gameo.image[y][x]) {
					px[i] = x;
					py[i++] = y;
					break;
				}
			}
		}
		for (i = 0; i < 4; i++) {
			if (px[i] != -1) {
				if (gameo.position_x + px[i] + 1 == g_width)return 1;
				if (game_world[py[i] + gameo.position_y][px[i] + gameo.position_x + 1])return 1;
			}
		}
		return 0;
		break;
	default:
		return -1;
	}
}
int init_ge(void(*re)()) {
	replace = re;
	if ((line_t = (char*)malloc(g_width)) == 0)return -1;
	memset(line_t, 1, g_width);
	memset(game_world, 0, sizeof(Game_Video));
	init_input_controller(g_left,g_right,g_up, g_down);
	thread_add(Update,NULL);
	return 0;
}
void make_gameobject(GameObject* object) {
	gobj = object;
}
void g_down() {
	//int count = 0;
	if (!collision(*gobj, DOWN_C)) {
		render(*gobj, CLEAN_MOD);
		gobj->position_y++;
		render(*gobj, NEW_MOD);
	}
	else
	{
		CAC_();
	}
}
void g_up()
{
	render(*gobj, CLEAN_MOD);
	rotate(gobj);
	render(*gobj, NEW_MOD);
}
void g_left() {
	//int count = 0;
	if (!collision(*gobj, LEFT_C)) {
		render(*gobj, CLEAN_MOD);
		gobj->position_x--;
		render(*gobj, NEW_MOD);
	}
}
void g_right() {
	//int count = 0;
	if (!collision(*gobj, RIGHT_C)) {
		render(*gobj, CLEAN_MOD);
		gobj->position_x++;
		render(*gobj, NEW_MOD);
	}
}
void Update(char*) {
	if (++i == 4) {
		i = 0; //int count = 0;
		
		if (!collision(*gobj,DOWN_C)) {
				render(*gobj, CLEAN_MOD);
				gobj->position_y++;
				render(*gobj, NEW_MOD);
		}
		else
		{
			
			CAC_();
		}
	}
}
void render(GameObject object, int mode) {
	if (mode == CLEAN_MOD) {
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				if (object.position_y + y <= g_height - 1 && object.position_x + x <= g_width - 1) if (object.image[y][x])game_world[object.position_y + y][object.position_x + x] = 0;
			}
		}
	}
	if (mode == NEW_MOD) {
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				if(object.position_y+y<=g_height-1&&object.position_x+x<=g_width-1)game_world[object.position_y + y][object.position_x + x] = game_world[object.position_y + y][object.position_x + x] + object.image[y][x] ? 1 : 0;
			}
		}
		output_window(game_world, TRANSLATE_MOD);
		out_push();
	}
}
int cheakline() {

	for (int i = g_height - 1; i >= 0; i--)
	{
		if (!memcmp(game_world[i], line_t, g_width)) return i;
	}return -1;

}
void CAC_() {
	while (1)
	{
		int i = cheakline();
		if (i == -1) {
			(*replace)();
			return;
		}
			memset(game_world[i], 0, g_width);
		for (int l = i - 1; l >= 0; l--)
		{
			memcpy(game_world[l + 1], game_world[l], g_width);
			memset(game_world[l], 0, g_width);
			output_window(game_world, TRANSLATE_MOD);
			score += 10;
			std::string sc = "你的分数是:" + std::to_string(score);
			output_moji(sc.c_str(), sc.size());
			out_push();
		}
	}
}