#include "REG52.H"
#include "LCD1602.h"
#include "STDIO.H"
sbit DQ = P3 ^ 7;

/*****��ʱ�ӳ���*****/
void delay(unsigned int t)
{
	for(;t>0;t--);
}


/*****��ʼ��DS18B20*****/
unsigned char Init_DS18B20(void)
{
  unsigned char x=0;
  DQ = 1;      //DQ��λ
  delay(8);    //������ʱ
  DQ = 0;      //��Ƭ����DQ����
  delay(80);   //��ȷ��ʱ������480us
  DQ = 1;      //��������
  delay(8);
  x = DQ;      //������ʱ�����x=0���ʼ���ɹ���x=1���ʼ��ʧ��
  delay(4);
  return x;
}

/*****��һ���ֽ�*****/
unsigned char ReadOneChar(void)
{
  unsigned char i=0;
  unsigned char dat = 0;
  for (i=8;i>0;i--)
  {
    DQ = 0;     // �������ź�
    dat>>=1;
    DQ = 1;     // �������ź�
    if(DQ)
    	dat|=0x80;
	delay(4);
  }
  return(dat);
}

/*****дһ���ֽ�*****/
void WriteOneChar(unsigned char dat)
{
  unsigned char i=0;
  for (i=8; i>0; i--)
  {
    DQ = 0;
    DQ = dat&0x01;
	delay(4);
    DQ = 1;
    dat>>=1;
  }
  delay(4);
}

/*****��ȡ�¶�*****/
int ReadTemperature(void)
{
  	unsigned char a=0;
  	unsigned char b=0;
  	unsigned int t=0;
  	t=Init_DS18B20();
  	if(t) return;
  	WriteOneChar(0xCC);  //����������кŵĲ���
  	WriteOneChar(0x44);  //�����¶�ת��
  	t=Init_DS18B20();
  	if(t) return;
  	WriteOneChar(0xCC);  //����������кŵĲ���
  	WriteOneChar(0xBE);  //��ȡ�¶ȼĴ���
  	a=ReadOneChar();     //����8λ
  	b=ReadOneChar();     //����8λ
    LCD_ShowBinNum(1,1,b,8);
    LCD_ShowBinNum(1,9,a,8);
  	t=b;
  	t<<=8;
  	t=t|a;
  	if(t<=0||t>0x900) 
	    return;
	t=t*0.0625;
  	return(t);
}

void main(){
    int temp;
    LCD_Init();

    while (1)
    {
        temp = ReadTemperature();
        LCD_ShowSignedNum(2, 1, temp, 3);
        
    }
    
}