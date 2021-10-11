#include "ysy.h"//ע�ͼ�ͷ�ļ�
#include "delay.h"//ע�ͼ�ͷ�ļ�

# define front_get			    analog_scan_close()==2||analog_scan_close()==3
# define back_get				analog_scan_close()==7||analog_scan_close()==8      

# define fightveloity			300
//void GoodMoto(int lspeed,int rspeed);

int left,right;
u8 flag_1 = 0;//ǰ������̨�ı�־
extern int count_ms;
extern int Taixia;
extern int Katai;
extern int Front_thing;
extern int Left_thing;
extern int Right_thing;
extern int Behind_thing;
extern int Behind_taizi;
extern int Bianyuan;
extern int Chan_tai;
extern int Own;
extern int Behind_edge;
extern int O;

void start_feedback(void)   //����ҳ��
{
	ShowStr(2,1,"����");
//	beep();
//	led_on();
//	delay_ms(50);
//	beep();
//	led_off();
	ClearScreen();
}


void test(void)             //���Բ���
{
	int i;
	u8 Key = 0;
	ClearScreen();
	while(1)
		{
			ShowStr(0,1,"1�����������");
			ShowStr(2,1,"2��������");
			ShowStr(4,1,"3��������");
			ShowStr(6,1,"4������");
			Key=KEY_Scan(0);
			if(Key==1)
			{
				AD_Detection();
				ClearScreen();
			}
//			else if(Key==2)
//			{
//				while(1)
//				{
//					ClearScreen();
//					for(i=0;i<=180;)
//					{
//						ShowStr(0,1,"����������");
//						ShowStr(2,1,"���PWM:");
//						ShowAI(4,30,i);
//						servos(1,i);
//						servos(2,i);
//						delay_ms(100);
//						if(Touch()==1) {i++;delay_ms(100);}
//					}
//				}
//			}
			else if(Key==3)
			{
				while(1)
				{
					ClearScreen();

					for(i=0;i<=1000;)
					{
						ShowStr(0,1,"�����Ըı�");
						ShowStr(2,1,"���ת��:");
						if(i>=0)
						{
							ShowStr(4,20," ");
							ShowAI(4,30,i);
						}
						else
						{
							ShowStr(4,20,"-");
							ShowAI(4,30,-i);
						}
						//GoodMoto(i,i);
						allmotor(i,i,i,i);
//						if(Touch()==1) {i=i+50;delay_ms(500);}
						Key=KEY_Scan(0);
						if(Key==1&&i<1000)	{i=i+50;delay_ms(100);}
						else if(Key==2&&i>-1000) {i=i-50;delay_ms(100);}
						else if(Key==3) {i=-i;delay_ms(100);}
						else if(Key==4) goto end;
						Key=0;
					}
				}
			}
			else if(Key==4)
			{
				end:
				Key=0;
				break;
				ClearScreen();
			}
		}
}

void up_stage(void)         //������̨
{
    ClearScreen();
	ShowStr(2,5,"��̨");
    delay_ms(300);
    ClearScreen();

            GoodMoto(-450,-450);
            count_ms=1200;
            while(count_ms){delay_us(1);}
            GoodMoto(0,0);//ֹͣ
            count_ms=500;
            while(count_ms){delay_us(1);}
            GoodMoto(-200,200);//��ת135�ȳ�����̨�м�
            count_ms=600;
            while(count_ms){delay_us(1);}
    }
