/********************************************
* 版本:	TheMonster_1.1_2017.08.09
*********************************************/
#include "init.h"
#include "function.h"		//所有业务详细子程序和详细模块程序都放在function.h头文件，main.c文件主要写跑的模块程序。
#include "ysy.h"				//2017.10
#include "edge.h"
#include "oled.h"
#include "usart.h"

#define AI 							analog
#define DI							digital
#define ClearScreen 		        clear_screen
#define ShowStr 				    OLED_Display_GB2312_string  //字符串显示
#define ShowAI					    display_GB2312_u16          //四位数显
#define ShowDI					    display_GB2312_u1		    //一位数显
#define ServoSetMode		        UP_CDS_SetMode					
#define ServoSetAngle		        UP_CDS_SetAngle	

void RobotInit(void);
void AD_Detection(void);
void Openmv_find();
void GoodMoto(int lspeed,int rspeed);

u8 Key = 0;
u8 Key_Temp = 0;
extern int Rs,Ls;
extern int O;
extern int Chan_tai;
extern int Behind_taizi;

int temp,t=0;
int i,n=0;
int b[1];
int main(void)
{
	MarineRobot_init();
	start_feedback();//启动反馈
//	while(1)
//	{

//          get_edge();
//        ClearScreen();
//        ShowStr(2,1,"直行攻击");
//        GoodMoto(300,300); 
//            if(Chan_tai==1||O==51)//前铲出台
//            {   
//                back();
//                turn_right90();
//                break;
//            }
//    }
//        
//		GoodMoto(400,0);
//		delay_ms(1000);
//		delay_ms(1000);
//		allmotor(-900, -900, -900, -900);
//		delay_ms(1000);
//		delay_ms(1000);
//		allmotor(0, 0, 0, 0);
//		delay_ms(1000);
//		delay_ms(1000);
//	}
	
	while(1)
	{
//		 GPIO_SetBits(GPIOD,GPIO_Pin_11);  //蜂鸣器对应引脚GPIOF8拉低，
//		 delay_ms(1000);
//		 GPIO_ResetBits(GPIOD,GPIO_Pin_11);  //蜂鸣器对应引脚GPIOF8拉低，
//		 delay_ms(1000);
//        led_on();
//        beep();
		Key = KEY_Scan(0);
		Key_Temp = Key;
		ShowStr(0,1,"1.测量模式");
		ShowStr(2,1,"2.启动程序");
		ShowStr(4,1,"3.摄像检测");
		ShowStr(6,1,"4.返回");
		Key = KEY_Scan(0);
		if(Key != 0) Key_Temp = Key;
		if(Key_Temp==1)//按键1程序段************传感器检测
		{
			test();
		}
		else if(Key_Temp==2)//按键2程序段************主程序
		{
			reset_time();
            ClearScreen();
            

                        
			while(1)        //软起动
			{
				if(AI(8)>800&&AI(9)>800)
                break;
            }
           up_stage();     //上台
			while(1)
			{
//				ShowAI(2,1,Behind_taizi);
                Xun_tai();     //巡台	
               select_high();  //掉台（卡台）登台
//		        find_single();
		
			}
		}
		else if(Key_Temp==3)//按键3程序段*****************摄像检测
		{
			ClearScreen();
			while(1)
			{
            
				ShowAI(2,1,O);
//				if(DI(1)==1)
//				{
//					while(1)
//					{
//						if(DI(1)==0)
//						{
//							n=n+1;
//							break;
//						}
//				}
//				}
		    }
//			up_stage();
//			GoodMoto(0,0);
		}
		else if(Key_Temp==4)//按键4程序段******************返回
		{
				
			ClearScreen();
			//touch_sensor();
		}
	}
}