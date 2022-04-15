#include "REG52.h"
#include "delay.h"
#include "LCD1602.h"
#include "nixieTube.h"
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;
typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int32_t;


void main() {
    LCD_Init();
    LCD_ShowString(0,1,"hello world!");
    while (1) {
        nixieTube(1,1);
        nixieTube(2,2);
        nixieTube(3,3);
        nixieTube(4,4);
        nixieTube(5,5);
        nixieTube(6,6);
        nixieTube(7,7);
        nixieTube(8,8); 
    }
}


// /*  P0  */
// sbit P07 = P0^7;
// sbit P06 = P0^6;
// sbit P05 = P0^5;
// sbit P04 = P0^4;
// sbit P03 = P0^3;
// sbit P02 = P0^2;
// sbit P01 = P0^1;
// sbit P00 = P0^0;

// /*  P1  */
// sbit P17 = P1^7;
// sbit P16 = P1^6;
// sbit P15 = P1^5;
// sbit P14 = P1^4;
// sbit P13 = P1^3;
// sbit P12 = P1^2;
// sbit P11 = P1^1;
// sbit P10 = P1^0;

// /*  P2  */
// sbit P27 = P2^7;
// sbit P26 = P2^6;
// sbit P25 = P2^5;
// sbit P24 = P2^4;
// sbit P23 = P2^3;
// sbit P22 = P2^2;
// sbit P21 = P2^1;
// sbit P20 = P2^0;

// /*  P3  */
// sbit P37 = P3^7;
// sbit P36 = P3^6;
// sbit P35 = P3^5;
// sbit P34 = P3^4;
// sbit P33 = P3^3;
// sbit P32 = P3^2;
// sbit P31 = P3^1;
// sbit P30 = P3^0;