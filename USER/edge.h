#include "init.h"

#define AI 							analog
#define DI							digital
#define ClearScreen 		clear_screen
#define ShowStr 				display_GB2312_string		//字符串数显
#define ShowAI					display_GB2312_u16 //四位数显
#define ShowDI					display_GB2312_u1		//一位数显
#define ServoSetMode		UP_CDS_SetMode					
#define ServoSetAngle		UP_CDS_SetAngle

int get_edge(void);//巡台
void back(void);             //倒车  （计时200/检测到物体——停止）
void forward_stop(void);    //倒车  （计时200——停止）
void turn_left90(void);     //左转90（计时200/前检测到物体——停止）
void turn_right90(void);     //右转90（计时200/前检测到物体——停止）