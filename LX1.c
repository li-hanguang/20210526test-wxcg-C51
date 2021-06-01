#include <reg52.h>
#define uchar unsigned char
#define uint  unsigned int
sbit BEEP=P3^6;//蜂鸣器定义
sbit s1=P3^5;//独立键盘S1定义
sbit s3=P3^3;//独立键盘S3定义
uchar i,j;
void delay(uint z)            
{
	uint x,y;             	
for(x=z;x>0;x--)
	for(y=110;y>0;y--);
}
void main( )
{
	//P1=0x7e;//学号灯点亮
	//delay(1000);//等待1秒钟
	
if(s1==0)
		{
			delay(5);	  //消抖动
			if(s1==0)	  //确认按键被按下
			{
				while(!s1);//松手检测，S1不等于0，代表松手
				P1=0xFF;
          for(i=5;i>0;i--)
          {
          P1=0x7e; 
          delay(500);
				 P1=0XFF; 
            delay(500);
          for(j=0;j<67;j++)
         {
					 BEEP=0;//发声
					 delay(1);
					 BEEP=1;//停止发声
					 delay(1);
				 }

			}
		}
}
		
if(s3==0)
		{
			delay(5);	  //消抖动
			if(s3==0)	  //确认按键被按下
			{
				while(!s3);//松手检测，S3不等于0，代表松手
          for(i=5;i>0;i--)
          {
          P1=0x3f; //87
          delay(500);//间隔500毫秒
				  P1=0xCF; //65
          delay(500);
         P1=0xf3; //43
          delay(500);
						P1=0xfc; //21
          delay(500);
						P1=0xfe; //1
          delay(500);
						P1=0xFF; //ximie
          delay(500);
			 }
			}
		}
}
