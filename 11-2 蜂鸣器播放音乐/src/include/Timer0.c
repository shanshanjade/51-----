#include "REG52.H"
void timer0_Init(){
    TMOD &= 0xF0; //把TMOD的低四位清零 高四位保持不变;
    TMOD |= 0x01; //把TMOD的最低位置1, 高四位保持不变;
    TF0 = 0;
    TR0 = 1;
    TH0 = 0xFC;
    TL0 = 0x18;
    ET0 = 1;
    EA  = 1;
    PT0 = 0;
}

// void Timer0_Routine() interrupt 1 {
//     static unsigned int T0Count;
//     TL0 = 0x18;
//     TH0 = 0xFC;
//     T0Count++;
//     if (T0Count == 1000)
//     {
//         T0Count = 0;
//     }
// }