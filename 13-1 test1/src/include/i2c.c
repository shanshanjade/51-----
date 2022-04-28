#include "delay.h"
#include "i2c.h"
#include "REG52.H"

// Function:初始化IO口
// Description：GPIO初始化为高,通知器件总线空闲
// Input:无
// Output:无
// Return:无
// Others:无
void IO_Init() {
    IIC_SCL = 1;
    delay_us(5);
    IIC_SDA = 1;
    delay_us(5);
}

// Function:启动IIC传输
// Description：IIC_SCL为高时,IIC_SDA由高到低
// Input:无
// Output:无
// Return:无
// Others:无
void IIC_Start() {
    IIC_SDA = 1;
    IIC_SCL = 1;
    delay_us(5);
    IIC_SDA = 0;
    delay_us(5);
    IIC_SCL = 0;
}

// Function:停止IIC传输
// Description：IIC_SCL为高时,IIC_SDA由低到高
// Input:无
// Output:无
// Return:无
// Others:无
void IIC_Stop() {
    IIC_SCL = 0;
    IIC_SDA = 0;
    delay_us(5);
    IIC_SCL = 1;
    IIC_SDA = 1;
    delay_us(5);
}

// Function:产生应答信号
// Description：IIC_SCL为高时,IIC_SDA被拉低并保持一定时间的低电平
// Input:无
// Output:无
// Return:无
// Others:无
void IIC_Ack() {
    unsigned char i;

    IIC_SCL = 1;  //在scl为高电平期间等待应答
    delay_ms(2);
    while ((IIC_SDA == 1) && i < 250)  //若为应答0即退出，从机向主机发送应答信号
        i++;                           //通过i自增等待一段时间
    IIC_SCL = 0;                       //得到应答,拉低时钟
    delay_ms(2);
}

// Function:产生非应答信号
// Description：IIC_SCL为高时,IIC_SDA为高
// Input:无
// Output:无
// Return:无
// Others:无
void IIC_NAck() {
    IIC_SCL = 1;
    delay_ms(2);
    IIC_SDA = 1;
    IIC_SCL = 0;
    delay_ms(2);
}

// Function:I2C写一个字节数据，返回ACK或者NACK
// Description：从高位开始依次传输
// Input:写的字节
// Output:无
// Return:无
// Others:无
void IIC_Write_Byte(unsigned char txd) {
    unsigned char len;

    for (len = 0; len < 8; len++) {
        IIC_SCL = 0;  //只有在IIC_SCL为低电平时,才允许IIC_SDA上的数据变化
        delay_us(5);
        if (txd & 0x80)
            IIC_SDA = 1;
        else
            IIC_SDA = 0;
        delay_us(5);
        IIC_SCL = 1;  //在IIC_SCL为高电平时,不允许IIC_SDA上的数据变化，使数据稳定
        txd <<= 1;
        delay_us(10);
        IIC_SCL = 0;
        delay_us(5);
    }
    IIC_SDA = 1;  //释放总线
    IIC_SCL = 1;
    delay_us(5);
}

// Function:I2C读一个字节数据，返回ACK或者NACK
// Description：从高到低,依次接收
// Input:是否应答
// Output:无
// Return:接收的数据
// Others:无
unsigned char IIC_Read_Byte(/*unsigned char ack*/) {
    unsigned char len, dat = 0;

    IIC_SDA = 1;  //准备读取数据
    for (len = 0; len < 8; len++) {
        IIC_SCL = 0;
        delay_us(5);
        IIC_SCL = 1;  //不允许IIC_SDA变化
        delay_us(5);
        dat <<= 1;
        dat |= IIC_SDA;  //读数据
        delay_us(5);
        IIC_SCL = 0;  //允许IIC_SDA变化等待下一位数据的到来
        delay_us(5);
    }

    return dat;
}
