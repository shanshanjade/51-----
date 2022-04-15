#include "REG52.H"
#include "nixieTube.h"
#include "delay.h"

unsigned char nixieTubeTable[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void nixieTube(unsigned char pos,unsigned char num){
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
    delay(1);
    P0 = 0x00;
}