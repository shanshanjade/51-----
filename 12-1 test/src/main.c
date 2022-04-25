#include "LCD1602.h"
#include "REG52.H"
#include "at24c02.h"
#include "delay.h"
#include "i2c.h"

//要写入到24c02的字符串数组


void main() {
    unsigned char dat = 48;
    unsigned char val;

    LCD_Init();
    AT24C02_Init();
    At24c02_Write_Byte(10, dat);
    delay_ms(10);
    val = At24c02_Read_Byte(10);
    LCD_ShowNum(2, 1, val, 3);
    while (1) {
        // At24c02_Write_Byte(10, dat);
        // delay_ms(500);
        // val = At24c02_Read_Byte(10);
        // LCD_ShowNum(2, 1, val, 3);
    }
}
