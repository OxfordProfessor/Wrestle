#include "TIM.h"
//����ļ���Ҫд��ʱ������
#include "BEEP.h" 
#include "CONTRAL.h"
u16 count_ms_0=0;
u16 count_s_0=0;
u16 count_ms_1=0;
u16 count_s_1=0;
u8 beep_label=0;
u16 beep_ms=0;
int j;
int weibuduiqi1;
int qiangjiao1;
int qianfangenemy1;
int position;
int yjdrz = 800;//��������ʱ���ֵ
int error;
int xt=0;
int HD[5]={1300,1300,0,0,0};
int left,right;
u16 ad1[16];
u16 HUI0,HUI1,HUI2,HUI3,HUI4;
u16 ceju5,ceju6,ceju7,ceju8,ceju9,ceju10,ceju11,ceju12,ceju13,ceju14,ceju15;
u16 hui0[5]={0},hui1[5]={0},hui2[5]={0},hui3[5]={0},hui4[5]={0};
void xuntai()
{
	if((AI(1)<HD[1])&&(AI(0)>HD[0]))//�ҽ����
	{
		xt=1;
	}
	else if((AI(0)<HD[0])&&(AI(1)>HD[1]))//����ҳ�
	{
		xt=2;
	}
	else if((AI(0)<HD[0])&&(AI(1)<HD[1]))//ȫ����ͷ
	{
		xt=3;
	}
	else
		xt=0;
}
void weibuduiqijiance()
{
		if((abs_my(ceju7,ceju8)<dqbz)&&(abs_my(ceju5,ceju6)<dqbz)&&(ceju15<czzx)&&((ceju9<czzx)||(ceju10<czzx)))
       weibuduiqi1=1;
		else
			 weibuduiqi1=0;
}
void qianfangenemy()
{
		if((ceju5>ceejuyz)&&(ceju6>ceejuyz))
			qianfangenemy1=1;
		else
			qianfangenemy1=0;
}
void taixiajiance()
{
		if((abs_my(ceju7,ceju8)<dqbz)&&(abs_my(ceju5,ceju6)<dqbz)&&(ceju15<czzx)&&(ceju10<czzx)&&(ceju9>czzx))
	{
			qiangjiao1=1;   //β����������ұ�Ϊ��
	}
	if((abs_my(ceju7,ceju8)<dqbz)&&(abs_my(ceju5,ceju6)<dqbz)&&(ceju15<czzx)&&(ceju9<czzx)&&(ceju10>czzx))
	{
			qiangjiao1=2;   //β������������Ϊ��
	}
	if((abs_my(ceju7,ceju8)<dqbz)&&(abs_my(ceju5,ceju6)<dqbz)&&(ceju15<czzx)&&(ceju10<czzx)&&(ceju9<czzx))
	{
			qiangjiao1=3;   //β������������ұ�Ϊ�գ�����������
	}
	else
		qiangjiao1=0;
}
void TIM2_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  ///ʹ��TIM3ʱ��
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	//�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);//��ʼ��TIM3
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE); //����ʱ��3�����ж�
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn; //��ʱ��3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x01; //�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}
void TIM5_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);  ///ʹ��TIM5ʱ��
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	//�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseInitStructure);//��ʼ��TIM5
	
	TIM_ITConfig(TIM5,TIM_IT_Update,ENABLE); //����ʱ��5�����ж�
	TIM_Cmd(TIM5,ENABLE); //ʹ�ܶ�ʱ��5
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM5_IRQn; //��ʱ��5�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x02; //��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x01; //�����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
//�����ʱ  ˵������ʱ����Ϊ 0


void start_time()
{
	count_ms_0=0;
	count_s_0=0;
	TIM_Cmd(TIM2,ENABLE);	//ʹ�ܶ�ʱ��3
}

//��ȡ��ʱ  ˵��������ϵͳ��ʱ����λ����
u16 mseconds()
{
	return count_ms_0;
}

//��ȡ��ʱ  ˵��������ϵͳ��ʱ����λ��			
u16 seconds()
{
	return count_s_0;
}

u16 getseconds()
{
	return (1000*count_s_0+count_ms_0);
}

void stop_time()
{
	TIM_Cmd(TIM2,DISABLE); //ʹ�ܶ�ʱ��2
}

void reset_time()
{
	count_ms_0=0;
	count_s_0=0;
}

void beep_time()
{
	beep_label = 1;
	BEEP = 1;
}
void beep_stop()
{
		beep_label = 0;
	  BEEP = 0;
}
void start_time_1()
{
	count_ms_1=0;
	count_s_1=0;
	TIM_Cmd(TIM5,ENABLE);	//ʹ�ܶ�ʱ��3
}

//��ȡ��ʱ  ˵��������ϵͳ��ʱ����λ����
u16 mseconds_1()
{
	return count_ms_1;
}

//��ȡ��ʱ  ˵��������ϵͳ��ʱ����λ��			
u16 seconds_1()
{
	return count_s_1;
}

