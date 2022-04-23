#include "REG52.H"
#include "Timer0.h"
#include "key.h"
#include "nixieTube.h"
#include "LCD1602.h"

unsigned char keyNum;
unsigned char temp = 0;
void main() {
    timer0_Init();
    LCD_Init();
    while (1) {
        keyNum = key();
        if (keyNum)
            temp = keyNum;
    }
}

void Timer0_Routine() interrupt 1 {
    static unsigned int T0Count, T1Count;
    TL0 = 0x18;
    TH0 = 0xFC;
    T0Count++;
    if (T0Count == 20) {
        T0Count = 0;
        key_loop();
    }
    T1Count++;
    if (T1Count == 5) {
        T1Count = 0;
        nixie_loop();
    }
}