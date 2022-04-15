#include "REG52.H"
#include "delay.h"

/* 74HC595引脚定义 */
sbit SER = P3 ^ 4;  //数据口
sbit SCK = P3 ^ 6;  //上升沿移位
sbit RCK = P3 ^ 5;  //上升沿锁存

void _74hc595_WriteByte(unsigned char byte) {
    unsigned char i;
    for (i = 0; i < 8; i++) {
        SER = byte & (0x80 >> i);
        SCK = 1;
        SCK = 0;
    }
    RCK = 1;                                                                                                                                                                                                                                                                                                                                                       
    RCK = 0;
}
void matrixLED_ShowColumn(unsigned char column, unsigned char mydata){
    _74hc595_WriteByte(mydata);
    P0 = ~ (0x80 >> column);
    delay(1);
    P0 = 0xFF;
}
void main() {
    P0 = 0x00;
    SCK = 0;
    RCK = 0;
    matrixLED_ShowColumn(7, 0xFF);
    while (1) {
        matrixLED_ShowColumn(0, 0x3C);
        matrixLED_ShowColumn(1, 0x42);
        matrixLED_ShowColumn(2, 0xA9);
        matrixLED_ShowColumn(3, 0x85);
        matrixLED_ShowColumn(4, 0x85);
        matrixLED_ShowColumn(5, 0xA9);
        matrixLED_ShowColumn(6, 0x42);
        matrixLED_ShowColumn(7, 0x3C);
    }
}
