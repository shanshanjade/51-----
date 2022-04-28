#include "REG52.H"
#include "delay.h"
#include "LCD1602.h"
#include "wire.h"

unsigned char Ack;

void main(){
    LCD_Init();
    LCD_ShowString(1,1, "Temperature:");
    Ack = wire_Init();
    LCD_ShowNum(2,1,Ack,3);
    while (1){
        
    }
}