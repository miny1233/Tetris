#include"ThreadPool.h"
#include<stdio.h>
#include<Windows.h>
static void (*func[PoolSize])(char*);
static char* avg[PoolSize];
static int nub, kill;
void init_threadpool() {
	nub = 0;
	kill = 0;
	return;
}
int thread_add(void(*fun)(char*),char *c) {
	if (nub >= PoolSize)return -1;
	avg[nub] = c;
	func[nub] = fun;
	nub++;
	return 0;
}
void threadpool_work() {
	while (!kill) {
		for (int round = 0; round < nub; round++)(*func[round])(avg[round]);
		Sleep(DELAY_MS);
	}
	return;
}
void stop() {
	kill = 1;
	return;
}