u16 getseconds_1(){
	return (1000*count_s_1+count_ms_1);
}

void stop_time_1()
{
	TIM_Cmd(TIM5,DISABLE); //ʹ�ܶ�ʱ��2
}

void reset_time_1()
{
	count_ms_1=0;
	count_s_1=0;
}
//��ʱ��3�жϷ�����  1ms�ж�һ��
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET) //����ж�
	{
		count_ms_0++;
		
		if(count_ms_0 == 1000)  count_s_0++;
	}
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //����жϱ�־λ
}

int huidu_lvbo(int hui)
{
	     if(hui==0)
	 {
			int i,j=0,k=0;
			for(i=0;i<5;i++)
			{
			  if((hdctyz<hui0[i])&&(hddtyz>hui0[i])) 
			   j++;
			}
			for(i=0;i<5;i++)
			{
			  if(hui0[i]<hdctyz) 
			   k++;
			}
			if(j==5)  return 1;              //�������Ϊ�ڣ��ж�Ϊ��
      if(k==5)  return 2;              //����������գ��ж�Ϊ����
		}
	 if(hui==1)
	 {
			int i,j=0,k=0;
			for(i=0;i<5;i++)
			{
			  if((hdctyz<hui1[i])&&(hddtyz>hui1[i])) 
			   j++;
			}
			for(i=0;i<5;i++)
			{
			  if(hui1[i]<hdctyz) 
			   k++;
			}
			if(j==5)  return 1;              //�������Ϊ�ڣ��ж�Ϊ��
      if(k==5)  return 2;              //����������գ��ж�Ϊ����
		}
	 if(hui==2)
	 {
			int i,j=0,k=0;
			for(i=0;i<5;i++)
			{
			  if((hdctyz<hui2[i])&&(hddtyz>hui2[i])) 
			   j++;
			}
			for(i=0;i<5;i++)
			{
			  if(hui2[i]<hdctyz) 
			   k++;
			}
			if(j==5)  return 1;              //�������Ϊ�ڣ��ж�Ϊ��
      if(k==5)  return 2;              //����������գ��ж�Ϊ����
		}
	 if(hui==3)
	 {
			int i,j=0,k=0;
			for(i=0;i<5;i++)
			{
			  if((hdctyz<hui3[i])&&(hddtyz>hui3[i])) 
			   j++;
			}
			for(i=0;i<5;i++)
			{
			  if(hui3[i]<hdctyz) 
			   k++;
			}
			if(j==5)  return 1;              //�������Ϊ�ڣ��ж�Ϊ��
      if(k==5)  return 2;              //����������գ��ж�Ϊ����
		}
	 if(hui==4)
	 {
			int i,j=0,k=0;
			for(i=0;i<5;i++)
			{
			  if((hdctyz<hui4[i])&&(hddtyz>hui4[i])) 
			   j++;
			}
			for(i=0;i<5;i++)
			{
			  if(hui4[i]<hdctyz) 
			   k++;
			}
			if(j==5)  return 1;              //�������Ϊ�ڣ��ж�Ϊ��
      if(k==5)  return 2;              //����������գ��ж�Ϊ����
		}
}

