#include "LCD1602.h"
#include "REG52.h"
#include "delay.h"
#include "matrixKey.h"
unsigned char keyNum = 0;
unsigned int passWord = 0;
unsigned char count = 0;
char* aa = ""; 
struct abc
{
    unsigned char a;
    int b;
};


void main() {
    abc a;
    LCD_Init();
    LCD_ShowString(1, 1, "Pass Word :");
    while (1) {
        keyNum = MatrixKey();
        if (keyNum) {
            if (keyNum <= 10 && (++count) <= 4) {
                passWord *= 10;
                passWord += keyNum % 10;
                // LCD_ShowNum(2, 11, passWord, 4);
                LCD_ShowChar(2, 5-count, '*');
            }
            if (keyNum == 11) {
                if (passWord == 1110) {
                    LCD_ShowString(1, 13, "OK ");
                } else {
                    LCD_ShowString(1, 13, "ERR");
                }
                passWord = 0;
                count = 0;
                LCD_ShowString(2,1,"    ");
            }
        }
    }
}