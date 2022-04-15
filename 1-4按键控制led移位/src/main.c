#include "REG52.H"
#include "delay.h"

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int32_t;

sbit button1 = P3 ^ 0;
sbit button2 = P3 ^ 1;

void main() {
    uint8_t lednum = 0; //0-7
    P2 = 0xFE;
    while (1) {
        if (button1 == 0) {
            delay(20);
            while (button1 == 0)
                ;
            delay(20);

            lednum++;
            P2 = ~(0x01 << lednum%8);
        }
        if (button2 == 0) {
            delay(20);
            while (button2 == 0)
                ;
            delay(20);
            lednum--;
            P2 = ~(0x01 << lednum%8);
        }
    }
}
