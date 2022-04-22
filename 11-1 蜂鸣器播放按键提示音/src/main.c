#include "LCD1602.h"
#include "REG52.H"
#include "delay.h"
#include "key.h"
#include "buzzer.h"
unsigned char keyNum;

void main() {
    LCD_Init();
    while (1) {
        keyNum = key();
        if (keyNum) {
            buzzerTime(100);
            LCD_ShowNum(1, 1, keyNum, 2);
        }
    }
}
