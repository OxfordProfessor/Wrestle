#include "CONTRAL.h"
#include "MOVE.h"
#define HUANGFANG	(AI(2)<120 && AI(2)>60)
#define LANFANG	 (AI(2)<240 && AI(2)>150)
#define FUKONG    (HUI0<hdctyz)&&(HUI1<hdctyz)&&(HUI2<hdctyz)&&(HUI3<hdctyz)&&(HUI4<hdctyz)
#define taixia1  ((hdctyz<HUI2)&&(HUI2<hddtyz))&&((hdctyz<HUI3)&&(HUI3<hddtyz))&&((hdctyz<HUI4)&&(HUI4<hddtyz))&&(enemynumber()>2)
extern u16 hui0[5],hui1[5],hui2[5],hui3[5],hui4[5];
extern u16 HUI0,HUI1,HUI2,HUI3,HUI4;
extern int receive;
extern u16 ceju5,ceju6,ceju7,ceju8,ceju9,ceju10,ceju11,ceju12,ceju13,ceju14,ceju15;
#define weibuduiqi  ((abs_my(AI(7),AI(8))<dqbz)&&(AI(15)<czzx)&&((AI(9)<1000)&&(AI(10)<1000))&&(abs_my(AI(5),AI(6))<dqbz))
//#define weibuduiqi  ((abs_my(ceju7,ceju8)<dqbz)&&(ceju15<czzx)&&((ceju9<czzx)&&(ceju10<czzx))&&(abs_my(ceju5,ceju6)<dqbz))  //尾部两个对齐，中间检测不到或者左后右后检测不到
int DIREN=51;
int attck_speed = 350;
extern int position;
int drcjz = 750;
#if HUANGFANGflag
#define DIREN  51
#endif
	
#if LANGFANGflag
#define DIREN  53
#endif
//这个文件写机器人动作控制（寻台，上台（台下
//寻找位置），掉台检测（侧身掉台），攻击，......）
extern int a[3];
extern unsigned char c[100];
int taixia;
int qiangjiao=0;
u8 tt=0;
unsigned char b[100];
int HUANGFANGflag,LANFANGflag;

void Dection(){
  if(HUANGFANG){
	  HUANGFANGflag=1;
		LANFANGflag=0;
  }
	if(LANFANG){
		HUANGFANGflag=0;
		LANFANGflag=1;
	}
}

int findenemy()
{
	int i;
	switch(position)
	{
		case 0:
		{
			while(1)
			{
				trackchannel();
			  if(position!=0)	
				{
					GoodMoto(0,0);
					break;			
				}
		  }
		}
		break;
	  case 1:           //正前方遇到敌人
		{
			GoodMoto(0,0);
			delay_ms(200);
			start_time();
		 if(receive==53)
		 {
		 		back_N60();
			  GoodMoto(300,300);
	   }
		 else
		 {
				while(1)
				{
					GoodMoto(attck_speed,attck_speed);
					if(AI(0)<drcjz||AI(1)<drcjz)	
					{
						edage();	
						break;
					}
				}				
			}
	  }
		break;
		case 2:        //右前方遇到敌人
		{
			start_time();
			while(1)
			{
				GoodMoto(100,-100);
				if(AI(0)<drcjz||AI(1)<drcjz||position==1)	{
				GoodMoto(0,0);
				break;//处理掉台、边缘等情况
				}
			}
		}
		break;
		case 3:        //右方遇到敌人
		{
			start_time();
			while(1)
			{
				GoodMoto(100,-100);
				if(AI(0)<drcjz||AI(1)<drcjz||position==1){	
					GoodMoto(0,0);
					break;//处理掉台、边缘等情况
				}
			}
			GoodMoto(0,0);
		}
		break;
		case 4:    //右后
		{
			start_time();
			while(1)
			{
				GoodMoto(100,-100);
				if(AI(0)<drcjz||AI(1)<drcjz||position==1){
					GoodMoto(0,0);
					break;//处理掉台、边缘等情况
				}
			}		
		}
		break;
		case 5:       //正后方
		{
			start_time();
			while(1)
			{
				GoodMoto(-100,100);
				if(AI(0)<drcjz||AI(1)<drcjz||position==1){
					GoodMoto(0,0);
					break;//处理掉台、边缘等情况
				}
			}
		}
		break;
		case 6:   //左后方
		{
			start_time();
			while(1)
			{
				GoodMoto(-100,100);
				if(AI(0)<drcjz||AI(1)<drcjz||position==1)	
				{
					GoodMoto(0,0);
					break;//处理掉台、边缘等情况
				}
			}	
		}
		break;
		case 7:     //左方遇到敌人
		{
  		start_time();
			while(1)
			{
				GoodMoto(-100,100);
				if(AI(0)<drcjz||AI(1)<drcjz||position==1){
					GoodMoto(0,0);
					break;//处理掉台、边缘等情况
				}
			}				
		}
		break;
		case 8:   //左前遇到敌人
		{
  		start_time();
			while(1)
			{
				GoodMoto(-100,100);
				if(AI(0)<drcjz||AI(1)<drcjz||position==1)
				{
					GoodMoto(0,0);
					break;//处理掉台、边缘等情况
				}
			}			
		}
		break;
		default:		//处理前行的情况
		{
			 GoodMoto(400,400);
		}
		break;
 }
}
	
