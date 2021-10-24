#include <sys.h>
#include "OLED.h"
#include "CAMERA.h"
#include "SENSOR.h"
#include "BEEP.h"
#include "TIM.h"
#include "KEY.h"
#include "PWM.h"
#include "MOVE.h"
#include "led.h"
#define display_AI		display_GB2312_u16
#define czzx     300   //测距最小值，小于此值说明测距什么都没看到
#define dqbz     80    //对齐标志，两传感器值的差值，小于此值说明对齐
#define hddtyz   300            //灰度掉台阈值
#define hdctyz   50            //灰度出台阈值
#define ceejuyz  1200           //测距阈值
#define maxspeed 450          //最大速度500
#define runtime  500        //小跑前进时间700
#define xpspeed  350          //小跑速度400
#define xzspeed  175      //旋转速度200
#define dtxzspeed  100      //台下旋转速度150
#define enemylimit 900
#ifndef _CONTRL_H
#define _CONTRL_H
void select_fall(void);
int fangxiangflage(void);
void detection_taixia_direction(void);	
int enemynumber(void);
void start_feedback(void);
void touchsensor(void);
int Touch(void);
void attack(void);
void motor_test(void);
void test(void);
void Dection(void);
int findenemy(void);
int maxDistance(void);
#endif

