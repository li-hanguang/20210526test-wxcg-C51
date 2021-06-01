#include <reg52.h>
#define uchar unsigned char//8位定义
#define uint  unsigned int//16位定义
sbit rs  = P0^7;//数据/命令，H/L，数据=1，命令=0
sbit rw = P0^6;/*读/写，从屏内取数据，读=1；把数据送到屏内，写=0*/
sbit en  = P0^5;//=1，可以使用，=0停止使用
sbit psb = P0^4;/* =1，并行传送，10100001，一次传8个数据；=0，串行传送，10100001，一次传1个*/
sbit BEEP=P3^6;

//和LX3一样，延迟不准，有误差
void delay(int z)
{
	unsigned int x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);//1ms延时函数
}

uchar code table1[]={"2019123466"};
uchar code table2[]={    }; //音乐音符的显示自己查表（提示：对应值）//详情参照12864数据手册
uchar code table3[]={"无线传感网课程  "};
uchar code table4[]={"课堂综合练习    "};
uchar code table5[]={"               "};  
uchar code table6[]={"    综合练习    "};

uchar wz,i,j,k,temp,flag,key,t;
uchar Disp_num=0;

void lcd_wcmd (uchar cmd)//写入命令函数
{
  rs=0;//命令
  rw=0;//写，将数据送入液晶屏
  en=0;//关使能信号
  P2=cmd ;//将命令送入P2
  delay(1);
  en=1;// 开使能信号
  delay(1);
  en=0; //关使能信号
  }

void lcd_wdat (uchar dat)//写入数据函数
{
  rs=1;//数据
  rw=0;//写，将学号数据送入液晶屏
  en=0;//关使能
  P2=dat ;//将数据送入P2
  delay(1);
  en=1;//开使能
  delay(1);
  en=0;// 关使能
}

void lcd_pos (uchar pos1,uchar pos2)//设置显示位置
{
  if (pos1==0)  {pos1=0x80;} //第1排
  if (pos1==1)  {pos1=0x90;}//第2排
  if (pos1==2)  {pos1=0x88;}//第3排
  if (pos1==3)  {pos1=0x98;}//第4排
  wz=pos1+pos2;
  lcd_wcmd(wz);
 }
void lcd_init( )//初始化液晶屏函数
{
  psb=1;
  lcd_wcmd(0x0c);//打开屏幕，关闭游标及游标反白显示。
  delay(1);
  lcd_wcmd(0x30);//设置基本指令集，8位并行数据。
  delay(1);
  lcd_wcmd(0x01);//清屏
  delay(1);
}


main(  )
{
	
	 lcd_init ( );//调用初始化函数
	 lcd_pos (0,0);//调用位置函数,第1排
     i=0;
     while(table1[i]!='\0')
     {
        lcd_wdat(table1[i]);
        i++;
        delay (1);
     }
		 
     i=0;
     lcd_pos (1,0);//调用位置函数,第2排111111111111111111111111111111111111
     while(table2[i]!='\0')
     {
        lcd_wdat(table2[i]);
        i++;
        delay (1);
     }
		 
     i=0;
     lcd_pos (2,0);//调用位置函数,第3排
     while(table3[i]!='\0')
     {
           lcd_wdat(table3[i]);
           i++;
           delay (1);
     }
		 
		 i=0;
     lcd_pos (3,0);//调用位置函数,第4排
     while(table3[i]!='\0')
     {
           lcd_wdat(table4[i]);
           i++;
           delay (1);
     }
		 
		 delay(3000); //延时3m
		 
		 i=0;
     lcd_pos (1,0);//调用位置函数,第.排
     while(table2[i]!='\0')
     {
        lcd_wdat(table5[i]);
        i++;
        delay (1);
     }
		 
		 i=0;
     lcd_pos (3,0);//调用位置函数,第.排
     while(table2[i]!='\0')
     {
        lcd_wdat(table6[i]);
        i++;
        delay (10);
     }
		 
		
		 
		 
		 
		 
		 
	while(1);
 }
