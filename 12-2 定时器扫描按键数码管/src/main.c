#include "REG52.H"
#include "Timer0.h"
#include "key.h"
#include "nixieTube.h"
#include "at24c02.h"
#include "delay.h"

unsigned char keyNum;
unsigned char min,sec,minisec;
unsigned char runFlag;
void main() {
    timer0_Init();
    while (1) {
        keyNum = key();
        if (keyNum == 1) runFlag = !runFlag;
        if (keyNum == 2) {
            min = sec = minisec = 0;
        }
        if (keyNum == 3)  {
            at24c02_WriteByte(0, min);
            delay(10);
            at24c02_WriteByte(1, sec);
            delay(10);
            at24c02_WriteByte(2, minisec);
            delay(10);
        }
        if (keyNum == 4) {
            min = at24c02_ReadByte(0);
            sec =  at24c02_ReadByte(1);
            minisec = at24c02_ReadByte(2);
        }

        nixie_setBuffer(1, min/10);
        nixie_setBuffer(2, min%10);
        nixie_setBuffer(3, 11);
        nixie_setBuffer(4, sec/10);
        nixie_setBuffer(5, sec%10);
        nixie_setBuffer(6, 11);
        nixie_setBuffer(7, minisec/10);
        nixie_setBuffer(8, minisec%10);
    }
}

void sec_loop(){
    if (runFlag){
        minisec++;
        if (minisec >= 100){
            minisec = 0;
            sec++;
            if (sec >= 60){
                sec = 0;
                min++;
                if (min >= 60){
                    min = 0;
                }
            }
        }
    }
    
    
}

void Timer0_Routine() interrupt 1 {
    static unsigned int T0Count, T0Count1,T0Count2;
    TL0 = 0x18;
    TH0 = 0xFC;
    T0Count++;
    if (T0Count == 15) {
        T0Count = 0;
        key_loop();
    }
    T0Count1++;
    if (T0Count1 >= 2) {
        T0Count1 = 0;
        nixie_loop();
    }
    T0Count2++;
    if (T0Count2 >= 10) {
        T0Count2 = 0;
        sec_loop();
    }
}