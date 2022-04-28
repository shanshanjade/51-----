#include "LCD1602.h"
#include "REG52.H"
#include "i2c.h"

#define AT24C02_ADDRESS 0xA0
void at24c02_WriteByte(unsigned char WordAddress, unsigned char byte) {
    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS);
    I2C_ReceiveAck();
    I2C_SendByte(WordAddress);
    I2C_ReceiveAck();
    I2C_SendByte(byte);
    I2C_ReceiveAck();
    I2C_Stop();
}

unsigned char at24c02_ReadByte(unsigned char WordAddress) {
    unsigned char byte;
    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS);
    I2C_ReceiveAck();
    I2C_SendByte(WordAddress);
    I2C_ReceiveAck();

    I2C_Start();
    I2C_SendByte(AT24C02_ADDRESS | 0x01);
    I2C_ReceiveAck();
    byte = I2C_ReceiveByte();
    I2C_ReceiveAck();
    I2C_Stop();
    return byte;
}