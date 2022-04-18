#include "REG52.H"
sbit DS1302_SCLK = P3 ^ 6;
sbit DS1302_IO = P3 ^ 4;
sbit DS1302_CE = P3 ^ 5;

void DS302_Init() {
    DS1302_CE = 0;
    DS1302_SCLK = 0;
}
void DS1302_WriteByte(unsigned char command, unsigned char data) {
    unsigned char i,j;
    DS1302_CE = 1;
    for (i = 0; i < 8; i++) {
        DS1302_IO = command & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    for (j = 0; j < 8; j++) {
        DS1302_IO = data & (0x01 << j);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    DS1302_CE = 0;
}
unsigned char DS1302_ReadByte(unsigned char command) {
    unsigned char i,j, data = 0x00;
    DS1302_CE = 1;
    for (i = 0; i < 8; i++) {
        DS1302_IO = command & (0x01 << i);
        DS1302_SCLK = 0;
        DS1302_SCLK = 1;
    }
    for ( j = 0; j < 8; j++)
    {
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
        if (DS1302_IO)
            data |= (0x01<<j);
    }
    DS1302_CE = 1;
    return data;
}