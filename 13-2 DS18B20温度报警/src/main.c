#include "REG52.H"
#include "delay.h"
#include "LCD1602.h"
#include "at24c02.h"
#include "key.h"
#include "ds18b20.h"
#include "wire.h"
#include "STDIO.H"
#include "Timer0.h"

float T;
char Thigh=0,Tlow=0;
unsigned char keyNum;
unsigned char LCD_line;
char putchar(unsigned char c) {
    static int x = 1;
    if (c == '\n') {x = 1; return c;} 
    LCD_ShowChar(LCD_line, x++,c);
    return c;
}

void main(){
    timer0_Init();
    LCD_Init();
    AT24C02_Init();
    ds18b20_ConvertT();
    delay_ms(1000);
    while (1){
        keyNum = key();
        ds18b20_ConvertT();
        T = ds18b20_ReadT();
        LCD_line = 1;
        printf("T:%+.2f    \n", T);
        if (keyNum) {
            if (keyNum == 1){
                Thigh++;
            }
            if (keyNum == 2){
                Thigh--;
            }
            if (keyNum == 3){
                Tlow++;
            }
            if (keyNum == 4){
                Tlow--;
            }
            LCD_line = 2;
            printf("TH:%+4d\tTL:%+4d\n", (int)Thigh, (int)Tlow);
        }
        delay_ms(500);
    }
}
// 定时器中断检测按键
void Timer0_Routine() interrupt 1 {
    static unsigned int T0Count;
    TL0 = 0x18;
    TH0 = 0xFC;
    T0Count++;
    if (T0Count == 10) {
        key_loop();
        T0Count = 0;
    }
}