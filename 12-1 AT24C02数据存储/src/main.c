#include "REG52.H"
#include "LCD1602.h"
#include "key.h"
#include "at24c02.h"
#include "delay.h"
unsigned char readData, count;
void initEx0();

void main() {
    initEx0();
    LCD_Init();
    LCD_ShowString(1, 1, "at24c02");
    // at24c02_WriteByte(1, 1);
    delay(10);
    readData = at24c02_ReadByte(1);
    LCD_ShowNum(2, 1, readData, 4);
    while (1) {
    }
}


void initEx0() {
    EA  = 1;	 //开启总中断
    EX0 = 1;	 //开启0号外部中断
    IT0 = 1;	 //设置外部中断触发方式 //0 - 低电平触发 //1 - 负跳变触发
}
void ex0_intr() interrupt 0 { 
    //每进入一次中断，则次数加一
    count = count + 1;
    if(count == 10)
        count = 0;
    LCD_ShowNum(2, 10, count, 2);
}