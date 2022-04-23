#ifndef _I2C_H
#define _I2C_H

#include "REG52.H"

/*IIC管脚定义*/
sbit IIC_SDA = P3 ^ 0;
sbit IIC_SCL = P3 ^ 1;

void IO_Init();
void IIC_Start();
void IIC_Stop();
void IIC_Ack();
void IIC_NAck();
void IIC_Write_Byte(unsigned char txd);
unsigned char IIC_Read_Byte();

#endif
