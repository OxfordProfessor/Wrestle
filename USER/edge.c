#include "edge.h"
#include "ysy.h"

# define AI 				analog
# define DI					digital


# define Front_thing			AI(0)>800||AI(1)>800//analog_scan_close()					//����

extern int count_ms;
extern int Behind_edge;

void GoodMoto(int lspeed,int rspeed);

void back()              //����  ����ʱ200/��⵽���塪��ֹͣ��
{ 
    start_time ();
	while(1)
	{
        GoodMoto(-400,-400);
		if(mseconds()>500||Behind_edge==1)	   break;
	}
 
}

void forward_stop()      //����  ����ʱ200����ֹͣ��
{
	start_time();
	while(1)
	{
		GoodMoto(-500,-500);	
		if(mseconds()>1000)	break;
	}
	back();
}

void turn_left90()      //��ת90����ʱ200/ǰ��⵽���塪��ֹͣ��
{
	start_time();
	while(1)
	{
		GoodMoto(-200,200);
		if(mseconds()>2000||Front_thing)       break;	
	}
}

void turn_left45()      //��ת90����ʱ200/ǰ��⵽���塪��ֹͣ��
{
	start_time();
	while(1)
	{
		GoodMoto(-200,200);
		if(mseconds()>1000||Front_thing)       break;	
	}
}

void turn_right90()     //��ת90����ʱ200/ǰ��⵽���塪��ֹͣ��
{
	start_time();
	while(1)
	{
		GoodMoto(200,-200);
		if(mseconds()>450||Behind_edge==1)       break;	
	}
}

void turn_right135()     //��ת135����ʱ200/ǰ��⵽���塪��ֹͣ��
{
	start_time();
	while(1)
	{
		GoodMoto(200,-200);
		if(mseconds()>600||Behind_edge==1)       break;	
	}
}












//void edge_spin()
//{
//	reset_time();
//	while(1)
//	{
//		GoodMoto(-200,-200);	
//		if(mseconds()>400||Front_thing)	
//        break;
//	}
//}
//extern u8 flag_1;//ǰ������̨�ı�־
//int get_edge()
//{
//	if(F_G_E)//ǰ����̨
//	{
//		
//		if(LF_G_E)
//		{
//			ShowStr(2,1,"---���");
//			forward_stop();
//			turn_right90();
//		}
//		else if(Befor_edge)//��̨ǰ״̬��¼
//		{
//			flag_1 = 1;
//		}
//		else if(RF_G_E)
//		{
//			ShowStr(2,1,"�Ҳ�---");
//			forward_stop();
//			turn_left90();
//		}
//		else
//		{
//			forward_stop();
//			edge_spin();
////			GoodMoto(0,0);
////			delay_ms(1000);
//		}
//		allmotor(150,150,150,150);//ǰ��
//		delay_ms(100);
//		return 1;
//	}
//	else
//	{
//		allmotor(100,100,100,100);
//		return 0;
//	}
//}