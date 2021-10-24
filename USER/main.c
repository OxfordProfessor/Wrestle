#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
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
#include "CONTRAL.h"

///////////////////////////////////////////////////////////////////////
//未经作者许可，不得用于其他任何用途
//STM32F407VET6主控
//作者：马旭阳，张凯洋
//版本：V5.2
//保留所有权力
//All rights reserved
///////////////////////////////////////////////////////////////////////

/*
修改日期：2021-07-14  23：28
	未完成任务： 调试任务：
	 1. 寻台最大速度，灰度墙大小
	 2. 攻击速度，攻击寻台速度
	 3. 速度的处理方式
	 4. 寻台旋转速度
	 5. 边缘检测的灰度值以及边缘时退后的值
	 6. 发现能量块的测距传感器阈值
	 
	 *********************************************更换电机（2021-7-17 1：45）需要调试走直线的速度有************************
	 *********************************************上台速度，边缘检测速度，进攻速度*****************************************
/*
已完成:
              4. 前铲两灰度处理后的实际测量(已完成)
              刚开始检测自己是哪一方的(已写)
              摄像头返回数据并处理（已写返回，已简单处理）
							寻台算法框架，接下来只需微调
*/
void Car_Init()
{		  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能GPIOD时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//使能GPIOD时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//使能GPIOD时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//使能GPIOD时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);//使能GPIOD时钟
	delay_init(168);
//	start_time_1();
	KEY_Init();	
	PWM_Init();
	SENSOR_Init();
	USART3_Init();  //波特率为115200
	BEEP_Init();
  OLED_Init();
	LED_Init();    
	TIM2_Int_Init(1000-1,84-1);	
	ClearScreen();
	Dection();
	ShowStr(0,1,"欢迎您");
	ShowStr(4,1,"使用天权队程序");
	ShowStr(6,1,"Right Reversed");
	delay_ms(1000);
	ClearScreen();
}
u8 Key = 0;
u8 Key_Temp = 0;
unsigned char c[100];
extern int Rs,Ls;
extern int a[3];
extern int taixia;
int temp,t=0;
int i,n=0;
extern int HUANGFANGflag,LANFANGflag;

int main(void)
{
	Car_Init();
	while(1)
	{
		Key = KEY_Scan(0);
		Key_Temp = Key;
		ShowStr(0,1,"1.检测模式");
		ShowStr(2,1,"2.主程序");
		ShowStr(4,1,"3.电机检测");
		ShowStr(6,1,"4.返回");
		Key = KEY_Scan(0);
		if(Key != 0)   Key_Temp = Key;
		if(Key_Temp==1)//按键1程序段************传感器检测
		{
  			test();   
		}
		else if(Key_Temp==2)//按键2程序段************主程序
		{
        motor_test();
		}
		else if(Key_Temp==3)
		{

			  touch_sensor9();
			  up_stage();
			  TIM5_Int_Init(50-1,8400-1);
			  ClearScreen();
				while(1)
				{
					if(taixia==0)
					{		
						findenemy();
					}
					else
					{
						detection_taixia_direction();
					}
				 }
	   }
		else if(Key_Temp==4)//按键4程序段******************返回
		  {
			  ClearScreen();
	    }
	 }
}