#include "timer.h"
#include "beep.h" 
#include "led.h" 
#include "ysy.h"
# define AI 				analog
# define maxDistance        800
# define SensorDifference   400
# define BasicVelocity	    400
u16 count_ms_0=0;
u16 count_s_0=0;
u16 count_ms_1=0;
u16 count_s_1=0;
int count_ms,timerled=0;
u8 beep_label=0;
u16 beep_ms=0;

int error;
int differsu;
int Taixia;
int Katai;
int Left_thing;
int Right_thing;
int Front_thing;
int Behind_thing;
int Behind_taizi;
int Bianyuan;
int Chan_tai;
int Behind_edge;
int Own;
extern int O;
extern int left,right;

//��ʼ��PF9��PF10Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
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
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}
void TIM5_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);  ///ʹ��TIM3ʱ��
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	//�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseInitStructure);//��ʼ��TIM3
	
	TIM_ITConfig(TIM5,TIM_IT_Update,ENABLE); //����ʱ��3�����ж�
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM5_IRQn; //��ʱ��3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //�����ȼ�3
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
		if(beep_label == 1 )
		{
			beep_ms++;
			if(beep_ms >= 200)
			{
				BEEP = 0;
				beep_label = 0;
				beep_ms = 0;
			}
		}
		count_ms--;
		count_ms_0++;
		
		if(count_ms_0 == 1000)  count_s_0++;
	}
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //����жϱ�־λ
}

//��ʱ��ʵʱ�����ж���

void TIM5_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM5,TIM_IT_Update)==SET) //����ж�
	{
         //Ѳ̨��Ե
         if(AI(2)<380||AI(3)<380)
            Bianyuan=1;
         else
            Bianyuan=0;
        //�󷽻Ҷ�̨��Ե������̨��
        if(AI(4)<300||AI(5)<300)
            Behind_edge=1;
        else
            Behind_edge=0;
        //̨�£������ĻҶȼ��ڣ�ǰ���������Ҷ������������ͬʱ��⵽
         if(AI(2)<300&&AI(3)<300&&AI(4)<300&&AI(5)<300&&((AI(8)>1000&&AI(9)>1000)||(AI(6)>1000&&AI(11)>1000)||(AI(7)>1000&&AI(10)>1000)))  
            Taixia=1;
         else if(AI(2)>200&&AI(3)>200&&AI(4)>200&&AI(5)>200)
            Taixia=0;
        //��/�ҿ�̨
         if((AI(2)<100&&AI(4)<100)||(AI(3)<100&&AI(5)<100))
            Katai=1;
         else 
            Katai=0;
        //��ǰ����⵽
         if(AI(6)>1000&&AI(7)>1000&&(AI(6)-AI(7)<350||AI(7)-AI(6)<350))
            Front_thing=1;
         else
            Front_thing=0;
        //�󷽼�⵽
         if(AI(8)>1100||AI(12)>1100||AI(14)>1100)
            Left_thing=1;
         else
            Left_thing=0;
        //�ҷ���⵽
         if(AI(9)>1100||AI(13)>1100||AI(15)>1100)        
            Right_thing=1;
         else
            Right_thing=0;
        //�󷽼�⵽
         if(AI(14)>1100&&AI(15)>1100) 
            Behind_thing=1;
         else
            Behind_thing=0;
        //����̨��
         if(AI(6)>1200&&AI(7)>1200&&AI(10)>1000&&AI(11)>1000&&AI(14)<700&&AI(15)<700&&((AI(7)-AI(6)<300)||(AI(7)-AI(6)<300)))
            Behind_taizi=1;
         else 
            Behind_taizi=0;
        //ǰ����̨
//        if((AI(2)<450&&AI(3)<450)||AI(0)<200||AI(1)<200)
         if(AI(0)<200||AI(1)<200||(AI(2)<400&&AI(3)<400))
            Chan_tai=1;
         else
            Chan_tai=0;
         //��⼺��������
		 
		int d[] = {AI(6), AI(7), AI(8), AI(9),AI(10), AI(11), AI(12), AI(13),AI(14),AI(15)};
        int maxNum = d[0];
	    int f=0;
	    int l;
	    int t;	
        for (int i = 1; i < 11; i++)
        {
           if (maxNum < d[i])
           {
              maxNum = d[i];
			  f=i;
           }
		   l=f+6;
        }
		
		if(maxNum>800)
		{
			switch(l)
			{
				case 6:
					if(abs_my(AI(6) , AI(7)) < 400)
					{
						error=0;
					}
					else{
						error=-1;
				}
				break;
				case 7:
					if(abs_my(AI(6) , AI(7)) < 400)
					{
						error=0;
					}
					else{
						error=1;
					}
				break;
				case 8:
					error=-3;
				break;
				case 9:
					error=3;
				break;
				case 10:
					if(abs_my(AI(10) , AI(11)) < 400)
					{
						error=6;
					}
					else{
						error=-5;
					}
				break;
				case 11:
					if(abs_my(AI(10) , AI(11)) < 400)
					{
						error=6;
					}
					else{
						error=5;
					}
				break;		
				case 12:
					error=-2;
				break;		
				case 13:
					error=2;
				break;		
				case 14:
					error=-4;
				break;				
				case 15:
					error=4;
				break;					
			}
			differsu=TrackAL(error,0);
		}
		else{
			error=NULL;
		}
        left=BasicVelocity+differsu;
		right=BasicVelocity-differsu;
        
		
        TIM_ClearITPendingBit(TIM5,TIM_IT_Update);  //����жϱ�־λ
	}
//    
//    count_ms--;
//    
    timerled++;
	if(timerled>1000)
	{
		timerled=0;
	}
	else if(timerled < 500)
	{
		beep();
	}
	else
	{
		beepoff();
	}
    
}
