#include "REG52.H"
#include "delay.h"
#include "uart.h"
#include "LCD1602.h"
char buffer[20]= {'\0'};
char mychar[] = "我是中国人, 我爱中国";
void main() {
    LCD_Init();
    UartInit();
    while (1) {
        
        // uart_Send_String(mychar);
        // delay(1000);
    }
}
void uart_Routine() interrupt 4 {
    static int i;
    ES = 0;
    buffer[i++] = SBUF;
    if (SBUF == '\r')
    {
        i = 0;
        LCD_ShowString(1,1,buffer);
    }
    RI = 0;
    ES = 1;
}


// void uart_Routine() interrupt 4 {
//     if (RI == 1)
//     {
//         temp = SBUF;
//         RI = 0;
//     }
// }