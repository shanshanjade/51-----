#include "REG52.H"
#include "LCD1602.h"
#include "key.h"
#include "at24c02.h"
#include "delay.h"
unsigned char readData;
void main() {
    LCD_Init();
    delay(100);
    LCD_ShowString(1, 1, "at24c02");
    delay(100);
    at24c02_WriteByte(1, 1);
    delay(100);

    readData = at24c02_ReadByte(1);
    delay(100);
    LCD_ShowNum(2, 1, readData, 4);
    while (1) {
    }
}