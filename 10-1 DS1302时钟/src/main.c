#include "DS1302.h"
#include "LCD1602.h"
#include "REG52.H"
#include "Timer0.h"
#include "delay.h"
unsigned char time[8];
unsigned char mode = 1, keyNum, timeSelect = 1, timeSetFlashFlag = 0;
char week[][7] = {"Mon", "Tue", "Wed", "Thur", "Fri", "Sat", "Sun"};

void showTime() {
    DS1302_Read_Time(time);
    LCD_ShowNum(1, 1, time[1], 2);
    LCD_ShowNum(1, 4, time[2], 2);
    LCD_ShowNum(1, 7, time[3], 2);
    LCD_ShowNum(2, 1, time[4], 2);
    LCD_ShowNum(2, 4, time[5], 2);
    LCD_ShowNum(2, 7, time[6], 2);

    LCD_ShowString(1, 10, week[time[7]]);
}
void setTime() {
    if (keyNum == 1) {
        mode = 1;
        timeSelect = 0;
        DS1302_Write_Time(time);
    }

    if (keyNum == 2) {
        if (++timeSelect > 7)
            timeSelect = 1;
    }
    if (keyNum == 3) {
        time[timeSelect]++;
    }
    if (keyNum == 4) {
        time[timeSelect]--;
    }

    if (timeSelect == 1 && timeSetFlashFlag)
        LCD_ShowString(1, 1, "  ");
    else
        LCD_ShowNum(1, 1, time[1], 2);
    if (timeSelect == 2 && timeSetFlashFlag)
        LCD_ShowString(1, 4, "  ");
    else
        LCD_ShowNum(1, 4, time[2], 2);
    if (timeSelect == 3 && timeSetFlashFlag)
        LCD_ShowString(1, 7, "  ");
    else
        LCD_ShowNum(1, 7, time[3], 2);
    if (timeSelect == 4 && timeSetFlashFlag)
        LCD_ShowString(2, 1, "  ");
    else
        LCD_ShowNum(2, 1, time[4], 2);
    if (timeSelect == 5 && timeSetFlashFlag)
        LCD_ShowString(2, 4, "  ");
    else
        LCD_ShowNum(2, 4, time[5], 2);

    if (timeSelect == 6 && timeSetFlashFlag)
        LCD_ShowString(2, 7, "  ");
    else
        LCD_ShowNum(2, 7, time[6], 2);

    if (timeSelect == 7 && timeSetFlashFlag)
        LCD_ShowString(1, 10, "    ");
    else
        LCD_ShowString(1, 10, week[time[7]]);
}

void main() {
    timer0_Init();
    LCD_Init();
    DS1302_Init();
    DS1302_Read_Time(time);
    LCD_ShowString(1, 1, "  /  /  ");
    LCD_ShowString(2, 1, "  :  :  ");
    while (1) {
        keyNum = key();
        switch (mode) {
            case 1:
                showTime();
                break;
            case 2:
                setTime();
                break;
            default:
                break;
        }
    }
}

void Timer0_Routine() interrupt 1 {
    static unsigned int T0Count;
    static unsigned int T0Count1;
    TL0 = 0x18;
    TH0 = 0xFC;
    T0Count++;
    T0Count1++;
    if (T0Count == 10) { //扫描按键
        T0Count = 0;
        if (keyNum) {
            if (keyNum == 1)
                mode = 1;
            if (keyNum == 2)
                mode = 2;
        }
    }
    if (T0Count1 == 500) { //选择控制闪烁
        T0Count1 = 0;
        timeSetFlashFlag = !timeSetFlashFlag;
    }
}