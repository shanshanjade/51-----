#include "DS1302.h"
#include "REG52.H"
<<<<<<< HEAD
=======
#include "DS1302.h"
sbit DS1302_SCLK = P3 ^ 6;
sbit DS1302_IO   = P3 ^ 4;
sbit DS1302_CE   = P3 ^ 5;
>>>>>>> 4eec1c20e38af43251e5f6607565e8f5bbfe3471

sbit SCK = P3 ^ 6;  // DS1302时钟线
sbit SDA = P3 ^ 4;  // DS1302数据线
sbit RST = P3 ^ 5;  // DS1302复位线

#define RST_CLR RST = 0  //电平置低
#define RST_SET RST = 1  //电平置高

#define SDA_CLR SDA = 0  //电平置低
#define SDA_SET SDA = 1  //电平置高
#define SDA_RD SDA       //电平读取

#define SCK_CLR SCK = 0  //时钟信号
#define SCK_SET SCK = 1  //电平置高

// unsigned char time_buf1[8] = {40, 14, 2, 14, 10, 59, 50, 7};  //  -年月日时分秒周 2014-02-14 10:59:50 7周
// unsigned char time_buf[8];                                    //   -年月日时分秒周

void DS1302_Init(void);
void DS1302_Write_Byte(unsigned char addr, unsigned char dat);
unsigned char DS1302_Read_Byte(unsigned char addr);

/*------------------------------------------------
           DS1302初始化
------------------------------------------------*/
void DS1302_Init(void) {
    RST_CLR;  // RST脚置低
    SCK_CLR;  // SCK脚置低
    DS1302_Write_Byte(0x80, 0x00);
}
<<<<<<< HEAD

/*------------------------------------------------
           向DS1302写入一字节数据
------------------------------------------------*/
void DS1302_Write_Byte(unsigned char addr, unsigned char dat) {
    unsigned char i;
    RST_SET;
    addr = addr & 0xFE;  //写地址 最低位为W写，低电平
    for (i = 0; i < 8; i++) {
        if (addr & 0x01) {
            SDA_SET;
        } else {
            SDA_CLR;
        }
        SCK_SET;
        SCK_CLR;
        addr = addr >> 1;
    }

    //写入数据：dat
    for (i = 0; i < 8; i++) {
        if (dat & 0x01) {
            SDA_SET;
        } else {
            SDA_CLR;
        }
        SCK_SET;
        SCK_CLR;
        dat = dat >> 1;
=======
void DS1302_WriteByte(unsigned char mycommand, unsigned char mydata) {
    unsigned char i,j;
    DS1302_CE = 1;
    for (i = 0; i < 8; i++) {
        DS1302_IO = mycommand & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    for (j = 0; j < 8; j++) {
        DS1302_IO = mydata & (0x01 << j);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
>>>>>>> 4eec1c20e38af43251e5f6607565e8f5bbfe3471
    }
    RST_CLR;  //停止DS1302总线
}
<<<<<<< HEAD

/*------------------------------------------------
           从DS1302读出一字节数据
------------------------------------------------*/
unsigned char DS1302_Read_Byte(unsigned char addr) {
    unsigned char i;
    unsigned char temp;
    RST_SET;

    addr = addr | 0x01;  //最低RD，有效为高电平
    for (i = 0; i < 8; i++) {
        if (addr & 0x01) {
            SDA_SET;
        } else {
            SDA_CLR;
        }
        SCK_SET;
        SCK_CLR;
        addr = addr >> 1;
    }

    //输出数据：temp
    for (i = 0; i < 8; i++) {
        temp = temp >> 1;
        if (SDA_RD) {
            temp |= 0x80;
        } else {
            temp &= 0x7F;
        }
        SCK_SET;
        SCK_CLR;
    }

    RST_CLR;  //停止DS1302总线
    return temp;
}

// /*------------------------------------------------
//            从DS1302读出时钟数据
// ------------------------------------------------*/
// void DS1302_Read_Time(void) {
//     unsigned char i, tmp;
//     time_buf[1] = DS1302_Read_Byte(DS1302_YEAR);          //年
//     time_buf[2] = DS1302_Read_Byte(DS1302_MON);           //月
//     time_buf[3] = DS1302_Read_Byte(DS1302_DATE);          //日
//     time_buf[4] = DS1302_Read_Byte(DS1302_HOUR);          //时
//     time_buf[5] = DS1302_Read_Byte(DS1302_MIN);           //分
//     time_buf[6] = (DS1302_Read_Byte(DS1302_SEC)) & 0x7F;  //秒
//     time_buf[7] = DS1302_Read_Byte(DS1302_DAY);           //周

//     for (i = 0; i < 8; i++) {  // BCD处理
//         tmp = time_buf[i] / 16;
//         time_buf1[i] = time_buf[i] % 16;
//         time_buf1[i] = time_buf1[i] + tmp * 10;
//     }
// }

// /*------------------------------------------------
//            向DS1302写入时钟数据
// ------------------------------------------------*/
// void DS1302_Write_Time(void) {
//     unsigned char i, tmp;
//     for (i = 0; i < 8; i++) {  // BCD处理
//         tmp = time_buf1[i] / 10;
//         time_buf[i] = time_buf1[i] % 10;
//         time_buf[i] = time_buf[i] + tmp * 16;
//     }
//     DS1302_Write_Byte(DS1302_CTRL, 0x00);  //关闭写保护
//     DS1302_Write_Byte(DS1302_SEC, 0x80);   //暂停
//     // DS1302_Write_Byte(DS1302_CHARGE,0xa9);  //涓流充电
//     DS1302_Write_Byte(DS1302_YEAR, time_buf[1]);  //年
//     DS1302_Write_Byte(DS1302_MON, time_buf[2]);   //月
//     DS1302_Write_Byte(DS1302_DATE, time_buf[3]);  //日
//     DS1302_Write_Byte(DS1302_HOUR, time_buf[4]);  //时
//     DS1302_Write_Byte(DS1302_MIN, time_buf[5]);   //分
//     DS1302_Write_Byte(DS1302_SEC, time_buf[6]);   //秒
//     DS1302_Write_Byte(DS1302_DAY, time_buf[7]);   //周
//     DS1302_Write_Byte(DS1302_CTRL, 0x80);         //打开写保护
// }
=======
unsigned char DS1302_ReadByte(unsigned char mycommand) {
    unsigned char i,j, mydata = 0x00;
    DS1302_CE = 1;
    for (i = 0; i < 8; i++) {
        DS1302_IO = mycommand & (0x01 << i);
        DS1302_SCLK = 0;
        DS1302_SCLK = 1;
    }
    for ( j = 0; j < 8; j++)
    {
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
        if (DS1302_IO)
            mydata |= (0x01<<j);
    }
    DS1302_CE = 1;
    return mydata;
}
>>>>>>> 4eec1c20e38af43251e5f6607565e8f5bbfe3471