//int findenemy(){
//	int i;
////	if(AI(0)<100&&AI(1)<100&&AI(2)<100&&AI(3)<100&&AI(4)<100){
////		GoodMoto(0,0);
////	}
////	else{
//	switch(position)
//	{
////		case 7:		//左前40度
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>80)	break;//处理掉台、边缘等情况
////				GoodMoto(-700,700);
////			}
////			break;
////		}
//		case 0:
//		{
//			start_time();
//			while(1)
//			{
//				trackchannel();
//                if(position!=0)	{
//					GoodMoto(0,0);
//					break;			
//				}
////		       if(mseconds()>600){      //僵持一段时间后，甩掉对方。
////			     GoodMoto(500,-500);
////			     break;				   
////		        }
//		}
////			trackchannel();
//		}
//		break;
//	  case 1:           //正前方遇到敌人
//		{
//			GoodMoto(0,0);
//			delay_ms(200);
//			start_time();
//		if(receive==53){
//				back_N90();
//			  GoodMoto(300,300);
//	  }
//			else{
//			while(1)
//			{
//				GoodMoto(350,350);
//				if(AI(0)<drcjz||AI(1)<drcjz)	{
//                    edage();	
//					break;
//				}					
////		       if(mseconds()>600){      //僵持一段时间后，甩掉对方。
////			     GoodMoto(500,-500);
////			     break;				   
////		        }
//		}
//	}
//		break;
//		case 2:        //左前方遇到敌人
//		{
//			start_time();
//			while(1)
//			{
//				GoodMoto(-100,100);
//				if(AI(0)<drcjz||AI(1)<drcjz||position==1)	{
//				GoodMoto(0,0);
//				break;//处理掉台、边缘等情况
//				}
//			}
//		}
//		break;
//		case 3:        //右前方遇到敌人
//		{
//			start_time();
//			while(1)
//			{
//				GoodMoto(100,-100);
//				if(AI(0)<drcjz||AI(1)<drcjz||position==1){	
//					GoodMoto(0,0);
//					break;//处理掉台、边缘等情况
//				}
//			}
//			GoodMoto(0,0);
//		}
//		break;
//		case 4:
//		{
//			start_time();
//			while(1)
//			{
//				GoodMoto(-100,100);
//				if(AI(0)<drcjz||AI(1)<drcjz||position==1){
//					GoodMoto(0,0);
//					break;//处理掉台、边缘等情况
//				}
//			}		
//		}
//		break;
//		case 5:       //左后方
//		{
//			start_time();
//			while(1)
//			{
//				GoodMoto(-100,100);
//				if(AI(0)<drcjz||AI(1)<drcjz||position==1){
//					GoodMoto(0,0);
//					break;//处理掉台、边缘等情况
//				}
//			}
//		}
//		break;
//		case 6:   //右后方
//		{
//			start_time();
//			while(1)
//			{
//				GoodMoto(100,-100);
//				if(AI(0)<drcjz||AI(1)<drcjz||position==1)	{
//					GoodMoto(0,0);
//					break;//处理掉台、边缘等情况
//				}
//			}	
//		}
//		break;
//		case 7:     //左方遇到敌人
//		{
//  			start_time();
//			while(1)
//			{
//				GoodMoto(-100,100);
//				if(AI(0)<drcjz||AI(1)<drcjz||position==1){
//					GoodMoto(0,0);
//					break;//处理掉台、边缘等情况
//				}
//			}				
//		}
//		break;
//		case 8:   //左方遇到敌人
//		{
//  		start_time();
//			while(1)
//			{
//				GoodMoto(-100,100);
//				if(AI(0)<drcjz||AI(1)<drcjz||position==1){
//				GoodMoto(0,0);
//				break;//处理掉台、边缘等情况
//				}
//			}			
//		}
//		break;
//		case 9:  //右方遇到敌人
//		{
//  			start_time();
//			while(1)
//			{
//				GoodMoto(100,-100);
//				if(AI(0)<drcjz||AI(1)<drcjz||position==1){
//				GoodMoto(0,0);
//				break;//处理掉台、边缘等情况
//				}
//			}			
//		}
//		break;
//		case 10: //右方遇到敌人
//		{
//  			start_time();
//			while(1)
//			{
//				GoodMoto(100,-100);
//				if(AI(0)<drcjz||AI(1)<drcjz||position==1){
//				GoodMoto(0,0);	
//				break;//处理掉台、边缘等情况
//				}
//			}				
//		}
//		break;
//		default:		//处理前行的情况
//		{
//			 GoodMoto(400,400);
//		 }
//		break;
// }
//}
//	
////}
//}
int maxDistance(){
	 int d[] = {AI(5), AI(6), AI(7), AI(8),AI(9), AI(10), AI(11), AI(12),AI(13), AI(14)};
   int maxNum = d[0];
	 int f=0;
	 int l;
   for (int i = 1; i < 10; i++)
   {
      if (maxNum < d[i])
      {
         maxNum = d[i];
				 f=i;
      }
			l=f+5;
   }
   return l;
}
int Touch()//触摸AD转换
{
	if(AI(12)>2000)
	{
		led_on();
		delay_ms(10);
		if(AI(12)>2000)
		{ 
			led_off();
			return 1;
		}
	}
	else return 0;  
}

