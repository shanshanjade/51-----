#include "REG52.H"
#include "delay.h"
#include "LCD1602.h"
#include "ds18b20.h"
#include "wire.h"
unsigned char Ack;

float T;
void main(){
    LCD_Init();
    LCD_ShowNum(1,1, wire_Init(),1);
    while (1){
        ds18b20_ConvertT();
        T = ds18b20_ReadT();
        if (T < 0) {
            LCD_ShowChar(2,1,'-');
            T = -T;
        } else if(T > 0) {
            LCD_ShowChar(2,1,'+');
        }
        LCD_ShowNum(2, 2, T, 3);
        LCD_ShowChar(2, 5, '.');
        LCD_ShowNum(2, 6, (unsigned long)(T*10000)%10000, 4);
        delay_ms(500);
    }
}