#pragma once
#define PoolSize 20
#define DELAY_MS 200
int thread_add(void(*fun)(char*), char*);//�β�Ϊ���硰void function(char*)���ĺ���
void stop();
void threadpool_work();
void init_threadpool();
