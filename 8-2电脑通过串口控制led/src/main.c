#include "REG52.H"
#include "delay.h"
#include "uart.h"
#include "LCD1602.h"

unsigned char temp;
void main(){
    LCD_Init();
    UartInit();
    P2 = 0x00;
    while (1)
    {
        LCD_ShowNum(1,1,temp,3);
    }
}

void uart_Routine() interrupt 4 {
    if (RI == 1)
    {
        temp = SBUF;
        RI = 0;
    }
}