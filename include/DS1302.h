#ifndef __DS1302_H__
#define __DS1302_H__
void DS1302_Init(void);
void DS1302_Write_Byte(unsigned char addr, unsigned char dat);
unsigned char DS1302_Read_Byte(unsigned char addr);
void DS1302_Read_Time(unsigned char* timeBuffer);
void DS1302_Write_Time(unsigned char* timeBuffer);
#endif  // !__DS1302_H__
