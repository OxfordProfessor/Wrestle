#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"

int O;
void USART3_Init(void)
{	USART_InitTypeDef  USART3_InitStruct;
    GPIO_InitTypeDef   GPIOC_InitStruct;
      NVIC_InitTypeDef   NVIC_InitStruct;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	USART_Cmd(USART3,ENABLE);
	

	USART3_InitStruct.USART_BaudRate=115200;
	USART3_InitStruct.USART_WordLength=USART_WordLength_8b;
	USART3_InitStruct.USART_StopBits=USART_StopBits_1;
	USART3_InitStruct.USART_Parity=USART_Parity_No;
	USART3_InitStruct.USART_Mode=USART_Mode_Rx | USART_Mode_Tx;
	USART3_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Init(USART3,&USART3_InitStruct);
	USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);
	
	
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource10,GPIO_AF_USART3);
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource11,GPIO_AF_USART3);
	GPIOC_InitStruct.GPIO_Pin=GPIO_Pin_10|GPIO_Pin_11;
	GPIOC_InitStruct.GPIO_Mode=GPIO_Mode_AF;
	GPIOC_InitStruct.GPIO_Speed=GPIO_Speed_100MHz;
	GPIOC_InitStruct.GPIO_PuPd=GPIO_PuPd_UP;
	GPIOC_InitStruct.GPIO_OType=GPIO_OType_PP;
  GPIO_Init(GPIOC,&GPIOC_InitStruct);	


	NVIC_InitStruct.NVIC_IRQChannel=USART3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}
void Openmv_find()
{
  if(USART_GetITStatus(USART3,USART_IT_RXNE))
	{
		O = USART_ReceiveData(USART3);
//        if(a==51)
	}
}