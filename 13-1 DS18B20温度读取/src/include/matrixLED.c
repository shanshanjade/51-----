#include "REG52.H"
#include "delay.h"

/* 74HC595引脚定义 */
sbit SER = P3 ^ 4;  //数据口
sbit SCK = P3 ^ 6;  //上升沿移位
sbit RCK = P3 ^ 5;  //上升沿锁存

#define MATRIX_LED_PORT P0

void MatrixLED_Init(){
    MATRIX_LED_PORT = 0x00;
    SCK = 0;
    RCK = 0;
}

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
void matrixLED_ShowColumn(unsigned char column, unsigned char mydata) {
    _74hc595_WriteByte(mydata);
    MATRIX_LED_PORT = ~(0x80 >> column);
    delay(1);
    MATRIX_LED_PORT = 0xFF;
}
void matrixLED_Delay(){
    
}