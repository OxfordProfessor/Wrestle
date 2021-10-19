#include "timer.h"
#include "beep.h" 
#include "led.h" 
#include "delay.h"
# define AI 				analog
u16 count_ms_0=0;
u16 count_s_0=0;
u16 count_ms_1=0;
u16 count_s_1=0;
int count_ms,timerled=0;
u8 beep_label=0;
u16 beep_ms=0;

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
int left,right;
int error;
extern int O;


//初始化PF9和PF10为输出口.并使能这两个口的时钟		    
//LED IO初始化
void TIM2_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  ///使能TIM3时钟
	
    TIM_TimeBaseInitStructure.TIM_Period = arr; 	//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);//初始化TIM3
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE); //允许定时器3更新中断
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn; //定时器3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}
void TIM5_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);  ///使能TIM3时钟
	
    TIM_TimeBaseInitStructure.TIM_Period = arr; 	//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseInitStructure);//初始化TIM3
	
	TIM_ITConfig(TIM5,TIM_IT_Update,ENABLE); //允许定时器3更新中断
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM5_IRQn; //定时器3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
//重设计时  说明：计时重设为 0
void start_time()
{
	count_ms_0=0;
	count_s_0=0;
	TIM_Cmd(TIM2,ENABLE);	//使能定时器3
}

//获取计时  说明：返回系统计时，单位毫秒
u16 mseconds()
{
	return count_ms_0;
}

//获取计时  说明：返回系统计时，单位秒			
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
	TIM_Cmd(TIM2,DISABLE); //使能定时器2
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
	TIM_Cmd(TIM5,ENABLE);	//使能定时器3
}

//获取计时  说明：返回系统计时，单位毫秒
u16 mseconds_1()
{
	return count_ms_1;
}

//获取计时  说明：返回系统计时，单位秒			
u16 seconds_1()
{
	return count_s_1;
}

u16 getseconds_1(){
	return (1000*count_s_1+count_ms_1);
}

void stop_time_1()
{
	TIM_Cmd(TIM5,DISABLE); //使能定时器2
}

void reset_time_1()
{
	count_ms_1=0;
	count_s_1=0;
}
//定时器3中断服务函数  1ms中断一次
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET) //溢出中断
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
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //清除中断标志位
}

//定时器实时数据判断区
int abs(int x,int y)
{
		if(x>y)
		return x - y;
		else 
		return y - x;	
}

void TIM5_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM5,TIM_IT_Update)==SET) //溢出中断
	{
         //巡台边缘
         if(AI(2)<370||AI(3)<370)
            Bianyuan=1,error=0;
         else
            Bianyuan=0;
        //后方灰度台边缘（防掉台）
        if(AI(4)<300||AI(5)<300)
            Behind_edge=1;
        else
            Behind_edge=0;
        //台下（车体四灰度检测黑，前后左右六灰度其中相对两个同时检测到
         if(AI(2)<300&&AI(3)<300&&AI(4)<300&&AI(5)<300&&((AI(8)>1000&&AI(9)>1000)||(AI(6)>1000&&AI(11)>1000)||(AI(7)>1000&&AI(10)>1000)))  
            Taixia=1;
         else if(AI(2)>200&&AI(3)>200&&AI(4)>200&&AI(5)>200)
            Taixia=0;
        //左/右卡台
         if((AI(2)<100&&AI(4)<100)||(AI(3)<100&&AI(5)<100))
            Katai=1;
         else 
            Katai=0;
        //正前方检测到
         if(AI(6)>1000||AI(7)>1000)
            Front_thing=1,error=0;
         else
            Front_thing=0;
        //左方检测到
         if(AI(8)>1100||AI(12)>1100||AI(14)>1100)
            Left_thing=1,error=100;
         else
            Left_thing=0,error=0;
        //右方检测到
         if(AI(9)>1100||AI(13)>1100||AI(15)>1100)        
            Right_thing=1,error=-100;
         else
            Right_thing=0;
        //后方检测到
         if(AI(14)>1100&&AI(15)>1100) 
            Behind_thing=1;
         else
            Behind_thing=0;
        //对齐台子
         if(AI(6)>1000&&AI(7)>1000&&AI(10)>1000&&AI(11)>1000&&AI(14)<700&&AI(15)<700&&((abs(AI(7),AI(6))<100)||(abs(AI(10),AI(11))<100)))
            Behind_taizi=1;
         else 
            Behind_taizi=0;
        //前铲出台
//        if((AI(2)<450&&AI(3)<450)||AI(0)<200||AI(1)<200)
         if(AI(0)<200||AI(1)<200||(AI(2)<400&&AI(3)<400))
            Chan_tai=1;
         else
            Chan_tai=0;
         //检测己方能量块
		if(error==0){
			left=400;
			right=400;
		}
		if(error!=0){
			left=error;
			right=-error;
		}
     
        
        
        TIM_ClearITPendingBit(TIM5,TIM_IT_Update);  //清除中断标志位
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
