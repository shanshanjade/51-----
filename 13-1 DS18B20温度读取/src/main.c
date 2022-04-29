#include "REG52.H"
#include "delay.h"
#include "LCD1602.h"

#include "ds18b20.h"
#include "wire.h"
#include "STDIO.H"

float T;

char putchar(unsigned char c) {
    static int x = 1;
    if (c == '\n') {x = 1; return c;} 
    LCD_ShowChar(1, x++,c);
    return c;
}

void main(){
    LCD_Init();
    while (1){
        ds18b20_ConvertT();
        T = ds18b20_ReadT();
        printf("%f\n", T);
        delay_ms(500);
    }
}