void get_edge(void)         //�޵�Ѳ̨
{
   while(Front_thing==0&&Left_thing==0&&Right_thing==0&&Behind_thing==0)
    {
        ClearScreen();    
        ShowStr(0,3,"Ѳ̨");
        GoodMoto(200,200);
        if(Bianyuan==1)
        {
          back();
//          GoodMoto(-300,-300);
//          delay_ms(600);
          turn_right90();
            break;

            
        }
        else 
            {
            GoodMoto(200,200);    
        }
    
    }

}
void select_high(void)      //̨��Ѱ��̨�Ӳ���̨
{
    while(Katai==1||Taixia==1)
    {
            ClearScreen();
            ShowStr(0,1,"̨��");
            if(Katai==1)     //��̨  
		    {
            GoodMoto(-400,-400);
            count_ms=1500;
            while(count_ms){delay_us(1);}
            }
            else if(Taixia==1)    //̨��
            {
                while(1)
                {
                GoodMoto(-100,100); 
//                if(AI(6)>1200&&AI(7)>1200&&AI(10)>1000&&AI(11)>1000&&AI(14)<350&&AI(15)<350)  //����̨��  
            if(Behind_taizi==1)  //����̨��                    
                        {
                        if((AI(6)||AI(7))>(AI(10)||AI(11)))
                        {
                            GoodMoto(-100,-100);
                            count_ms=300;
                            while(count_ms){delay_us(1);}
                        }
                        else if((AI(10)||AI(11))>(AI(6)||AI(7)))
                        {
                            GoodMoto(100,100);
                            count_ms=300;
                            while(count_ms){delay_us(1);}
                        }
                                GoodMoto(200,200); 
                                count_ms=500;
                                while(count_ms){delay_us(1);}
                                GoodMoto(0,0);
                                count_ms=200;
                                while(count_ms){delay_us(1);}
                                start_time();
                                while(1)
                                {
                                    GoodMoto(-450,-450);        //��̨
                                    if(mseconds()>1500) break;   
                                } 
                        }
              break;
                }
          }
         
    }
}

void Go_fight(void )        //ǰ��������ǰ����̨��ת180�ȷ��أ�
 {
    while(Front_thing==1&&Behind_edge==0)
    {
//        ClearScreen();
//        ShowStr(2,1,"ֱ�й���");
//        GoodMoto(300,300); 
//            if(Chan_tai==1||O==51)//ǰ����̨
//            {   
//                back();
//                GoodMoto(-125,250);//��ת180
//                start_time();
//                while(1)
//                    {
//                     if(mseconds()>400)   break;
//                    }
//               break;
//            }

//        GoodMoto(300,300); 
            if(O==51)
            {   
                ClearScreen();
                ShowStr(2,1,"����������");
                back();
                turn_right90();
                break;
                O=0;
            }
            else 
            {        
                ClearScreen();
                ShowStr(2,1,"׷�ٹ���");
                GoodMoto(left,right); 
				start_time();
                if(Bianyuan==1)
                {   
				  for(int i=0;i<=3;i++)     //��ǰ����������3��
				  {    
					GoodMoto(-fightveloity,-fightveloity);
					delay_ms(300);
				    while(1)
					{
				        GoodMoto(fightveloity,fightveloity);
						if(Bianyuan==1){ break;}
					}
				  }
				  GoodMoto(-fightveloity,-fightveloity);
				  turn_left45();
				  for(int i=0;i<=2;i++)     //���򲹵�����2��
				  {    
				    while(1)
					{
				        GoodMoto(fightveloity,fightveloity);
						if(Bianyuan==1) {break;}
					}
					GoodMoto(-fightveloity,-fightveloity);
					delay_ms(300);
				  }
				  turn_right135();
				  for(int i=0;i<=2;i++)		//�ҷ��򲹵�����2��
				  {    
				    while(1)
					{
				        GoodMoto(fightveloity,fightveloity);
						if(Bianyuan==1) {break;}
					}
					GoodMoto(-fightveloity,-fightveloity);
					delay_ms(300);
				  }
                delay_ms(600);
                }
                O=0;
                break;
            }
    }
   
}

void Xun_tai(void)          //Ѳ̨����������
{
    while(Taixia==0)
    {
        if(Bianyuan==1) back();
        else
            {
        ClearScreen();
        ShowStr(2,1,"̨��");
        if(Left_thing==1)//���������
            {
               start_time();
               ClearScreen();
               ShowStr(2,1,"���"); 
               GoodMoto(-50,150); 
//               while(Front_thing==0&&Right_thing==0&&Behind_thing==0)
               while(Front_thing==0)
               { 
                    if(mseconds()>1000) break;
               
               }              
            }
        else if(Right_thing==1)//�ұ�������
            {
               start_time();
               ClearScreen();
               ShowStr(2,1,"�Ҳ�");
               GoodMoto(150,-50); 
//              while(Front_thing==0&&Left_thing==0&&Behind_thing==0)
                while(Front_thing==0)
               { 
                    if(mseconds()>1000) break;
               
               }   
            }
        else if(Behind_thing==1)//��������
            {
               start_time();
               ClearScreen();
               ShowStr(2,1,"��");
               GoodMoto(200,-50); 
                while(Front_thing==0)
               { 
                   if(mseconds()>1000) break;
 
               }   
            }    
        else if(Front_thing==1&&Bianyuan==0)//ǰ��������
            {    
                Go_fight(); 
            }                    
//            }
        else get_edge();
     }
    }
}
    
