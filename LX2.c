#include<reg52.h>  //52单片机头文件
#define uchar unsigned char  //宏定义
#define uint unsigned int  //宏定义


uchar  num=0,num1=0,a=0 ,i,l;//8位
uint  j;//16位
//uchar code table1[]={0xfe,0xfd,0xfb,0xf7};//从左到右管位亮
uchar code table2[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e,0xff};// 0-7的显示0xf8
uchar code table3[]={0xe7,....}; //45,36,27,18,mie,18....一共9个或10个-自己算...

//定时器中断，我删掉了，自己写（我写的与例程不同）
void InitTimer0()
{	

	
}



void main()
{
	InitTimer0();  //定时器来干活
	
	P2=0xfe; //点亮第一个数码管
	//P0=0xc0; // 显示 0  -- 可加可不加
		
	while(1)  //主事件循环
	{
		
		if(i==6 && j<96) // 6*50 = 300 ms
		{
			//P0=0xff;
			i=0;
			num++;
			if(num==16)  //
			{
				num = 0;
			}
		}
		
		
		if(j==96)
		{
			P2=0xff;
		}
		
		P0 = table2[num];
		
	}
	
	
	
}

void Timer0Interrupt(void) interrupt 1
{
    TH0 = 0x;
    TL0 = 0x;
	
	i++;
	j++;
	l++;
	
	
//参照数码管的写法来写灯  
		if(...)
    {
      ....
    }
	
		
	
    
	
}
