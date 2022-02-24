#include<memory.h>
#include"Game_Engine.h"
void rotate(GameObject* ch)
{
	int i, j;
	char ap[4][4];
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			ap[i][3 - j] = ch->image[j][i];
	memcpy(ch->image, ap, 16);
	return;
}