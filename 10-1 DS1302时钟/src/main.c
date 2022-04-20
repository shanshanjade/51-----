#include "DS1302.h"
#include "LCD1602.h"
#include "REG52.H"
#include "delay.h"
unsigned char time[8];

void main() {
    LCD_Init();
    DS1302_Init();
    DS1302_Write_Time(22, 4, 19, 15, 59, 50, 2);  //年 月 日 时 分 秒 周
    while (1) {
        DS1302_Read_Time(time);
        LCD_ShowNum(1, 1, time[1], 2);
        LCD_ShowNum(1, 4, time[2], 2);
        LCD_ShowNum(1, 7, time[3], 2);
        LCD_ShowNum(2, 1, time[4], 2);
        LCD_ShowNum(2, 4, time[5], 2);
        LCD_ShowNum(2, 7, time[6], 2);
    }
}