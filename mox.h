#pragma once
void rotate(GameObject* ch);
static char L[4][4] = {
	0,0,0,0,
	0,1,0,0,
	0,1,0,0,
	0,1,1,0
};
static char I[4][4] = {
	0,1,0,0,
	0,1,0,0,
	0,1,0,0,
	0,1,0,0
};
static char Z[4][4] = {
	0,0,0,0,
	1,1,0,0,
	0,1,1,0,
	0,0,0,0
};
static char R[4][4] = {
	0,0,0,0,
	0,1,1,0,
	0,1,1,0,
	0,0,0,0
};
static char T[4][4] = {
	0,0,0,0,
	0,1,0,0,
	1,1,1,0,
	0,0,0,0
};