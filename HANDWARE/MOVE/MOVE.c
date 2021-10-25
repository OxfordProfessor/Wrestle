#include "MOVE.h"
#include "CONTRAL.h"
#define	baseSpeed 300
#define dangerblack1 800
#define dangerblack2 1000
#define MoreSpinSpeed  300
#define LessSpinSpeed  200
#define TurnAround_MoreSpinSpeed  200
#define TurnAround_LessSpinSpeed  -200
#define BreakValue		300
extern u16 hui0[5],hui1[5],hui2[5],hui3[5],hui4[5];
extern u16 HUI0,HUI1,HUI2,HUI3,HUI4;
extern u16 ceju5,ceju6,ceju7,ceju8,ceju9,ceju10,ceju11,ceju12,ceju13,ceju14,ceju15;
extern int attck_speed;
//extern  u16 hui0[5]={0},hui1[5]={0},hui2[5]={0},hui3[5]={0},hui4[5]={0};
//这个文件用来写机器人的相关动作函数
u8 flag_1 = 0;//前铲出擂台的标志
int m;
/*
  灰度传感器分布
	铲子        0       1
	                2
									
	尾巴        3       4
*/

int abs_my(int a,int b)//差的绝对值
{
	if((a-b)>=0)
		return a-b;
	else
		return b-a;
}
void touch_sensor9()
{
   while(1)
	 {
	   if(AI(9)>ceejuyz)
		 {
			 delay_ms(10);
			 if(AI(9)>ceejuyz)
				 break;
		 }
	 }
}
void up_stage()       //初始上台              
{
	ClearScreen();
	ShowStr(2,5,"Stand By");
	delay_ms(1000);
	ClearScreen();
	ShowStr(2,5,"初始上台");
	{
		GoodMoto(-maxspeed,-maxspeed);
		delay_ms(1200);
		GoodMoto(0,0);
		delay_ms(100);
		back_S90();
	}
}
void up_stage1()     //上台
{
  ClearScreen();
	{
		GoodMoto(-maxspeed,-maxspeed);
		delay_ms(1000);  //1500
		GoodMoto(0,0);   
		delay_ms(100);
		back_S45();
	}  
}    
  //补刀
void  ContinueAttack()               
{
	ClearScreen();
	ShowStr(2,5,"补刀中");
	int i;
	for(i=0;i<6;i++)
	{
	 start_time(); 
   if(mseconds()<backtime)										 //后退时间待测
	 GoodMoto(-500,-500);
	 GoodMoto(0,0);
	 delay_ms(100);
	 while(1)
	 {
     GoodMoto(500,500);
		 if((AI(0)<hdctyz)||(AI(1)<hdctyz))
		 break;
	 }	
	 GoodMoto(0,0);
	 delay_ms(100);
 }	 
}
 
void attack()
{
	int i;
	while(1)
		{
		  	ShowStr(2,5,"攻击中");
				GoodMoto(maxspeed,maxspeed);           
        if((AI(0)<hdctyz)||(AI(1)<hdctyz))				 
				break;
	  }
		
//		u8 j;
//		while(1)
//		{
//			GoodMoto(500,500);
//			if(abs_my(AI(5),AI(6))>dqbz)
//			{
//				if(AI(5)>AI(6))
//				{
//						for(j=0;abs_my(AI(5),AI(6))<dqbz;j++)
//					  GoodMoto(500,500+i);
//				}
//				if(AI(5)<AI(6))
//				{
//						for(j=0;abs_my(AI(5),AI(6))<dqbz;j++)
//					  GoodMoto(500+j,500);
//				}
//			}
//			else break;
//		}
			

	GoodMoto(0,0);
	delay_ms(100);
	for(i=0;i<6;i++)
	{
	 ShowStr(2,5,"补刀中");
	 start_time(); 
   if(mseconds()<backtime)                      //后退时间待测
 	 GoodMoto(-500,-500);
	 GoodMoto(0,0);
	 delay_ms(100);
	 while(1)
	 {
     GoodMoto(500,500);
		 if((AI(0)<hdctyz)||(AI(1)<hdctyz))
		 break;
	 }	
	 GoodMoto(0,0);
	 delay_ms(100);
 }	 
		 start_time(); 
     if(mseconds()<backtime)
		 GoodMoto(-500,-500);
}


void edge_spin()
{
	start_time();
	while(1)
	{
		GoodMoto(-xzspeed,xzspeed);	
		if(mseconds()>400)	break;
	}
}

void edage(){
	  if(HUI0>900 && HUI1>900){
		   GoodMoto(300,300);
		}
		else if(HUI0<900 && HUI1>900)
		{
			forward_stop();
			back_N90();
		}
		else if(HUI0>900 && HUI1<900)
		{
			forward_stop();
			back_S90();
		}
		else
		{
			forward_stop();
			edge_spin();
		}
}