void motor_test(void)//电机测试函数
{
			u8 Key = 0;
			ClearScreen();
	while(1)
	{
		ShowStr(0,1,"顺时针90");
		ShowStr(2,1,"逆时针90");
		ShowStr(4,1,"直行1秒");
		ShowStr(6,1,"返回");
	  Key=KEY_Scan(0);
		if(Key==1)
		{
			start_time();
			while(1)
			{
				GoodMoto(300,-300);
				if(mseconds()>500)	{GoodMoto(0,0); break;}
			}
			Key=KEY_Scan(0);
			if(Key==4)	{ClearScreen();Key=0; break;}	
		}
		else if(Key==2)
		{
			start_time();
			while(1)
			{
				GoodMoto(300,300);
				if(mseconds()>1000)	{GoodMoto(0,0); break;}
			}
			Key=KEY_Scan(0);
			if(Key==4)	{ClearScreen();Key=0; break;}	
		}
		else if(Key==3)
		{
			start_time();
			while(1)
			{
				GoodMoto(-300,300);
				if(mseconds()>500)	{GoodMoto(0,0); break;}
			}
			Key=KEY_Scan(0);
			if(Key==4)	{ClearScreen();Key=0; break;}	
		}
		else if(Key==4)
		{
		Key=KEY_Scan(0);
		{ClearScreen();Key=0; break;}
	   }		
	}
}
void test(void)//测试函数
{
	int i;
	u8 Key = 0;
	ClearScreen();
	while(1)
		{
			ShowStr(0,1,"1.灰度检测");
			ShowStr(2,1,"2.摄像头检测");
			ShowStr(4,1,"3.距离检测");
			ShowStr(6,1,"4.返回");
			Key=KEY_Scan(0);
			if(Key==1)
			{
				ClearScreen();
				while(1){
						if(tt%10==0)
			{
					display_AI(0,26,AI(0));	
					display_AI(0,70,AI(1));		
					display_AI(2,26,averageAI(2));	
					display_AI(2,70,averageAI(3));	
					display_AI(4,26,averageAI(4));	
		 }
		delay_ms(10);
		tt++;		
		if(tt==20)
		{
			tt=0;
		}
    Key=KEY_Scan(0);
	 if(Key==4)	{ClearScreen();Key=0; break;}			
				}
			}
			else if(Key==3)
			{
					 ClearScreen();
						 while(1)
							{
							  ShowStr(0,1,"摄像头检测中...");
								if(tt%10==0)
								{
								display_AI(6,70,(int)receive);					//摄像头检测显示	
				        }
								delay_ms(10);
								tt++;		
								if(tt==20)
								{
									tt=0;
								}
								Key=KEY_Scan(0);
								if(Key==4)	{ClearScreen();Key=0; break;}	
							}
			}
			else if(Key==2)
			{
				ClearScreen();
				while(1)
				{
							if(tt%10==0)
							{
							display_AI(0,0,averageAI(5));	
							display_AI(0,40,averageAI(6));	
							display_AI(0,80,averageAI(7));	
							display_AI(2,0,averageAI(8));	
							display_AI(2,40,averageAI(9));
							display_AI(2,80,averageAI(10));	
							display_AI(4,0,averageAI(11));	
							display_AI(4,40,averageAI(12));	
							display_AI(4,80,averageAI(13));	
							display_AI(6,0,averageAI(14));
							display_AI(6,40,averageAI(15));
							}
							delay_ms(10);
							tt++;		
							if(tt==20)
							{
								tt=0;
							}
							Key=KEY_Scan(0);
							if(Key==4)	{ClearScreen();Key=0; break;}	
				}
			}
							else if(Key==4)
							{
								Key=0;
								ClearScreen();
								break;
							}
		}
}
void start_feedback(void)//启动反馈
{
	ShowStr(2,1,"    welcome");
	beep();
	led_on();
	delay_ms(300);
	beep();
	led_off();
	ClearScreen();
}

