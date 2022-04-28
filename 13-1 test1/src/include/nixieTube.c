#include "REG52.H"
#include "nixieTube.h"
#include "delay.h"
unsigned char nixie_buffer[9] = {2,10,10,10,10,10,10,10,10};
unsigned char nixieTubeTable[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x40};
void nixie_setBuffer(unsigned char location, unsigned char num){
    nixie_buffer[location] = num;
}

void nixie_scan(unsigned char pos,unsigned char num){
    P0 = 0x00;
    switch (pos){
        case 1:P24 = 1;P23 = 1;P22 = 1; break;
        case 2:P24 = 1;P23 = 1;P22 = 0; break;
        case 3:P24 = 1;P23 = 0;P22 = 1; break;
        case 4:P24 = 1;P23 = 0;P22 = 0; break;
        case 5:P24 = 0;P23 = 1;P22 = 1; break;
        case 6:P24 = 0;P23 = 1;P22 = 0; break;
        case 7:P24 = 0;P23 = 0;P22 = 1; break;
        case 8:P24 = 0;P23 = 0;P22 = 0; break;
        default:break;
    }
    P0 = nixieTubeTable[num];   
}

void nixie_loop(){
    static unsigned char i;
    nixie_scan(i, nixie_buffer[i]);
    if(++i >= 9)
        i = 1;
}