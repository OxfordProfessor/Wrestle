#include "ysy.h"//×¢ÊÍ¼ûÍ·ÎÄ¼þ
#include "delay.h"//×¢ÊÍ¼ûÍ·ÎÄ¼þ

# define front_get			    analog_scan_close()==2||analog_scan_close()==3
# define back_get				analog_scan_close()==7||analog_scan_close()==8      


//void GoodMoto(int lspeed,int rspeed);

   
u8 flag_1 = 0;//Ç°²ù³öÀÞÌ¨µÄ±êÖ¾
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

void start_feedback(void)   //¿ª»úÒ³Ãæ
{
	ShowStr(2,1,"Óñºâ¶Ó");
//	beep();
//	led_on();
//	delay_ms(50);
//	beep();
//	led_off();
	ClearScreen();
}


void test(void)             //ÆÁÏÔ²âÊÔ
{
	int i;
	u8 Key = 0;
	ClearScreen();
	while(1)
		{
			ShowStr(0,1,"1¡¢´«¸ÐÆ÷¼ì²â");
			ShowStr(2,1,"2¡¢¶æ»ú¼ì²â");
			ShowStr(4,1,"3¡¢µç»ú¼ì²â");
			ShowStr(6,1,"4¡¢·µ»Ø");
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
					GoodMoto(400,400);       //²â100µ½199£¬200µ½299£¬300µ½399£¬400µ½499
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
						ShowStr(0,1,"°´¼üÒÔ¸Ä±ä");
						ShowStr(2,1,"µç»ú×ªËÙ:");
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

void up_stage(void)         //¿ª»úÉÏÌ¨
{
    ClearScreen();
	ShowStr(2,5,"ÉÏÌ¨");
    delay_ms(300);
    ClearScreen();

            GoodMoto(-450,-450);
            count_ms=1200;
            while(count_ms){delay_us(1);}
            GoodMoto(0,0);//Í£Ö¹
            count_ms=500;
            while(count_ms){delay_us(1);}
            GoodMoto(-200,200);//×ó×ª135¶È³¯ÏòÀÞÌ¨ÖÐ¼ä
            count_ms=600;
            while(count_ms){delay_us(1);}
}
void up_stage1(void)         //¿ª»úÉÏÌ¨
{
    ClearScreen();
	ShowStr(2,5,"ÉÏÌ¨");
    delay_ms(300);
    ClearScreen();

            GoodMoto(-550,-550);
            count_ms=1500;
            while(count_ms){delay_us(1);}
            GoodMoto(0,0);//Í£Ö¹
            count_ms=500;
            while(count_ms){delay_us(1);}
            GoodMoto(-200,200);//×ó×ª135¶È³¯ÏòÀÞÌ¨ÖÐ¼ä
            count_ms=600;
            while(count_ms){delay_us(1);}
    }

void get_edge(void)         //ÎÞµÐÑ²Ì¨
{
   while(Front_thing==0&&Left_thing==0&&Right_thing==0&&Behind_thing==0)
    {
        ClearScreen();    
        ShowStr(0,3,"Ñ²Ì¨");
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
void select_high(void)      //Ì¨ÏÂÑ°ÕÒÌ¨×Ó²¢µÇÌ¨
{
    while(Taixia==1)
    {
            ClearScreen();
            ShowStr(0,1,"Ì¨ÏÂ");
            if(Taixia==1)    //Ì¨ÏÂ
            {
//                if(AI(6)>1200&&AI(7)>1200&&AI(10)>1000&&AI(11)>1000&&AI(14)<350&&AI(15)<350)  //¶ÔÆëÌ¨×Ó  
						while(Behind_taizi==0)  //¶ÔÆëÌ¨×Ó    
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
//                                    GoodMoto(-450,-450);        //µÇÌ¨
//                                    if(mseconds()>1500) break;   
//                                } 
                       
          }
         
    }
}

void Go_fight(void )        //Ç°½ø¹¥»÷£¨Ç°²ù³öÌ¨×ó×ª180¶È·µ»Ø£©
 {
    while(Front_thing==1&&Behind_edge==0)
    {
//        ClearScreen();
//        ShowStr(2,1,"Ö±ÐÐ¹¥»÷");
//        GoodMoto(300,300); 
//            if(Chan_tai==1||O==51)//Ç°²ù³öÌ¨
//            {   
//                back();
//                GoodMoto(-125,250);//×ó×ª180
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
                ShowStr(2,1,"¼º·½ÄÜÁ¿¿é");
				back1();
                turn_right90();
				GoodMoto(300,300);
                break;
				O=0;
            }
            else 
            {        
                ClearScreen();
                ShowStr(2,1,"Ö±ÐÐ¹¥»÷");
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

void Xun_tai(void)          //Ñ²Ì¨£¨º¬¹¥»÷£©
{
    while(Taixia==0)
    {
//        if(Bianyuan==1) back();
//        ClearScreen();
//        ShowStr(2,1,"Ì¨ÉÏ");
        if(Left_thing==1)//×ó±ßÓÐÎïÌå
            {
               start_time();
               ClearScreen();
               ShowStr(2,1,"×ó²à"); 
//               while(Front_thing==0&&Right_thing==0&&Behind_thing==0)
               while(Front_thing==0)
               { 
                    GoodMoto(100,-100); 
               
               }              
            }
        else if(Right_thing==1)//ÓÒ±ßÓÐÎïÌå
            {
               start_time();
               ClearScreen();
               ShowStr(2,1,"ÓÒ²à");
//              while(Front_thing==0&&Left_thing==0&&Behind_thing==0)
                while(Front_thing==0)
               { 
                    GoodMoto(-100,100); 
               
               }   
            }
        else if(Behind_thing==1)//ºó·½ÓÐÎïÌå
            {
               start_time();
               ClearScreen();
               ShowStr(2,1,"ºó·½");
                while(Front_thing==0)
               { 
                   GoodMoto(200,-200); 
               }   
            }    
        else if(Front_thing==1&&Bianyuan==0)//Ç°·½ÓÐÎïÌå
            {    
                Go_fight(); 
            }                    
//            }
        else get_edge();
     }
 }

    



















//	      ShowStr(0,3,"90¶È×ªÍä");						 
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
//	ShowStr(0,1,"µ±Ç°ËÙ¶È");
//	ShowStr(2,1,"Left      Right");
//	ShowAI(4,1,Ls);
//	ShowAI(4,80,Rs);
//}

//int abs_my(int a,int b)//²îµÄ¾ø¶ÔÖµ
//{
//	if((a-b)>=0)
//		return a-b;
//	else
//		return b-a;
//}

//int Touch(void)//´¥ÃþAD×ª»»
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


//int analog_scan_close(void)//¼ì²â×î½üÎïÌå
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


//int analog_scan_far(void)//¼ì²â×îÔ¶ÎïÌå
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

//void touch_sensor()//´¥ÃþÄ£¿éAI(12)
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


//int select_high(void)//µôÌ¨¼ì²â
//{
//	int i;
//	ClearScreen();
//	if(AI(0)>2490&&AI(1)>2090&&AI(2)>2600&&AI(3)>2650&&AI(4)>2650&&AI(5)>2620&&flag_1==1)//µôÌ¨
//	{
//		allmotor(0,0,0,0);//É²³µ
//		Find_Taizi();
//		return 1;
//	}
////	for(i=1;i<=7;i++)
////	{
////			if(AI(i)>1000&&AI(i+1)>1000&&AI(i+4)>1000)	//ÖÐ¼ä¶à¼ÓÒ»¸öÌõ¼þ£¬Ò»¶¨³Ì¶ÈÉÏ¼õÉÙÎóÅÐ£¬µ«¼ì²âµôÌ¨ ·´Ó¦ÉÔ³Ù¶ÙÒ»Ð
////			{
////				ShowStr(0,1,"µôÌ¨");
////				GoodMoto(0,0);//É²³µ
//////			touch_sensor();
////				Find_Taizi();	
////				return 1;
////			}
////	}
//	
////	if(AI(2)>1000&&AI(3)>1000&&AI(11)>1000)
////	{
////		ShowStr(0,1,"ÌØÊâµôÌ¨×ó");
////		GoodMoto(0,0);
////	  touch_sensor();
////		Find_Taizi();
////	}
////	if(AI(2)>1000&&AI(3)>1000&&AI(7)>1000)
////	{
////		ShowStr(0,1,"ÌØÊâµôÌ¨ÓÒ");
////		GoodMoto(0,0);
////	    touch_sensor();
////		Find_Taizi();
////	}
//	return 0;//»¹ÔÚÌ¨ÉÏ
//}

//void find_single()
//{
//	switch(analog_scan_close())
//	{
////		case 1:		//×óÇ°40¶È
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>80)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
////				GoodMoto(-400,400);
////			}
////			break;
////		}
//case 1:		//×óÇ°
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>300||Front_thing)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
//				allmotor(400,500,400,500);
//			
//			}
//			break;
//		}
//case 2:		//ÓÒÇ°
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>300||Front_thing)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
//				allmotor(500,400,500,400);
//			}
//			break;
//		}
////		case 4:		//ÓÒÇ°40¶È
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>80)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
////				GoodMoto(700,-700);
////			}
////			break;
////		}
////		case 5:		//ÓÒÇ°60¶È
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>70)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
////				GoodMoto(800,-800);
////			}
////			break;
////		}
//case 5:		//ÓÒ90¶È
//		{
//			reset_time();
//			while(1)
//			{
//				allmotor(500,-500,500,-500);
//				if(get_edge()||mseconds()>300||Front_thing)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
//														} 
//			break;
//		}
//		case 6:		//×ó90¶È
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>300||Front_thing)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
//				allmotor(-500,500,-500,500);
//			}
//			break;
//		}
////		case 7:		//ÓÒºó45¶È
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>100)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
////				GoodMoto(800,-800);
////			}
////			break;
////		}
//		case 3:		//ºó×ó
//		{
//			reset_time();
//			while(1)
//			{
//				allmotor(400,-600,400,-600);
//				if(get_edge()||mseconds()>400||Front_thing)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
//				
//			}
//			break;
//		}
//			case 4:		//ºó
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>400||Front_thing)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
//				allmotor(-600,400,-600,400);
//			}
//			break;
//		}
////				case 7:		//Ç°×ó
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>250||Front_thing)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
////				allmotor(-400,-400,400,400);
////			}
////			break;
////		}
////			case 8:		//Ç°ÓÒ
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>250||Front_thing)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
////				allmotor(400,400,-400,-400);
////			}
////			break;
////		}
//					case 9:		//ÕýÇ°
//		{
//			reset_time();
//			while(1)
//			{
//				
//				if(get_edge()||mseconds()>80)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
//			allmotor(700,700,700,700);
//			}
//			break;
//		}
//			case 10:		//Õýhou
//		{
//			reset_time();
//			while(1)
//			{
//					allmotor(-700,700,-700,700);
//				if(get_edge()||mseconds()>500)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
//		
//			}
//			break;
//		}
////		case 9:		//×óºó45¶È
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>100)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
////				GoodMoto(-800,800);
////			}
////			break;
////		}
//	
////		case 11:		//×óÇ°60¶È
////		{
////			reset_time();
////			while(1)
////			{
////				if(get_edge()||mseconds()>100)	break;//´¦ÀíµôÌ¨¡¢±ßÔµµÈÇé¿ö
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

