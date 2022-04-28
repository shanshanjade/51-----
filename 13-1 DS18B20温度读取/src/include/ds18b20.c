#include "REG52.H"
#include "ds18b20.h"
#include "wire.h"
#include "LCD1602.h"

#define SKIP_ROM            0xCC
#define CONVENT_T           0x44
#define READ_SCRATCHPAD     0xBE


void ds18b20_ConvertT() {
    wire_Init();
    wire_SendByte(SKIP_ROM);
    wire_SendByte(CONVENT_T);
} 

float ds18b20_ReadT(){
    unsigned char TLSB,TMSB;
    int temp;
    float T;
    wire_Init();
    wire_SendByte(SKIP_ROM);
    wire_SendByte(READ_SCRATCHPAD);
    TLSB = wire_ReceiveByte();
    TMSB = wire_ReceiveByte();
    LCD_ShowBinNum(1,1,TMSB,8);
    LCD_ShowBinNum(1,9,TLSB,8);
    temp = (TMSB << 8) | TLSB;
    T = temp / 16.0;
    return T;
}