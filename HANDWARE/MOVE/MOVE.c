#include "MOVE.h"
#include "CONTRAL.h"
extern u16 hui0[5],hui1[5],hui2[5],hui3[5],hui4[5];
extern u16 HUI0,HUI1,HUI2,HUI3,HUI4;
extern u16 ceju5,ceju6,ceju7,ceju8,ceju9,ceju10,ceju11,ceju12,ceju13,ceju14,ceju15;
extern int attck_speed;
//extern  u16 hui0[5]={0},hui1[5]={0},hui2[5]={0},hui3[5]={0},hui4[5]={0};
//����ļ�����д�����˵���ض�������
u8 flag_1 = 0;//ǰ������̨�ı�־
int m;
/*
  �Ҷȴ������ֲ�
	����        0       1
	                2
									
	β��        3       4
*/

int abs_my(int a,int b)//��ľ���ֵ
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
void up_stage()       //��ʼ��̨              
{
	ClearScreen();
	ShowStr(2,5,"Stand By");
	delay_ms(1000);
	ClearScreen();
	ShowStr(2,5,"��ʼ��̨");
	{
		GoodMoto(-maxspeed,-maxspeed);
		delay_ms(1200);
		GoodMoto(0,0);
		delay_ms(100);
		back_S90();
	}
}
void up_stage1()     //��̨
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
  //����
