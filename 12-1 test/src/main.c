#include "LCD1602.h"
#include "REG52.H"
#include "at24c02.h"
#include "delay.h"
#include "i2c.h"
#include "STDIO.H"



int a = 8629;

char putchar(unsigned char c){
    static int x = 1;
    if (c == '\n') {x = 1; return;} 
    LCD_ShowChar(1, x++,c);
    return c;
}

void main() {
    LCD_Init();
    printf("hello\nworld!");
    while (1) {
        a = a+11;
        printf("Temp:%d              \n", a);
        delay_ms(1000);
    }
}
