#include "LCD1602.h"
#include "REG52.H"
#include "at24c02.h"
#include "delay.h"
#include "i2c.h"

//要写入到24c02的字符串数组
const unsigned char TEXT_Buffer[] = {"STC51"};
unsigned char TEXT_Buffer1[] = {"00000"};  //数组一定初始化

#define SIZE sizeof(TEXT_Buffer)

void main() {
    unsigned char dat = 48;
    unsigned char Text = 6 + '0';
    unsigned char val;

    LCD_Init();
    AT24C02_Init();
    while (1) {
        At24c02_Write_Byte(10, dat);
        delay_ms(500);
        val = At24c02_Read_Byte(10);
        LCD_ShowNum(2, 1, val, 3);
    }
}
