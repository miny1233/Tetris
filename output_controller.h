#pragma once
#define g_height 15 //��Ϸ���ڸ߶�
#define g_width 10  //��Ϸ���ڿ��
#define SIGN '*'//���ڱ߿�
#define BLOCK '#'
#define RAW_MOD 1
#define TRANSLATE_MOD 0
typedef char Game_Video[g_height][g_width];
int init_controller();//��ʼ��������
void output_window(char[g_height][g_width],int);//������ʾ�������ϸ���Ҫ��Ĵ�С��
int output_moji(const char*, int);//������ʾ
void out_push();//ˢ����ʾ
int output_raw(char*,int);//ԭʼ��ʾ��ע����󳤶�Ϊ ��g_height + 2) * (g_width + 3)��