#pragma once
#define PoolSize 20
#define DELAY_MS 200
int thread_add(void(*fun)(char*), char*);//形参为形如“void function(char*)”的函数
void stop();
void threadpool_work();
void init_threadpool();
