#include "LCD1602.h"
#include "REG52.H"
#include "Timer0.h"
#include "delay.h"

unsigned char sec=55, min=59, hour=23;
void main() {
    timer0_Init();
    LCD_Init();
    LCD_ShowString(1, 1, "CLOCK:");
    LCD_ShowString(2, 1, "  :  :");
    while (1) {
        LCD_ShowNum(2, 1, hour, 2);
        LCD_ShowNum(2, 4, min, 2);
        LCD_ShowNum(2, 7, sec, 2);
    }
}

void timer0_Routine() interrupt 1 {
    static unsigned int T0Count;
    TL0 = 0x18;
    TH0 = 0xFC;
    if (++T0Count == 1000) {
        T0Count = 0;
        if (++sec >= 60) {
            sec = 0;
            if (++min >= 60) {
                min = 0;
                if (++hour >= 24) {
                    hour = 0;
                }
            }
        }
    }
}