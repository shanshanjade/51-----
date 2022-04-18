#include "REG52.H"
#include "DS1302.h"
sbit DS1302_SCLK = P3 ^ 6;
sbit DS1302_IO   = P3 ^ 4;
sbit DS1302_CE   = P3 ^ 5;

void DS302_Init() {
    DS1302_CE = 0;
    DS1302_SCLK = 0;
}
void DS1302_WriteByte(unsigned char mycommand, unsigned char mydata) {
    unsigned char i,j;
    DS1302_CE = 1;
    for (i = 0; i < 8; i++) {
        DS1302_IO = mycommand & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    for (j = 0; j < 8; j++) {
        DS1302_IO = mydata & (0x01 << j);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    DS1302_CE = 0;
}
unsigned char DS1302_ReadByte(unsigned char mycommand) {
    unsigned char i,j, mydata = 0x00;
    DS1302_CE = 1;
    for (i = 0; i < 8; i++) {
        DS1302_IO = mycommand & (0x01 << i);
        DS1302_SCLK = 0;
        DS1302_SCLK = 1;
    }
    for ( j = 0; j < 8; j++)
    {
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
        if (DS1302_IO)
            mydata |= (0x01<<j);
    }
    DS1302_CE = 1;
    return mydata;
}