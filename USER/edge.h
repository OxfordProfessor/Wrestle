#include "init.h"

#define AI 							analog
#define DI							digital
#define ClearScreen 		clear_screen
#define ShowStr 				display_GB2312_string		//�ַ�������
#define ShowAI					display_GB2312_u16 //��λ����
#define ShowDI					display_GB2312_u1		//һλ����
#define ServoSetMode		UP_CDS_SetMode					
#define ServoSetAngle		UP_CDS_SetAngle

int get_edge(void);//Ѳ̨
void back(void);             //����  ����ʱ200/��⵽���塪��ֹͣ��
void forward_stop(void);    //����  ����ʱ200����ֹͣ��
void turn_left90(void);     //��ת90����ʱ200/ǰ��⵽���塪��ֹͣ��
void turn_right90(void);     //��ת90����ʱ200/ǰ��⵽���塪��ֹͣ��