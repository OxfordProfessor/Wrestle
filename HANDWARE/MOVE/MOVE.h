#define backtime 200           //后退时间，待测
#define AI analog
#define DI digital
#define dangerblack 700
#define movetime1 5 
#define breakvalue 200
#define F_G_E			  		huidu_lvbo(0)==2 ||  huidu_lvbo(1)==2			// 前铲出擂台
#define LF_G_E					huidu_lvbo(0)==2 &&  huidu_lvbo(1)==2		// 前铲左方出擂台
#define RF_G_E					huidu_lvbo(0)==2 &&  huidu_lvbo(1)==2		// 前铲右方出擂台
#define Befor_edge			huidu_lvbo(0)==2 &&  huidu_lvbo(1)==2			// 掉台前的一个状态
#define A_S_C  0//遇敌

#include "sys.h"
#include "OLED.h"
#include "CAMERA.h"
#include "SENSOR.h"
#include "BEEP.h"
#include "TIM.h"
#include "KEY.h"
#include "PWM.h"
#ifndef _MOVE_H
#define _MOVE_H
int abs_my(int a,int b);
void touch_sensor9(void);
void up_stage1(void);
void clockwise_turn_90(void);
void anticlockwise_turn_90(void);
void up_stage(void);
void attack(void);
void  ContinueAttack(void); 

u16 averageAI(int i);
int minAI(void);
int minAIvalue(void);
void trackchannel(void);
int maxAI(void);
int maxAIvalue(void);
void forward_stop(void);
void pavetocentral(void);
void back_N45(void);
void back_S45(void);
void back(void);
void forward(void);
void back_S90(void);
void back_N90(void);
void back_N60(void);
void back_S60(void);
void back_180(void);
void forward2(void);
void back2(void);
void back_2N45(void);
void back_2S45(void);
void back_2180();
void edage();
void edge_spin(void);
int BlackFilter0(void);
int BlackFilter1(void);
void attack1(void);
#endif