char Black_State()
{		//判断位于灰度墙的状态
	if(AI(2)<dangerblack1)      //车头传感器不在灰度墙带内,而位于外层灰度墙
	{
		if(AI(3)>AI(4) && AI(3))
		{
			return 'A';       //返回A，A情况采取措施为逆时针转
		}
		else if(AI(3)<AI(4))
		{
			return 'B';			//返回B，B情况采取措施为逆时针转
		}
	}
	else if(AI(2)>dangerblack2)  //车头传感器不位于灰度带内，而位于内层灰度墙
	{
		if(AI(3)>AI(4))
		{
			return 'B';       //返回B，B情况采取措施为逆时针转
		}
		else if(AI(3)<AI(4))
		{
			return 'A';		//返回A，A情况采取措施为逆时针转
		}
	}
	else if(AI(2)>dangerblack1 && AI(2)<dangerblack2)   //车头位于灰度带内，此时又需要判断车尾传感器位置
	{
		if(AI(3)<dangerblack1 || AI(4)<dangerblack1)
		{
			if(AI(3)>AI(4))
			{
				return 'A';		//返回A，A情况采取措施为逆时针转				
			}
			else if(AI(3)<AI(4))
			{
				return 'B';		 //返回B，B情况采取措施为逆时针转
			}			
		}
		else
		{
			if(AI(3)<AI(4))
			{
				return 'B';		 //返回B，B情况采取措施为逆时针转				
			}
			else if(AI(3)>AI(4))
			{
				return 'A';		//返回A，A情况采取措施为逆时针转
			}				
		}
	}
}

void trackchannel()
{      //圆周寻台
	if(minAIvalue()>dangerblack2)       //位于灰度墙内部
	{
		while(minAI()==2 && abs_my(AI(4),AI(3))<BreakValue)			//转直到车头指向外环
		{
			if(AI(4)>AI(3))
			{
				GoodMoto(TurnAround_MoreSpinSpeed,TurnAround_LessSpinSpeed);    
			}
			else{
				GoodMoto(TurnAround_LessSpinSpeed,TurnAround_MoreSpinSpeed);
			}
		}
		while(minAIvalue()<dangerblack2)     //向前走，直到某一传感器达到灰度墙区域内
		{
			GoodMoto(baseSpeed,baseSpeed);
		}
	}
	if(maxAIvalue()<dangerblack1)     //位于灰度墙外部
	{
		while(maxAI()==2 && abs_my(AI(4),AI(3))<BreakValue)			//转直到车头指向中心
		{
			if(AI(4)>AI(3))
			{
				GoodMoto(TurnAround_MoreSpinSpeed,TurnAround_LessSpinSpeed);    
			}
			else{
				GoodMoto(TurnAround_LessSpinSpeed,TurnAround_MoreSpinSpeed);
			}
		}
		while(maxAIvalue()>dangerblack1)     //向前走，直到某一传感器达到灰度墙区域内
		{
			GoodMoto(baseSpeed,baseSpeed);
		}
	}
	else{			//某一传感器位于灰度墙区域内
		switch(Black_State()){
			case 'A':
				while((AI(2)>dangerblack1 && AI(2)>dangerblack2)&&(abs_my(AI(3),AI(4)))<BreakValue)
				{
					GoodMoto(TurnAround_LessSpinSpeed,TurnAround_MoreSpinSpeed);
				}
				GoodMoto(baseSpeed,baseSpeed);
			break;
			case 'B':
				while((AI(2)>dangerblack1 && AI(2)>dangerblack2)&&(abs_my(AI(3),AI(4)))<BreakValue)
				{
					GoodMoto(TurnAround_MoreSpinSpeed,TurnAround_LessSpinSpeed);
				}
				GoodMoto(baseSpeed,baseSpeed);				
			break;
		}
	}

}


u16 averageAI(int i){         //灰度平均值
	int times=5;
	int t;
	int a;
	for(t=0;t<times;t++){
		a+=AI(i);
	}
	return a/times;
}

int minAI(){              //寻找灰度传感器中的灰度最小值，返回最小值的传感器号
	 int a[] = {averageAI(2), averageAI(3), averageAI(4)};
   int minNum = a[0];
	 int t=0;
	 int l;
   for (int i = 1; i < 3; i++)
   {
      if (minNum > a[i])
      {
         minNum = a[i];
				 t=i;
      }
			l=t+2;
   }
   return t;
}

int minAIvalue(){              //寻找灰度传感器中的灰度最小值，返回最小值的传感器号
	 int a[] = {averageAI(2), averageAI(3), averageAI(4)};
   int minNum = a[0];
	 int t=0;
   for (int i = 1; i < 3; i++)
   {
      if (minNum > a[i])
      {
         minNum = a[i];
				 t=i;
      }
   }
   return minNum;
}