void  ContinueAttack()               
{
	ClearScreen();
	ShowStr(2,5,"������");
	int i;
	for(i=0;i<6;i++)
	{
	 start_time(); 
   if(mseconds()<backtime)										 //����ʱ�����
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
		  	ShowStr(2,5,"������");
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
	 ShowStr(2,5,"������");
	 start_time(); 
   if(mseconds()<backtime)                      //����ʱ�����
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

void trackchannel(){      //Բ��Ѱ̨

//	if( minAIvalue() < dangerblack){      //С��������Σ����,���޵���
//		if((averageAI(2)<dangerblack)&&(averageAI(3)>dangerblack)&&(averageAI(4)>dangerblack)) {
//				while(1){
//				GoodMoto(xzspeed,-xzspeed);   
//				if( abs_my(averageAI(3),averageAI(4))<breakvalue ) break;
//				}
//				back2();
//				back_2180();
////				forward();
////				back_N45();
//				GoodMoto(xzspeed,xzspeed);
////				ShowStr(2,1,"���1");
//			}
//		if( (averageAI(2)>dangerblack)&&(averageAI(3)>dangerblack)&&(averageAI(4)<dangerblack) ) {
//				while(1){
//				GoodMoto(-xzspeed,xzspeed);  
//				if( abs_my(averageAI(3),averageAI(4))<breakvalue ) break;
//				}
//				back_2180();
////				forward();
////				back_N45();
//				GoodMoto(xzspeed,xzspeed);
//				clear_screen();
//			}
//		if( (averageAI(2)<dangerblack)&&(averageAI(3)<dangerblack)&&(averageAI(4)>dangerblack) ) {
//				while(1){
//        GoodMoto(xzspeed,-xzspeed);						   
//				if(abs_my(averageAI(3),averageAI(4))<breakvalue) break;
//				}
////				forward();
//				GoodMoto(xzspeed,xzspeed);
////				back_N45();
////				GoodMoto(200,200);
//				clear_screen();
//			}
//		if( (averageAI(2)<dangerblack)&&(averageAI(3)>dangerblack)&&(averageAI(4)<dangerblack) ){
//				while(1){
//				GoodMoto(-xzspeed,xzspeed);
//				if(abs_my(averageAI(3),averageAI(4))<breakvalue) break;
//				}
////				forward();
//				GoodMoto(xzspeed,xzspeed);
////				back_N45();
////				GoodMoto(200,200);
//				clear_screen();
//			}
//		if( (averageAI(2)>dangerblack)&&(averageAI(3)<dangerblack)&&(averageAI(4)<dangerblack) ) {
//				while(1){
//				GoodMoto(xzspeed,-xzspeed);  
//				if( abs_my(averageAI(3),averageAI(4))<breakvalue ) break;
//				}
//				forward2();
//				back_2N45();
////				forward();
////				back_N45();
//				GoodMoto(xzspeed,xzspeed);
////				ShowStr(2,1,"���2");
//			}
//			if( (averageAI(2)>dangerblack)&&(averageAI(3)<dangerblack)&&(averageAI(4)>dangerblack) ) {
//				while(1){
//				GoodMoto(-xzspeed,xzspeed);
//				if(abs_my(averageAI(3),averageAI(4))<breakvalue) break;
//				}
////				forward();
//			 GoodMoto(xzspeed,xzspeed);
////				back_N45();
////				GoodMoto(200,200);
//				clear_screen();
//			}
//			if( (averageAI(2)<dangerblack)&&(averageAI(3)<dangerblack)&&(averageAI(4)<dangerblack)){
//				pavetocentral();
////				GoodMoto(xzspeed,xzspeed);
//				clear_screen();
//			}
//	}
//	if(minAIvalue() > dangerblack){   //���ڰ�ȫ�������޵���
//	    back_2N45();
//	    GoodMoto(xzspeed,xzspeed);
//	}
}
void PaveToDangerBlack()
{

}
void pavetocentral(){       //Ѱ������,�����ò���,�����ĸ��Ҷ�ȫ����Σ����ʱ���ж��жϣ���ԭ����Ѱ�һҶȴ������е���Сֵ����Ҷ�ֵ���ķ����ƶ�������ص�����
	switch( maxAI() )
	{
		case 2:
		{
			while(1){
			GoodMoto(-xzspeed,xzspeed);
				if(abs_my(averageAI(3),averageAI(4))<breakvalue && maxAI()==2)break;
			}
			 GoodMoto(xzspeed,xzspeed);        //��Ե���
		}
		break;
		case 3:
		{
			while(1){
			GoodMoto(-xzspeed,xzspeed);
				if(abs_my(averageAI(3),averageAI(4))<breakvalue && maxAI()==2)break;
			}
			 GoodMoto(xzspeed,xzspeed);       //��Ե���
		}
		break;
		case 4:
		{
			while(1){
			GoodMoto(xzspeed,-xzspeed);
				if(abs_my(averageAI(3),averageAI(4))<breakvalue && maxAI()==2)break;
			}
			back_2180();
			 GoodMoto(xzspeed,xzspeed);        //��Ե���
		}
		break;
  }
}
u16 averageAI(int i){         //�Ҷ�ƽ��ֵ
	int times=5;
	int t;
	int a;
	for(t=0;t<times;t++){
		a+=AI(i);
	}
	return a/times;
}

int minAI(){              //Ѱ�һҶȴ������еĻҶ���Сֵ��������Сֵ�Ĵ�������
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

int minAIvalue(){              //Ѱ�һҶȴ������еĻҶ���Сֵ��������Сֵ�Ĵ�������
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

int maxAI(){              //Ѱ�һҶȴ������еĻҶ����ֵ���������ֵ�Ĵ�������
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

int maxAIvalue(){              //Ѱ�һҶȴ������еĻҶ����ֵ,�������ֵ
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
void forward2()
{
	start_time();
	while(1)
	{
		GoodMoto(400,400);
		if(mseconds()>400)	GoodMoto(0,0); break;
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

void back2()
{
	start_time();
	while(1)
	{
		GoodMoto(-400,-400);
		if(mseconds()>200)	GoodMoto(0,0); break;
	}
}
void forward_stop()//ǰ��ʱ����ɲ��
{
	start_time();
	while(1)
	{
		GoodMoto(-maxspeed,-maxspeed);	
		if(mseconds()>500)	{GoodMoto(0,0); break;}
	}
}
void forward_2stop()//ǰ��ʱ����ɲ��
{
	start_time();
	while(1)
	{
		GoodMoto(-maxspeed,-maxspeed);	
		if(mseconds()>500)	GoodMoto(0,0); break;
	}
}

void back_S90()//��ʱ��90
{
	start_time();
	while(1)
	{
		GoodMoto(-xzspeed,xzspeed);
		if(mseconds()>430)	{GoodMoto(0,0); break;}
	}	
}

void back_N90()//˳ʱ��90
{
	start_time();
	while(1)
	{
		GoodMoto(400,-400);
		if(mseconds()>430)	{GoodMoto(0,0); break;}
	}
}

void back_N60()//˳ʱ��60(����ԣ�δ����)
{
	start_time();
	while(1)
	{
		GoodMoto(xzspeed,-xzspeed);
		if(mseconds()>290)	{GoodMoto(0,0); break;}
	}
}

void back_S60()//��ʱ��60(����ԣ�δ����)
{
	start_time();
	while(1)
	{
		GoodMoto(-xzspeed,xzspeed);
		if(mseconds()>290)	{GoodMoto(0,0); break;}
	}	
}

void back_N45()//˳ʱ��45(����ԣ�δ����)
{
	start_time();
	while(1)
	{
		GoodMoto(xzspeed,-xzspeed);
		if(mseconds()>220)	{GoodMoto(0,0); break;}
	}
}
void back_2N45()//˳ʱ��45(����ԣ�δ����)
{
	start_time();
	while(1)
	{
		GoodMoto(xzspeed,-xzspeed);
		if(mseconds()>220)	GoodMoto(0,0); break;
	}
}
void back_S45()//��ʱ��45(����ԣ�δ����)
{
	start_time();
	while(1)
	{
		GoodMoto(-xzspeed,xzspeed);
		if(mseconds()>220)	{GoodMoto(0,0); break;}
	}	
}

void back_2S45()//��ʱ��45(����ԣ�δ����)
{
	start_time();
	while(1)
	{
		GoodMoto(-xzspeed,xzspeed);
		if(mseconds()>220)	GoodMoto(0,0); break;
	}	
}
void back_180()//˳ʱ��180(����ԣ�δ����)
{
	start_time();
	while(1)
	{
		GoodMoto(xzspeed,-xzspeed);
		if(mseconds()>870)	{GoodMoto(0,0); break;}
	}
}
void back_2180()//˳ʱ��180(����ԣ�δ����)
{
	start_time();
	while(1)
	{
		GoodMoto(xzspeed,-xzspeed);
		if(mseconds()>870)
		{			
			GoodMoto(0,0); break;
		}
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