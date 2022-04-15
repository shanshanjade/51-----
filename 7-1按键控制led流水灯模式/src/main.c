#include "REG52.H"
#include "INTRINS.H"
#include "Timer0.h"
#include "key.h"
unsigned char keyNum, led_Mode;
void main(){
    timer0_Init();
    P2 = 0xFE;
    while(1){
        keyNum = key();
        if (keyNum)
        {
            if (keyNum == 1){
                led_Mode = (++led_Mode)%2;
            }
        }
        
    }
}

unsigned int T0_Count;
void timer0_Routine() interrupt 1
{
    TH0 = 0xFC;
    TL0 = 0x18;
    if ((++T0_Count) >= 500)
    {
        T0_Count = 0;
        if (led_Mode == 0) P2 = _crol_(P2, 1);
        if (led_Mode == 1) P2 = _cror_(P2, 1);
    }
}