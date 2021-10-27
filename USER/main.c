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
//δ��������ɣ��������������κ���;
//STM32F407VET6����
//���ߣ����������ſ���
//�汾��V6.1
//��������Ȩ��
//All rights reserved
///////////////////////////////////////////////////////////////////////

/*
�޸����ڣ�2021-07-14  23��28
	δ������� ��������
	 1. Ѱ̨����ٶȣ��Ҷ�ǽ��С
	 2. �����ٶȣ�����Ѱ̨�ٶ�
	 3. �ٶȵĴ���ʽ
	 4. Ѱ̨��ת�ٶ�
	 5. ��Ե���ĻҶ�ֵ�Լ���Եʱ�˺��ֵ
	 6. ����������Ĳ�ഫ������ֵ
	 
	 *********************************************���������2021-7-17 1��45����Ҫ������ֱ�ߵ��ٶ���************************
	 *********************************************��̨�ٶȣ���Ե����ٶȣ������ٶ�*****************************************
/*
�����:
              4. ǰ�����Ҷȴ�����ʵ�ʲ���(�����)
              �տ�ʼ����Լ�����һ����(��д)
              ����ͷ�������ݲ�������д���أ��Ѽ򵥴���
							Ѱ̨�㷨��ܣ�������ֻ��΢��
*/
void Car_Init()
{		  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//ʹ��GPIODʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//ʹ��GPIODʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//ʹ��GPIODʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//ʹ��GPIODʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);//ʹ��GPIODʱ��
	delay_init(168);
//	start_time_1();
	KEY_Init();	
	PWM_Init();
	SENSOR_Init();
	USART3_Init();  //������Ϊ115200
	BEEP_Init();
  OLED_Init();
	LED_Init();    
	TIM2_Int_Init(1000-1,84-1);	
	ClearScreen();
	Dection();
	ShowStr(0,1,"��ӭ��");
	ShowStr(4,1,"ʹ����Ȩ�ӳ���");
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
		ShowStr(0,1,"1.���ģʽ");
		ShowStr(2,1,"2.������");
		ShowStr(4,1,"3.������");
		ShowStr(6,1,"4.����");
		Key = KEY_Scan(0);
		if(Key != 0)   Key_Temp = Key;
		if(Key_Temp==1)//����1�����************���������
		{
  			test();   
		}
		else if(Key_Temp==2)//����2�����************������
		{
        motor_test();
		}
		else if(Key_Temp==3)
		{

//			  touch_sensor9();
//			  up_stage();
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
		else if(Key_Temp==4)//����4�����******************����
		  {
			  ClearScreen();
	    }
	 }
}