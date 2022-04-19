#ifndef __DS1302_H__
#define __DS1302_H__
<<<<<<< HEAD
void DS1302_Init(void);
void DS1302_Write_Byte(unsigned char addr, unsigned char dat);
unsigned char DS1302_Read_Byte(unsigned char addr);
void DS1302_Read_Time(void);
void DS1302_Write_Time(void);
=======
void DS302_Init();
void DS1302_WriteByte(unsigned char mycommand, unsigned char mydata) ;
unsigned char DS1302_ReadByte(unsigned char mycommand);
>>>>>>> 4eec1c20e38af43251e5f6607565e8f5bbfe3471
#endif  // !__DS1302_H__