int abs_my(int a,int b)//��ľ���ֵ
{
	if((a-b)>=0)
		return a-b;
	else
		return b-a;
}

int TrackAL(int Encoder,int Target)
{
//PID����׷���㷨����ΪΣ�գ������ջ��������Ϊ��ѡ��������//////////////////////////////////////////
/*
    float position_kp=240,position_ki=0.5,position_kd=100;
	static float Bias,Pwm,Integral_bias,Last_Bias;
	Bias=Encoder-Target;
	Integral_bias+=Bias;
	Pwm=position_kp*Bias+position_ki*Integral_bias+position_kd*(Bias-Last_Bias);
	Last_Bias=Bias;
	if(Pwm>200){
		Pwm=200;
	}
	if(Pwm<-200){
		Pwm=-200;
	}
	return Pwm;
*/
//��дPIDħ���㷨�������ԭ�ȵ�PID�㷨���������ջ����
	int pwm;
	pwm=50*(Encoder-Target);
	return pwm;
}


//	      ShowStr(0,3,"90��ת��");						 
//	     else if((abs_my(AI(0),AI(1))<400)&&(abs_my(AI(7),AI(9))<400)&&AI(2)>1000&&AI(3)>1000&&AI(8)>700&&AI(12)>1500) 
//			 {
//				  GoodMoto(400,400);  
//			    delay_ms(1000);
//			    GoodMoto(0,0);
//				  delay_ms(100);
//			    up_stage();	
//				 return 0;
//			 }				 
//	      break;







//int maxDistance(){
//	 int d[] = {AI(5), AI(6), AI(7), AI(8),AI(9), AI(10), AI(11), AI(12),AI(13), AI(14)};
//   int maxNum = d[0];
//	 int f=0;
//	 int l=f+5;
//   for (int i = 1; i < 10; i++)
//   {
//      if (maxNum < d[i])
//      {
//         maxNum = d[i];
//				 f=i;
//      }
//   }
//   return l;
//}










//void speed_dispaly(void)
//{
//	ShowStr(0,1,"��ǰ�ٶ�");
//	ShowStr(2,1,"Left      Right");
//	ShowAI(4,1,Ls);
//	ShowAI(4,80,Rs);
//}

//int abs_my(int a,int b)//��ľ���ֵ
//{
//	if((a-b)>=0)
//		return a-b;
//	else
//		return b-a;
//}

//int Touch(void)//����ADת��
//{
//	if(AI(12)>2000)
//	{
//		led_on();
//		delay_ms(10);
//		if(AI(12)>2000)
//		{
//			led_off();
//			return 1;
//		}
//	}
//	else return 0;
//}


//int analog_scan_close(void)//����������
//{
//	int j,t=0,temp=800;
//	if(AI(0)>1000&&AI(1)>1000)
//	{
//	t=9;
//	}
//	else if(AI(2)>1000&&AI(3)>1000)
//	{
//		t=10;
//	}
//	else
//	{
//	for(j=0;j<=5;j++)
//	{
//		if(temp<AI(j))
//		{
//			temp=AI(j);
//			t=j+1;
//		}
//	}
//}
//	ShowAI(4,1,t);
//	return t;
//}


//int analog_scan_far(void)//�����Զ����
//{
//	int j,t,temp=AI(1);
//	for(j=7;j<=13;j++)
//	{
//		if(temp>AI(j))
//		{
//			temp=AI(j);
//			t=j+1;
//		}
//	}
//	return t;
//}

//void touch_sensor()//����ģ��AI(12)
//{
//	u8 Key = 0;
//	ShowStr(2,0,"Touch Sensor");	
//	while(1)
//	{
//		Key=KEY_Scan(0);
//		if(Key==2)
//			{
//				delay_ms(1000);
//				ClearScreen();
//				break;
//			}
//	}
//}


