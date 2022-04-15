#include "REG52.h"
#include "LCD1602.h"
#include "delay.h"
#include "matrixKey.h"
unsigned  char keyNum = 0;
void main() {
    LCD_Init();
    LCD_ShowString(1, 1, "Matrix Key:");
    while (1) {
        keyNum = MatrixKey();
        if (keyNum)
        {
            LCD_ShowNum(2,1,keyNum,2);
        }
    }
}