//判断有多少个敌人在旁边
int enemynumber()          
{
    int i,enemy=0;
	  for(i=5;i<15;i++)
	 {
		    	if(AI(i)>ceejuyz)
						enemy++;
	 }
	 return enemy;
}
int fangxiangflage()
{
    if(((AI(5)<czzx)&&(AI(6)<czzx))&&(abs_my(AI(7),AI(8))<dqbz))      //前方无障碍，后方对齐
			return 1;
		else
			return 0;
}
//掉台检测（掉台方式）
void select_fall()    
{
	if(taixia1)
	{  
  taixia=1;                                       
//	ShowStr(3,1,"普通掉台");
	}
//  if((AI(0)<100)&&(AI(3)<100)&&(AI(1)>100)&&(AI(4)>600))  //左侧身掉台
//	{
//	taixia=2;
////	ShowStr(3,1,"左侧身掉台");
//	}
// if((AI(1)<100)&&(AI(4)<100)&&(AI(0)>100)&&(AI(3)>600))        //右侧身掉台
//	{
//	taixia=3;
////	ShowStr(3,1,"右侧身掉台");
//	}
	else
  taixia=0;	 
	 ClearScreen();
}
//台下寻找方向并登台
void detection_taixia_direction()        
{
	//普通掉台
  if(taixia==1)
	{
		//掉台尾部刚好对齐
		if(weibuduiqi)  
		{
			ShowStr(4,1,"尾部对齐");
			start_time();  
			 //往前跑一小段，对齐，上台更猛
			   while(1)
				   {
					    GoodMoto(xpspeed,xpspeed);            
              if(mseconds()>runtime)	
							{
              GoodMoto(0,0);		
							delay_ms(100);
						  break;
							}
					 }
			up_stage1();	       
	  }
		//否则需要找对其的方向   //若转不到尾部对齐，则判断在墙角(既墙角置1)
		else                                     
			{
				 start_time();      
			   while(1)
				   {
					   GoodMoto(-dtxzspeed,dtxzspeed);                                                  
					   if(weibuduiqi)
						 {
						  GoodMoto(0,0);
							delay_ms(100);							 
						  break;
						 }
						 if(mseconds()>3000)    	 
						 {						
							 qiangjiao=1;        
						   break;
						 }
				   }
			}
			//不是在墙角
			if(qiangjiao==0)		
			{
					start_time();  
				 //往前跑一小段，对齐，上台更猛
			   while(1)
				   {     
					    GoodMoto(xpspeed,xpspeed);            
              if(mseconds()>runtime)
							{
						   GoodMoto(0,0);	
								delay_ms(100);
						   break;
							}
					 }
				up_stage1();
			 }
			//在墙角
			else
			{
			 //找到无障碍方向，前进一段时间    
			    start_time();  
			   while(1)
				   {
					   GoodMoto(-dtxzspeed,dtxzspeed);                                                  
					   if(fangxiangflage()==1)
						 {
						  GoodMoto(0,0);
							delay_ms(100);							 
						  break;
						 }
						 if(mseconds()>4000)
						 {
						 	 GoodMoto(0,0);
							 delay_ms(100);
						    break;
						 }
					 }
			   GoodMoto(500,500);
			   delay_ms(1000);	
				 GoodMoto(0,0);
					delay_ms(100);					 
				 //尾部对齐
				start_time();      
			   while(1)
				   {
					   GoodMoto(-dtxzspeed,dtxzspeed);                                                  
					   if(weibuduiqi)
						 {
							 ShowStr(4,1,"尾部对齐");
							 GoodMoto(0,0);
							 delay_ms(100);							 
						   break;
						 }
						 if(mseconds()>4000)
						 {
						 	 GoodMoto(0,0);
							 delay_ms(100);
						    break;
						 }
				   }
					 //往前跑一小段，对齐，上台更猛
					 start_time();  
			     while(1)     
				   {
					    GoodMoto(xpspeed,xpspeed);                
              if(mseconds()>runtime)	
							{
							GoodMoto(0,0);	
								delay_ms(100);
						  break;
							}
					 }
					 up_stage1();
			}
	}	
	//左侧身掉台
	if(taixia==2)
	{
		 start_time(); 
		 //一直跑，直到判断为台下
	   	while(1)
		{
	   GoodMoto(-maxspeed,-maxspeed);
				if(taixia1)
			{
				GoodMoto(0,0);
				delay_ms(100);
				break;
				if(mseconds()>5000)	
				{
					GoodMoto(0,0);	
					delay_ms(100);
					break;
				}
		  }
		}
	}
	//右侧身掉台
	if(taixia==3)
	{
		while(1)
		{
	   GoodMoto(-maxspeed,-maxspeed);
	if(taixia1)
			{
				GoodMoto(0,0);
				delay_ms(100);
				break;
		  }
			if(mseconds()>5000)	
				{
					GoodMoto(0,0);
					delay_ms(100);					
					break;
				}
		}
	}
	
  //如果上台异常，持续登台，直到上台为止（需测试是否管用）
//	while(1)  
//	{		
//			if((hdctyz<BlackFilter0()<hddtyz)&&(hdctyz<BlackFilter1()<hddtyz)&&(hdctyz<AI(2)<hddtyz)&&(hdctyz<AI(3)<hddtyz)&&(hdctyz<AI(4)<hddtyz))
//			{
//				  start_time();    
//				  if(mseconds()<runtime)
//					GoodMoto(xpspeed,xpspeed);
//            GoodMoto(0,0); 
//            delay_ms(100);  
//	        up_stage1();					
//		  }
//			else
//				break;
//	}
	  qiangjiao=0;
    taixia=0;	      //置零，否则会一致认为在台下
}
