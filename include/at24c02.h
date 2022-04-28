#ifndef _AT24C02_H
#define _AT24C02_H

#define IIC_WADDR 0XA0
#define IIC_RADDR 0XA1

void AT24C02_Init(void);

void At24c02_Write_Byte(unsigned char addr, unsigned char dat);
unsigned char At24c02_Read_Byte(unsigned char addr);

void At24c02_Serial_Write(unsigned char Writeaddr, unsigned char* Str, unsigned char Len);
void At24c02_Serial_Read(unsigned char Readaddr, unsigned char* Str, unsigned char Len);

#endif
