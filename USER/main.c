/********************************************
* �汾:	TheMonster_1.1_2017.08.09
*********************************************/
#include "init.h"
#include "function.h"		//����ҵ����ϸ�ӳ������ϸģ����򶼷���function.hͷ�ļ���main.c�ļ���Ҫд�ܵ�ģ�����
#include "ysy.h"				//2017.10
#include "edge.h"
#include "oled.h"
#include "usart.h"

#define AI 							analog
#define DI							digital
#define ClearScreen 		        clear_screen
#define ShowStr 				    OLED_Display_GB2312_string  //�ַ�����ʾ
#define ShowAI					    display_GB2312_u16          //��λ����
#define ShowDI					    display_GB2312_u1		    //һλ����
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
	start_feedback();//��������
//	while(1)
//	{

//          get_edge();
//        ClearScreen();
//        ShowStr(2,1,"ֱ�й���");
//        GoodMoto(300,300); 
//            if(Chan_tai==1||O==51)//ǰ����̨
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
//		 GPIO_SetBits(GPIOD,GPIO_Pin_11);  //��������Ӧ����GPIOF8���ͣ�
//		 delay_ms(1000);
//		 GPIO_ResetBits(GPIOD,GPIO_Pin_11);  //��������Ӧ����GPIOF8���ͣ�
//		 delay_ms(1000);
//        led_on();
//        beep();
		Key = KEY_Scan(0);
		Key_Temp = Key;
		ShowStr(0,1,"1.����ģʽ");
		ShowStr(2,1,"2.��������");
		ShowStr(4,1,"3.������");
		ShowStr(6,1,"4.����");
		Key = KEY_Scan(0);
		if(Key != 0) Key_Temp = Key;
		if(Key_Temp==1)//����1�����************���������
		{
			test();
		}
		else if(Key_Temp==2)//����2�����************������
		{
			reset_time();
            ClearScreen();
            

                        
			while(1)        //����
			{
				if(AI(8)>800&&AI(9)>800)
                break;
            }
           up_stage();     //��̨
			while(1)
			{
//				ShowAI(2,1,Behind_taizi);
                Xun_tai();     //Ѳ̨	
               select_high();  //��̨����̨����̨
//		        find_single();
		
			}
		}
		else if(Key_Temp==3)//����3�����*****************������
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
		else if(Key_Temp==4)//����4�����******************����
		{
				
			ClearScreen();
			//touch_sensor();
		}
	}
}