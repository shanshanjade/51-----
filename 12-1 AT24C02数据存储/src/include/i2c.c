#include "i2c.h"
#include "REG52.H"

sbit I2C_SCL = P2 ^ 1;
sbit I2C_SDA = P2 ^ 0;
// i2c 开始
void I2C_Start() {
    I2C_SDA = 1;
    I2C_SCL = 1;
    I2C_SDA = 0;
    I2C_SCL = 0;
}
// i2c 停止
void I2C_Stop() {
    I2C_SCL = 0;
    I2C_SDA = 0;
    I2C_SCL = 1;
    I2C_SDA = 1;
}
// i2c 发送一个字节
void I2C_SendByte(unsigned char byte) {
    unsigned char i;
    for (i = 0; i < 8; i++) {
        I2C_SDA = byte & (0x80 >> i);
        I2C_SCL = 1;
        I2C_SCL = 0;
    }
}
// i2c 接收一个字节 返回接收到的一个字节数据
unsigned char I2C_ReceiveByte() {
    unsigned char i, Byte;
    I2C_SDA = 1;
    for (i = 0; i < 8; i++) {
        I2C_SCL = 1;
        if (I2C_SDA)
            Byte |= (0x80 >> i);
        I2C_SCL = 0;
    }
    return Byte;
}
// i2c 发送应答 参数 AckBit ： 0为应答，1为非应答
void I2C_SendAck(unsigned char AckBit) {
    I2C_SDA = AckBit;
    I2C_SCL = 1;
    I2C_SCL = 0;
}
// i2c 接收应答 返回值接收到的应答位，0为应答， 1为非应答
unsigned char I2C_ReceiveAck() {
    unsigned char AckBit;
    I2C_SDA = 1;
    I2C_SCL = 1;
    AckBit = I2C_SDA;
    I2C_SCL = 0;
    return AckBit;
}