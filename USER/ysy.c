#include "ysy.h"//注释见头文件
#include "delay.h"//注释见头文件

# define front_get			    analog_scan_close()==2||analog_scan_close()==3
# define back_get				analog_scan_close()==7||analog_scan_close()==8      


//void GoodMoto(int lspeed,int rspeed);

   
u8 flag_1 = 0;//前铲出擂台的标志
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
extern int left,right;
extern int b[1];

void start_feedback(void)   //开机页面
{
	ShowStr(2,1,"玉衡队");
//	beep();
//	led_on();
//	delay_ms(50);
//	beep();
//	led_off();
	ClearScreen();
}


void test(void)             //屏显测试
{
	int i;
	u8 Key = 0;
	ClearScreen();
	while(1)
		{
			ShowStr(0,1,"1、传感器检测");
			ShowStr(2,1,"2、舵机检测");
			ShowStr(4,1,"3、电机检测");
			ShowStr(6,1,"4、返回");
			Key=KEY_Scan(0);
			if(Key==1)
			{
				AD_Detection();
				ClearScreen();
			}
			else if(Key==2)
			{
				while(1)
				{
					ClearScreen();
					GoodMoto(400,400);       //测100到199，200到299，300到399，400到499
					if(mseconds()>2000){GoodMoto(0,0); break;}
				}
			}
			else if(Key==3)
			{
				while(1)
				{
					ClearScreen();

					for(i=0;i<=1000;)
					{
						ShowStr(0,1,"按键以改变");
						ShowStr(2,1,"电机转速:");
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

void up_stage(void)         //开机上台
{
    ClearScreen();
	ShowStr(2,5,"上台");
    delay_ms(300);
    ClearScreen();

            GoodMoto(-450,-450);
            count_ms=1200;
            while(count_ms){delay_us(1);}
            GoodMoto(0,0);//停止
            count_ms=500;
            while(count_ms){delay_us(1);}
            GoodMoto(-200,200);//左转135度朝向擂台中间
            count_ms=600;
            while(count_ms){delay_us(1);}
}
void up_stage1(void)         //开机上台
{
    ClearScreen();
	ShowStr(2,5,"上台");
    delay_ms(300);
    ClearScreen();

            GoodMoto(-550,-550);
            count_ms=1500;
            while(count_ms){delay_us(1);}
            GoodMoto(0,0);//停止
            count_ms=500;
            while(count_ms){delay_us(1);}
            GoodMoto(-200,200);//左转135度朝向擂台中间
            count_ms=600;
            while(count_ms){delay_us(1);}
    }

void get_edge(void)         //无敌巡台
{
   while(Front_thing==0&&Left_thing==0&&Right_thing==0&&Behind_thing==0)
    {
        ClearScreen();    
        ShowStr(0,3,"巡台");
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
void select_high(void)      //台下寻找台子并登台
{
    while(Taixia==1)
    {
            ClearScreen();
            ShowStr(0,1,"台下");
            if(Taixia==1)    //台下
            {
//                if(AI(6)>1200&&AI(7)>1200&&AI(10)>1000&&AI(11)>1000&&AI(14)<350&&AI(15)<350)  //对齐台子  
						while(Behind_taizi==0)  //对齐台子    
						{
							GoodMoto(-50,50); 
						}
							GoodMoto(200,200);
							count_ms=500;
							while(count_ms){delay_us(1);}
							up_stage1();
							Taixia=0;
			
//							if((AI(6)||AI(7))>(AI(10)||AI(11)))
//							{
//                            GoodMoto(-100,-100);
//                            count_ms=300;
//                            while(count_ms){delay_us(1);}
//							}
//                        else if((AI(10)||AI(11))>(AI(6)||AI(7)))
//                        {
//                            GoodMoto(100,100);
//                            count_ms=300;
//                            while(count_ms){delay_us(1);}
//                        }
//                                GoodMoto(200,200); 
//                                count_ms=500;
//                                while(count_ms){delay_us(1);}
//                                GoodMoto(0,0);
//                                count_ms=200;
//                                while(count_ms){delay_us(1);}
//                                start_time();
//                                while(1)
//                                {
//                                    GoodMoto(-450,-450);        //登台
//                                    if(mseconds()>1500) break;   
//                                } 
                       
          }
         
    }
}

void Go_fight(void )        //前进攻击（前铲出台左转180度返回）
 {
    while(Front_thing==1&&Behind_edge==0)
    {
//        ClearScreen();
//        ShowStr(2,1,"直行攻击");
//        GoodMoto(300,300); 
//            if(Chan_tai==1||O==51)//前铲出台
//            {   
//                back();
//                GoodMoto(-125,250);//左转180
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
                ShowStr(2,1,"己方能量块");
				back1();
                turn_right90();
				GoodMoto(300,300);
                break;
				O=0;
            }
            else 
            {        
                ClearScreen();
                ShowStr(2,1,"直行攻击");
				while(Bianyuan==0){
					GoodMoto(left,right); 
				}
				GoodMoto(-400,-400);
				delay_ms(300);
				turn_right90();
			}
			O=0;
			break;
		}

   
}

void Xun_tai(void)          //巡台（含攻击）
{
    while(Taixia==0)
    {
//        if(Bianyuan==1) back();
//        ClearScreen();
//        ShowStr(2,1,"台上");
        if(Left_thing==1)//左边有物体
            {
               start_time();
               ClearScreen();
               ShowStr(2,1,"左侧"); 
//               while(Front_thing==0&&Right_thing==0&&Behind_thing==0)
               while(Front_thing==0)
               { 
                    GoodMoto(100,-100); 
               
               }              
            }
        else if(Right_thing==1)//右边有物体
            {
               start_time();
               ClearScreen();
               ShowStr(2,1,"右侧");
//              while(Front_thing==0&&Left_thing==0&&Behind_thing==0)
                while(Front_thing==0)
               { 
                    GoodMoto(-100,100); 
               
               }   
            }
        else if(Behind_thing==1)//后方有物体
            {
               start_time();
               ClearScreen();
               ShowStr(2,1,"后方");
                while(Front_thing==0)
               { 
                   GoodMoto(200,-200); 
               }   
            }    
        else if(Front_thing==1&&Bianyuan==0)//前方有物体
            {    
                Go_fight(); 
            }                    
//            }
        else get_edge();
     }
 }

    



















//	      ShowStr(0,3,"90度转弯");						 
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
//	ShowStr(0,1,"当前速度");
//	ShowStr(2,1,"Left      Right");
//	ShowAI(4,1,Ls);
//	ShowAI(4,80,Rs);
//}

//int abs_my(int a,int b)//差的绝对值
//{
//	if((a-b)>=0)
//		return a-b;
//	else
//		return b-a;
//}

//int Touch(void)//触摸AD转换
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


//int analog_scan_close(void)//检测最近物体
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


//int analog_scan_far(void)//检测最远物体
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

//void touch_sensor()//触摸模块AI(12)
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


//int select_high(void)//掉台检测
//{
//	int i;
//	ClearScreen();
//	if(AI(0)>2490&&AI(1)>2090&&AI(2)>2600&&AI(3)>2650&&AI(4)>2650&&AI(5)>2620&&flag_1==1)//掉台
//	{
//		allmotor(0,0,0,0);//刹车
//		Find_Taizi();
//		return 1;
//	}
////	for(i=1;i<=7;i++)
////	{
////			if(AI(i)>1000&&AI(i+1)>1000&&AI(i+4)>1000)	//中间多加一个条件，一定程度上减少误判，但检测掉台 反应稍迟顿一�
////			{
////				ShowStr(0,1,"掉台");
////				GoodMoto(0,0);//刹车
//////			touch_sensor();
////				Find_Taizi();	
////				return 1;
////			}
////	}
//	
////	if(AI(2)>1000&&AI(3)>1000&&AI(11)>1000)
////	{
////		ShowStr(0,1,"特殊掉台左");
////		GoodMoto(0,0);
////	  touch_sensor();
////		Find_Taizi();
////	}
////	if(AI(2)>1000&&AI(3)>1000&&AI(7)>1000)
////	{
////		ShowStr(0,1,"特殊掉台右");
////		GoodMoto(0,0);
////	    touch_sensor();
////		Find_Taizi();
////	}
//	return 0;//还在台上
//}

//void find_single()
//{
//	switch(analog_scan_close())
//	{
////		case 1:		//左前40度
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>80)	break;//处理掉台、边缘等情况
////				GoodMoto(-400,400);
////			}
////			break;
////		}
//case 1:		//左前
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>300||Front_thing)	break;//处理掉台、边缘等情况
//				allmotor(400,500,400,500);
//			
//			}
//			break;
//		}
//case 2:		//右前
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>300||Front_thing)	break;//处理掉台、边缘等情况
//				allmotor(500,400,500,400);
//			}
//			break;
//		}
////		case 4:		//右前40度
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>80)	break;//处理掉台、边缘等情况
////				GoodMoto(700,-700);
////			}
////			break;
////		}
////		case 5:		//右前60度
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>70)	break;//处理掉台、边缘等情况
////				GoodMoto(800,-800);
////			}
////			break;
////		}
//case 5:		//右90度
//		{
//			reset_time();
//			while(1)
//			{
//				allmotor(500,-500,500,-500);
//				if(get_edge()||mseconds()>300||Front_thing)	break;//处理掉台、边缘等情况
//														} 
//			break;
//		}
//		case 6:		//左90度
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>300||Front_thing)	break;//处理掉台、边缘等情况
//				allmotor(-500,500,-500,500);
//			}
//			break;
//		}
////		case 7:		//右后45度
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>100)	break;//处理掉台、边缘等情况
////				GoodMoto(800,-800);
////			}
////			break;
////		}
//		case 3:		//后左
//		{
//			reset_time();
//			while(1)
//			{
//				allmotor(400,-600,400,-600);
//				if(get_edge()||mseconds()>400||Front_thing)	break;//处理掉台、边缘等情况
//				
//			}
//			break;
//		}
//			case 4:		//后
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>400||Front_thing)	break;//处理掉台、边缘等情况
//				allmotor(-600,400,-600,400);
//			}
//			break;
//		}
////				case 7:		//前左
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>250||Front_thing)	break;//处理掉台、边缘等情况
////				allmotor(-400,-400,400,400);
////			}
////			break;
////		}
////			case 8:		//前右
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>250||Front_thing)	break;//处理掉台、边缘等情况
////				allmotor(400,400,-400,-400);
////			}
////			break;
////		}
//					case 9:		//正前
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>80)	break;//处理掉台、边缘等情况
//			allmotor(700,700,700,700);
//			}
//			break;
//		}
//			case 10:		//正hou
//		{
//			reset_time();
//			while(1)
//			{
//					allmotor(-700,700,-700,700);
//				if(get_edge()||mseconds()>500)	break;//处理掉台、边缘等情况
//		
//			}
//			break;
//		}
////		case 9:		//左后45度
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>100)	break;//处理掉台、边缘等情况
////				GoodMoto(-800,800);
////			}
////			break;
////		}
//	
////		case 11:		//左前60度
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>100)	break;//处理掉台、边缘等情况
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