//int select_high(void)//��̨���
//{
//	int i;
//	ClearScreen();
//	if(AI(0)>2490&&AI(1)>2090&&AI(2)>2600&&AI(3)>2650&&AI(4)>2650&&AI(5)>2620&&flag_1==1)//��̨
//	{
//		allmotor(0,0,0,0);//ɲ��
//		Find_Taizi();
//		return 1;
//	}
////	for(i=1;i<=7;i++)
////	{
////			if(AI(i)>1000&&AI(i+1)>1000&&AI(i+4)>1000)	//�м���һ��������һ���̶��ϼ������У�������̨ ��Ӧ�Գٶ�һ�
////			{
////				ShowStr(0,1,"��̨");
////				GoodMoto(0,0);//ɲ��
//////			touch_sensor();
////				Find_Taizi();	
////				return 1;
////			}
////	}
//	
////	if(AI(2)>1000&&AI(3)>1000&&AI(11)>1000)
////	{
////		ShowStr(0,1,"�����̨��");
////		GoodMoto(0,0);
////	  touch_sensor();
////		Find_Taizi();
////	}
////	if(AI(2)>1000&&AI(3)>1000&&AI(7)>1000)
////	{
////		ShowStr(0,1,"�����̨��");
////		GoodMoto(0,0);
////	    touch_sensor();
////		Find_Taizi();
////	}
//	return 0;//����̨��
//}

//void find_single()
//{
//	switch(analog_scan_close())
//	{
////		case 1:		//��ǰ40��
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>80)	break;//�����̨����Ե�����
////				GoodMoto(-400,400);
////			}
////			break;
////		}
//case 1:		//��ǰ
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>300||Front_thing)	break;//�����̨����Ե�����
//				allmotor(400,500,400,500);
//			
//			}
//			break;
//		}
//case 2:		//��ǰ
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>300||Front_thing)	break;//�����̨����Ե�����
//				allmotor(500,400,500,400);
//			}
//			break;
//		}
////		case 4:		//��ǰ40��
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>80)	break;//�����̨����Ե�����
////				GoodMoto(700,-700);
////			}
////			break;
////		}
////		case 5:		//��ǰ60��
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>70)	break;//�����̨����Ե�����
////				GoodMoto(800,-800);
////			}
////			break;
////		}
//case 5:		//��90��
//		{
//			reset_time();
//			while(1)
//			{
//				allmotor(500,-500,500,-500);
//				if(get_edge()||mseconds()>300||Front_thing)	break;//�����̨����Ե�����
//														} 
//			break;
//		}
//		case 6:		//��90��
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>300||Front_thing)	break;//�����̨����Ե�����
//				allmotor(-500,500,-500,500);
//			}
//			break;
//		}
////		case 7:		//�Һ�45��
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>100)	break;//�����̨����Ե�����
////				GoodMoto(800,-800);
////			}
////			break;
////		}
//		case 3:		//����
//		{
//			reset_time();
//			while(1)
//			{
//				allmotor(400,-600,400,-600);
//				if(get_edge()||mseconds()>400||Front_thing)	break;//�����̨����Ե�����
//				
//			}
//			break;
//		}
//			case 4:		//��
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>400||Front_thing)	break;//�����̨����Ե�����
//				allmotor(-600,400,-600,400);
//			}
//			break;
//		}
////				case 7:		//ǰ��
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>250||Front_thing)	break;//�����̨����Ե�����
////				allmotor(-400,-400,400,400);
////			}
////			break;
////		}
////			case 8:		//ǰ��
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>250||Front_thing)	break;//�����̨����Ե�����
////				allmotor(400,400,-400,-400);
////			}
////			break;
////		}
//					case 9:		//��ǰ
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>80)	break;//�����̨����Ե�����
//			allmotor(700,700,700,700);
//			}
//			break;
//		}
//			case 10:		//��hou
//		{
//			reset_time();
//			while(1)
//			{
//					allmotor(-700,700,-700,700);
//				if(get_edge()||mseconds()>500)	break;//�����̨����Ե�����
//		
//			}
//			break;
//		}
////		case 9:		//���45��
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>100)	break;//�����̨����Ե�����
////				GoodMoto(-800,800);
////			}
////			break;
////		}
//	
////		case 11:		//��ǰ60��
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>100)	break;//�����̨����Ե�����
////				GoodMoto(-600,800);
////			}
////			break;
////		}
//		default:
//		{
//		//	allmotor(150,150,150,150);
//			break;
//		}
//	}

