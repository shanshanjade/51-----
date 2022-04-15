#include "REG52.h"
#include "delay.h"
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;
typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int32_t;

uint8_t nixieTubeTable[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void nixieTube(uint8_t pos,uint8_t num){
    switch (pos)
    {
    case 8:P24 = 1;P23 = 1;P22 = 1; break;
    case 7:P24 = 1;P23 = 1;P22 = 0; break;
    case 6:P24 = 1;P23 = 0;P22 = 1; break;
    case 5:P24 = 1;P23 = 0;P22 = 0; break;
    case 4:P24 = 0;P23 = 1;P22 = 1; break;
    case 3:P24 = 0;P23 = 1;P22 = 0; break;
    case 2:P24 = 0;P23 = 0;P22 = 1; break;
    case 1:P24 = 0;P23 = 0;P22 = 0; break;
    default:break;
    }
    P0 = nixieTubeTable[num];   
}

void main() {
    nixieTube(2,3);
    while (1) {
    }
}
