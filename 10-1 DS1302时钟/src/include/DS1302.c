#include "DS1302.h"
#include "REG52.H"

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

#define DS1302_SEC 0x80     //秒数据地址
#define DS1302_MIN 0x82     //分数据地址
#define DS1302_HOUR 0x84    //时数据地址
#define DS1302_DATE 0x86    //日数据地址
#define DS1302_MON 0x88     //月数据地址
#define DS1302_DAY 0x8a     //星期数据地址
#define DS1302_YEAR 0x8c    //年数据地址
#define DS1302_CTRL 0x8e    //控制数据地址
#define DS1302_CHARGE 0x90  //涓流充电

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
    }
    RST_CLR;  //停止DS1302总线
}
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
/*------------------------------------------------
           从DS1302读出时钟数据
------------------------------------------------*/
void DS1302_Read_Time(unsigned char* buffer) {
    unsigned char i;
    buffer[1] = DS1302_Read_Byte(DS1302_YEAR);          //年
    buffer[2] = DS1302_Read_Byte(DS1302_MON);           //月
    buffer[3] = DS1302_Read_Byte(DS1302_DATE);          //日
    buffer[4] = DS1302_Read_Byte(DS1302_HOUR);          //时
    buffer[5] = DS1302_Read_Byte(DS1302_MIN);           //分
    buffer[6] = (DS1302_Read_Byte(DS1302_SEC)) & 0x7F;  //秒
    buffer[7] = DS1302_Read_Byte(DS1302_DAY);           //周

    // 将BCD码转换为整数
    for (i = 0; i < 8; i++) {  // BCD处理
        buffer[i] = buffer[i] / 16 * 10 + buffer[i] % 16;
    }
}
/*------------------------------------------------
           向DS1302写入时钟数据
------------------------------------------------*/
void DS1302_Write_Time(int year, int month, int date, int hour, int minute, int second, int day) {
    // 将整形数字转换为BCD码
    year = year / 10 * 16 + year % 10;
    month = month / 10 * 16 + month % 10;
    date = date / 10 * 16 + date % 10;
    hour = hour / 10 * 16 + hour % 10;
    minute = minute / 10 * 16 + minute % 10;
    second = second / 10 * 16 + second % 10;
    day = day / 10 * 16 + day % 10;
    // for (i = 0; i < 8; i++) {  // BCD处理
    //     tmp = time_buf1[i] / 10;
    //     time_buf[i] = time_buf1[i] % 10;
    //     time_buf[i] = time_buf[i] + tmp * 16;
    // }
    DS1302_Write_Byte(DS1302_CTRL, 0x00);  //关闭写保护
    DS1302_Write_Byte(DS1302_SEC, 0x80);   //暂停
    // DS1302_Write_Byte(DS1302_CHARGE,0xa9);  //涓流充电
    DS1302_Write_Byte(DS1302_YEAR, year);   //年
    DS1302_Write_Byte(DS1302_MON, month);   //月
    DS1302_Write_Byte(DS1302_DATE, date);   //日
    DS1302_Write_Byte(DS1302_HOUR, hour);   //时
    DS1302_Write_Byte(DS1302_MIN, minute);  //分
    DS1302_Write_Byte(DS1302_SEC, second);  //秒
    DS1302_Write_Byte(DS1302_DAY, day);     //周
    DS1302_Write_Byte(DS1302_CTRL, 0x80);   //打开写保护
}
