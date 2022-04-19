#ifndef __DS1302_H__
#define __DS1302_H__
void DS1302_Init(void);
void DS1302_Write_Byte(unsigned char addr, unsigned char dat);
unsigned char DS1302_Read_Byte(unsigned char addr);
void DS1302_Read_Time(unsigned char* buffer);
void DS1302_Write_Time(int year, int month, int date, int hour, int minute, int second, int day);
#endif  // !__DS1302_H__
