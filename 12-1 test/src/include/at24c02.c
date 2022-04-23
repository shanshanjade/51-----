#include "at24c02.h"
#include "delay.h"
#include "i2c.h"
#include "REG52.H"

// Function:初始化AT24C02
// Description：IO口属于空闲,准备开始通信
// Input:无
// Output:无
// Return:无
// Others:无
void AT24C02_Init(void) {
    IO_Init();
}

// Function:写一个字节
// Description：向AT24C02的任意地址写入一个字节数据
// Input:写入的地址和数据
// Output:无
// Return:无
// Others:无
void At24c02_Write_Byte(unsigned char addr, unsigned char dat) {
    IIC_Start();                //启动
    IIC_Write_Byte(IIC_WADDR);  //发送从设备地址
    IIC_Ack();                  //等待从设备的响应
    IIC_Write_Byte(addr);       //发出芯片内地址
    IIC_Ack();                  //等待从设备的响应
    IIC_Write_Byte(dat);        //发送数据
    IIC_Ack();                  //等待从设备的响应
    IIC_Stop();                 //停止
    delay_ms(10);               // 写入周期
}

// Function:指定地址读一个字节
// Description：向AT24C02的指定地址读出一个字节数据
// Input:读地址
// Output:无
// Return:读到的数据
// Others:无
unsigned char At24c02_Read_Byte(unsigned char addr) {
    unsigned char dat;

    IIC_Start();
    IIC_Write_Byte(IIC_WADDR);  //发送发送从设备地址 写操作
    IIC_Ack();
    IIC_Write_Byte(addr);  //发送芯片内地址
    IIC_Ack();
    IIC_Start();
    IIC_Write_Byte(IIC_RADDR);  //发送发送从设备地址 读操作
    IIC_Ack();
    dat = IIC_Read_Byte();  //获取数据
    IIC_Stop();

    return dat;
}

// Function:任意地址写入一串数据
// Description：向AT24C02写入一串数据
// Input:写地址,写数据,数据长度
// Output:无
// Return:无
// Others:无
void At24c02_Serial_Write(unsigned char Writeaddr, unsigned char* Str, unsigned char Len) {
    while (Len--) {
        At24c02_Write_Byte(Writeaddr, *Str);
        Writeaddr++;
        Str++;
    }
}

// Function:指定地址读出一串数据
// Description：向AT24C02读出一串数据
// Input:读地址,读数据,数据长度
// Output:无
// Return:无
// Others:无
void At24c02_Serial_Read(unsigned char Readaddr, unsigned char* Str, unsigned char Len) {
    while (Len) {
        *Str++ = At24c02_Read_Byte(Readaddr++);
        Len--;
    }
}
