#pragma once
#define g_height 15 //游戏窗口高度
#define g_width 10  //游戏窗口宽度
#define SIGN '*'//窗口边框
#define BLOCK '#'
#define RAW_MOD 1
#define TRANSLATE_MOD 0
typedef char Game_Video[g_height][g_width];
int init_controller();//初始化控制器
void output_window(char[g_height][g_width],int);//窗口显示（必须严格按照要求的大小）
int output_moji(const char*, int);//文字显示
void out_push();//刷新显示
int output_raw(char*,int);//原始显示（注意最大长度为 （g_height + 2) * (g_width + 3)）