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
#define czzx     300   //�����Сֵ��С�ڴ�ֵ˵�����ʲô��û����
#define dqbz     80    //�����־����������ֵ�Ĳ�ֵ��С�ڴ�ֵ˵������
#define hddtyz   300            //�Ҷȵ�̨��ֵ
#define hdctyz   50            //�Ҷȳ�̨��ֵ
#define ceejuyz  1200           //�����ֵ
#define maxspeed 450          //����ٶ�500
#define runtime  500        //С��ǰ��ʱ��700
#define xpspeed  250          //С���ٶ�400
#define xzspeed  175      //��ת�ٶ�200
#define dtxzspeed  125      //̨����ת�ٶ�150
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

