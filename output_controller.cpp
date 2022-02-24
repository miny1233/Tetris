#include<stdio.h>
#include"output_controller.h"
#include <malloc.h>
#include<memory.h>
#include<stdlib.h>
static char* output_w;
static char* moji_buffer;
static char* output_buffer;

int init_controller() {
	char o_buffer[g_height + 2][g_width + 3];
	memset(o_buffer,' ',sizeof(o_buffer));
	for (int h = 0; h < g_height + 2; h++) {
		if (h == 0 || h == g_height + 1) {
			memset(o_buffer[h], SIGN, g_width + 2);
			o_buffer[h][g_width + 2] = '\n';
		}
		else {
			o_buffer[h][0] = SIGN;
			o_buffer[h][g_width + 1] = SIGN;
			o_buffer[h][g_width + 2] = '\n';
		}
	}
	o_buffer[g_height + 1][g_width + 2] = '\0';
	output_w = (char*)malloc((g_height + 2) * (g_width + 3));
	output_buffer = (char*)malloc((g_height + 2) * (g_width + 3));
	moji_buffer = (char*)malloc(sizeof(char) * 512);
	if (moji_buffer)memset(moji_buffer,0,512);
	else return -1;
	if (output_buffer)memcpy(output_buffer, o_buffer, (g_height + 2) * (g_width + 3));
	else return -1;
	if (output_w)memcpy(output_w, o_buffer, (g_height + 2) * (g_width + 3));
	else return -1;
	return 0;
}

void output_window(Game_Video g,int mode) 
{
	Game_Video game_video;
	memcpy(game_video, g, sizeof(Game_Video));
	if (mode == TRANSLATE_MOD)
	{
		for (int h = 0; h < g_height; h++) {
			for (int w = 0; w < g_width; w++) {
				game_video[h][w] = game_video[h][w] ? BLOCK : ' ';
			}
		}
	}
	memcpy(output_buffer, output_w, (g_height + 2) * (g_width + 3));
	for (int h = 1; h <= g_height; h++)
		memcpy((output_buffer + (g_width + 3) * h + 1), game_video[h-1], g_width);
	return;
}
int output_moji(const char* soc,int size) {
	memset(moji_buffer, '\0', sizeof(char) * 512);
	if (size > 512)return -1;
	memcpy(moji_buffer, soc, size);
	return size;
}
int output_raw(char *v_raw,int size) {
	if (size > (g_height + 2) * (g_width + 3))return -1;
	memcpy(output_buffer, v_raw, size);
	return size;
}
void out_push() {
	system("cls");
	printf("%s\n", moji_buffer);
	printf("%s", output_buffer);
	memcpy(output_buffer, output_w, (g_height + 2) * (g_width + 3));
	//memset(moji_buffer, '\0', sizeof(char) * 512);
}