void TIM5_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM5,TIM_IT_Update)==SET) //����ж�
	{
		 for(j=0;j<16;j++)    
		{
			ad1[j]=AI(j);		
		}
   	HUI0=ad1[0];
		HUI1=ad1[1];
		HUI2=ad1[2];
		HUI3=ad1[3];
		HUI4=ad1[4];
		
		for(j=0;j<5;j++)			//��������5��
	{	
		hui0[j]=hui0[j+1];
		hui1[j]=hui1[j+1];
		hui2[j]=hui2[j+1];
		hui3[j]=hui3[j+1];
	}
		hui0[4]=ad1[0];
		hui1[4]=ad1[1];
		hui2[4]=ad1[2];
		hui3[4]=ad1[3];
		hui4[4]=ad1[4];
  	ceju5=ad1[5];
  	ceju6=ad1[6];
		ceju7=ad1[7];
		ceju8=ad1[8];
		ceju9=ad1[9];
		ceju10=ad1[10];
		ceju11=ad1[11];
		ceju12=ad1[12];
		ceju13=ad1[13];
		ceju14=ad1[14];
		ceju15=ad1[15];
		if((hui0[4]<hdctyz)&&(hui1[4]<hdctyz)&&(hui2[4]<hdctyz)&&(hui3[4]<hdctyz)&&(hui4[4]<hdctyz))
			{  GoodMoto(0,0);
			                   }
	   	select_fall();
//	    taixiajiance();
//	    qianfangenemy();
//    	weibuduiqijiance();
	 int d[] = {AI(5), AI(6), AI(7), AI(8),AI(9), AI(10), AI(11), AI(12),AI(13), AI(14)};
   int maxNum = d[0];
	 int f=0;
	 int l;
	 int t;
   for (int i = 1; i < 10; i++)
   {
      if (maxNum < d[i])
      {
         maxNum = d[i];
				 f=i;
      }
			l=f+5;
   }
//	 switch (l)
//  {
//  	case 5:
//			if (abs_my(AI(5) , AI(6)) < 400 && maxNum>800 )//Ŀ������ǰ��,�Ҿ���ǰ����������
//				position=1 ;
//			if (abs_my(AI(5) , AI(11)) < 200 && maxNum>800)//Ŀ������ǰ��,�Ҿ���ǰ����������
//				position=2 ;
//			if(maxNum<800)
//				position=0;
//  		break;
//  	case 6:
//			if (abs_my(AI(5) , AI(6)) < 400 && maxNum>800)//Ŀ������ǰ��,�Ҿ���ǰ����������
//				position=1 ;
//			if (abs_my(AI(6) , AI(12)) < 200 && maxNum>800)//Ŀ������ǰ��,�Ҿ���ǰ����������
//				position=3 ;
//			if(maxNum<800)
//				position=0;
//  		break;
//	case 7:
//			if (abs_my(AI(7) , AI(8)) < 200&& maxNum>800)//Ŀ��������,�Ҿ���ǰ����������
//				position=4 ;
//			if (abs_my(AI(7) , AI(13)) < 200&& maxNum>800)//Ŀ�������,�Ҿ���ǰ����������
//				position=5 ;
//			if(maxNum<800)
//				position=0;
//			break;
//	case 8:
//			if (abs_my(AI(7) , AI(8)) < 200&& maxNum>800)//Ŀ��������,�Ҿ���ǰ����������
//				position=4 ;
//			if (abs_my(AI(7) , AI(13)) < 200&& maxNum>800)//Ŀ�����Һ�,�Ҿ���ǰ����������
//				position=6 ;
//			if(maxNum<800)
//				position=0;
//			break;
//  	case 9:
//			if (abs_my(AI(9) , AI(11)) < 200 && abs_my(AI(5) , AI(11)) < 200&& maxNum>800)//Ŀ������ǰ�����Ҿ����󷽴�������
//				position=8 ;
//			if (abs_my(AI(9) , AI(13)) < 200 && abs_my(AI(7) , AI(13)) < 200&& maxNum>800)//Ŀ������󷽣��Ҿ����󷽴�������
//				position=8 ;
//			if ((abs_my(AI(9) , AI(11)) < 200) && (abs_my(AI(9) , AI(13)) < 200)&& maxNum>800)//Ŀ������,�Ҿ�����ߴ�������
//				position=7 ;
//			if(maxNum<800)
//				position=0;
//  		break;
//	case 10:
//			if (abs_my(AI(10) , AI(12)) < 200 && abs_my(AI(6) , AI(12)) < 200&& maxNum>800)//Ŀ������ǰ�����Ҿ����ҷ���������
//				position=10;
//			if (abs_my(AI(10) , AI(14)) < 200 && abs_my(AI(8) , AI(14)) < 200&& maxNum>800)//Ŀ�����Һ󷽣��Ҿ����ҷ���������
//				position=10 ;
//			if ((abs_my(AI(10) , AI(12)) < 200) && (abs_my(AI(10) , AI(14)) < 200)&& maxNum>800)//Ŀ�����ҷ�,�Ҿ����ұߴ�������
//				position=9 ;
//			if(maxNum<800)
//				position=0;
//  		break;
//  	default:
//		{
//			position=0;
//  		break;
//		}
//  }
	 switch (l)
     {
  	  case 5:
			if(maxNum>800)
			position=1,error=0;
			else
			position=0;	
  		break;
  	  case 6:
			if(maxNum>800)
			position=1,error=0;
			else
				position=0;	
  		break;
	  case 7:
			if(maxNum>800)
				position=5,error=-100;
			else
				position=0;	
			break;
	  case 8:
			if(maxNum>800)
				position=5,error=-100;
			else
				position=0;	
			break;
	  case 9:
			if(maxNum>800)
				position=7,error=-100;
			else
				position=0;	
  		break;
	  case 10:
			if(maxNum>800)
			position=3,error=100;
			else
				position=0;	
  		break;
	  case 11:
			if(maxNum>800)
			position=8,error=-100;
			else
			position=0;	
  		break;
	  case 12:
			if(maxNum>800)
			position=2,error=100;
			else
			position=0;	
  		break;
	  case 13:
			if(maxNum>800)
			position=6,error=-100;
			else
				position=0;	
  		break;
	  case 14:
			if(maxNum>800)
			position=4,error=100;
			else
				position=0;	
  		break;
	  case 15:
			if(maxNum>800)
			position=5,error=-100;
			else
				position=0;	
  		break;
  	default:
		{
			position=0;
  		break;
		}
  }
  		if(error==0){
			left=400;
			right=400;
		}
		if(error!=0){
			left=error;
			right=-error;
		}
		xuntai();
}
	TIM_ClearITPendingBit(TIM5,TIM_IT_Update);  //����жϱ�־λ
}

