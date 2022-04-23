#include "LCD1602.h"
#include "REG52.H"
#include "i2c.h"

unsigned char tt = 0;
#define AT24C02_ADDRESS 0xA0
void at24c02_WriteByte(unsigned char WordAddress, unsigned char byte) {
    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS);
    if (!I2C_ReceiveAck())
        tt++;
    LCD_ShowNum(1, 10, tt, 3);
    I2C_SendByte(AT24C02_ADDRESS);
    if (!I2C_ReceiveAck())
        tt++;
    LCD_ShowNum(1, 10, tt, 3);
    I2C_SendByte(byte);
    if (!I2C_ReceiveAck())
        tt++;
    LCD_ShowNum(1, 10, tt, 3);
    I2C_Stop();
}

unsigned char at24c02_ReadByte(unsigned char WordAddress) {
    unsigned char byte;
    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS);
    if (!I2C_ReceiveAck())
        tt++;
    LCD_ShowNum(1, 10, tt, 3);
    I2C_SendByte(WordAddress);
    if (!I2C_ReceiveAck())
        tt++;
    LCD_ShowNum(1, 10, tt, 3);

    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS | 0x01);
    if (!I2C_ReceiveAck())
        tt++;
    LCD_ShowNum(1, 10, tt, 3);
    byte = I2C_ReceiveByte();
    // I2C_SendAck(1);
    I2C_Stop();
    return byte;
}