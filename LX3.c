#include <reg52.h>
typedef unsigned char BYTE;//定义8位变量，BYTE字节
typedef unsigned int WORD;// 定义16位变量，WORD字
sbit rs=P0^7;/*数据/命令选择端，=1向液晶屏发数据;=0向液晶屏发命令，即将特殊含义的数;送入液晶屏，清屏0x01*/
sbit rw=P0^6;/*读写选择，=1读，从液晶屏中读出数据;     =0写，将数据送入液晶屏*/
sbit en=P0^5;//使能信号，=1，可以使用液晶屏

//这个延迟函数是给12M晶振用的，而我们的开发板上是11.0592MHZ的晶振，所以不准(有误差，凑活着用吧，可以自己改写)
void delay(WORD z)
{
	WORD x,y;
	for(x=z;x>0;x--)
   for(y=110;y>0;y--);//1ms延时函数 
}


BYTE wz,i,j,k,temp,flag,key;

WORD t;

void lcd_wcmd (BYTE cmd)//写入命令函数
{
  rs=0;//命令
  rw=0;//写，将数据送入液晶屏
  delay(5);
  P2=cmd ;//将具体命令代表的数据送入P2
  delay(5);
  en=1;// 开使能信号，液晶屏可以使用
  delay(5);
  en=0; //关使能信号，液晶屏关闭
}
void lcd_wdat (BYTE dat)//写入数据函数
{
  
  rs=1;//数据
  rw=0;//写，将学号数据送入液晶屏
  delay(5);
  P2=dat ;//将数据（学号）送入P2
  delay(5);
  en=1;//开使能，液晶屏可以使用
  delay(5);
  en=0;// 关使能，关闭液晶屏
}

void lcd_pos (BYTE pos)//调整位置函数
{
  lcd_wcmd (pos|0x80);//将第1排的开始位置变为00
}

//自己写第二排（调整位置函数）在1602的数据手册里面有寄存器的值

void lcd_init (  )//初始化液晶屏函数
{
  lcd_wcmd (0x38);/*显示模式设置，含义：
16×2显示，5×7点阵，8位数据接口*/
  delay (1);
  lcd_wcmd (0x0c);//光标打开
  delay (1);
  lcd_wcmd (0x06);//送入数据后，光标在后面
  delay (1);
  lcd_wcmd (0x01);//清屏
  delay (1);
}

void keyscan()	//扫描按键是否按下
{
  //键盘扫描函数只给出大概写法，搭配字符位置显示（扫描位置函数）

		P1=0xfe;	//扫描第4列
		temp=P1;temp=temp&0xf0;
		if(temp!=0xf0)	//判断按键是否按下
		{

				switch(temp)
				{
					case 0xe0:key='D';
					case 0xd0:key='C';
					case 0xb0:key='B';lcd_pos(0x0e);lcd_wdat('B');break;
					case 0x70:key='A';lcd_pos(0x06);lcd_wdat('A');break;
				}
			

		}
	
}

main()
{
  
	lcd_init();//调用初始化函数
    

	while(1)
	{
		  keyscan();
	}
}
