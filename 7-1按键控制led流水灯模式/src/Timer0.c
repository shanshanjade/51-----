#include "REG52.H"
void timer0_Init(){
    TMOD &= 0xF0; //��TMOD�ĵ���λ���� ����λ���ֲ���;
    TMOD |= 0x01; //��TMOD�����λ��1, ����λ���ֲ���;
    TF0 = 0;
    TR0 = 1;
    TH0 = 0xFC;
    TL0 = 0x18;
    ET0 = 1;
    EA  = 1;
    PT0 = 0;
}
/*
��ʱ���жϺ���ģ��
void timer0_Routine() interrupt 1
{
    TH0 = 0xFC;
    TL0 = 0x18;
    if ((++T0_Count) >= 1000)
    {
        T0_Count = 0;
    }
}

*/