int maxAI(){              //寻找灰度传感器中的灰度最大值，返回最大值的传感器号
	 int a[] = {averageAI(2), averageAI(3), averageAI(4)};
   int maxNum = a[0];
	 int t=0;
	 int l;
   for (int i = 1; i < 3; i++)
   {
      if (maxNum < a[i])
      {
         maxNum = a[i];
				 t=i;
      }
			l=t+2;
   }
   return l;
}

int maxAIvalue(){              //寻找灰度传感器中的灰度最大值,返回最大值
	 int a[] = {averageAI(2), averageAI(3), averageAI(4)};
   int maxNum = a[0];
	 int t=0;
   for (int i = 1; i < 3; i++)
   {
      if (maxNum < a[i])
      {
         maxNum = a[i];
				 t=i;
      }
   }
   return maxNum;
}

void forward()
{
	start_time();
	while(1)
	{
		GoodMoto(400,400);
		if(mseconds()>400)	{GoodMoto(0,0); break;}
	}
}

void back()
{
	start_time();
	while(1)
	{
		GoodMoto(-400,-400);
		if(mseconds()>200)	{GoodMoto(0,0); break;}
	}
}


void forward_stop()//前进时反向刹车
{
	start_time();
	while(1)
	{
		GoodMoto(-maxspeed,-maxspeed);	
		if(mseconds()>500)	{GoodMoto(0,0); break;}
	}
}


void back_S90()//逆时针90
{
	start_time();
	while(1)
	{
		GoodMoto(-xzspeed,xzspeed);
		if(mseconds()>430)	{GoodMoto(0,0); break;}
	}	
}

void back_N90()//顺时针90
{
	start_time();
	while(1)
	{
		GoodMoto(400,-400);
		if(mseconds()>430)	{GoodMoto(0,0); break;}
	}
}

void back_N60()//顺时针60(需测试，未测试)
{
	start_time();
	while(1)
	{
		GoodMoto(xzspeed,-xzspeed);
		if(mseconds()>290)	{GoodMoto(0,0); break;}
	}
}

void back_S60()//逆时针60(需测试，未测试)
{
	start_time();
	while(1)
	{
		GoodMoto(-xzspeed,xzspeed);
		if(mseconds()>290)	{GoodMoto(0,0); break;}
	}	
}

void back_N45()//顺时针45(需测试，未测试)
{
	start_time();
	while(1)
	{
		GoodMoto(xzspeed,-xzspeed);
		if(mseconds()>220)	{GoodMoto(0,0); break;}
	}
}

void back_S45()//逆时针45(需测试，未测试)
{
	start_time();
	while(1)
	{
		GoodMoto(-xzspeed,xzspeed);
		if(mseconds()>220)	{GoodMoto(0,0); break;}
	}	
}


void back_180()//顺时针180(需测试，未测试)
{
	start_time();
	while(1)
	{
		GoodMoto(xzspeed,-xzspeed);
		if(mseconds()>870)	{GoodMoto(0,0); break;}
	}
}



void continue_attack()
{
		start_time();
	  while(1)
	  {
			GoodMoto(-(attck_speed-100),-attck_speed);
			if(mseconds()>300)
			{
				GoodMoto(0,0); break;
			}
		}
			GoodMoto(attck_speed,attck_speed);
		  if(AI(0)<900||AI(1)<900)
			edage();
		start_time();
	  while(1)
	  {
			GoodMoto(-attck_speed,-attck_speed);
			if(mseconds()>200)
			{
				GoodMoto(0,0); break;
			}
		}
		GoodMoto(attck_speed,attck_speed);
		if(AI(0)<900||AI(1)<900)
		edage();
		start_time();
	  while(1)
	  {
			GoodMoto(-attck_speed,-(attck_speed-100));
			if(mseconds()>300)
			{
				GoodMoto(0,0); break;
			}
		}
		GoodMoto(attck_speed,attck_speed);
		if(AI(0)<900||AI(1)<900)
		edage();
}

void attack1()
{
	while(1)
	{
		  if(abs_my(AI(5),AI(6))<dqbz)
			{
			GoodMoto(attck_speed,attck_speed);
			}
			if(abs_my(AI(5),AI(6))>dqbz)
			{
				if(AI(5)>AI(6))
				{
						for(m=0;abs_my(AI(5),AI(6))<dqbz;m+=100)
					{
						if(m>attck_speed) m=attck_speed;
					  GoodMoto(attck_speed-m,attck_speed+m);
					}
				}
				if(AI(5)<AI(6))
				{
						for(m=0;abs_my(AI(5),AI(6))<dqbz;m+=100)
					{
					  GoodMoto(attck_speed+m,attck_speed-m);
						if(m>attck_speed) m=attck_speed;
					}
				}
			}
			if(AI(0)<60||AI(1)<60)
			{
				edage();
				break;
			}
		}
}
