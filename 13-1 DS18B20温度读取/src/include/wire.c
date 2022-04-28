#include "REG52.H"
#include "wire.h"
#include "delay.h"
sbit wire_DQ = P3 ^ 7;

// 初始化
unsigned char wire_Init(){ 
    unsigned char i;
    unsigned char AckBit;

    wire_DQ = 1;
    wire_DQ = 0;			//拉低总线
    i = 247; while (--i); 	//延时500us
    wire_DQ = 1;          	//释放总线
    i = 32; while (--i);  	//延时70us
    AckBit = wire_DQ;		//读取总线
    i = 247; while (--i); 	//至少500us

    return AckBit; // 返回 0 为应答， 返回 1 为非应答
}
// 发送一位
void wire_SendBit(unsigned char _bit) {
    unsigned char i;   

    wire_DQ = 0;			//拉低总线
    i = 4; while (--i);  	//延时10us
    wire_DQ = _bit;			//写入总线1位
	i = 24; while (--i); 	//延时50us
	wire_DQ = 1; 			//释放总线
}
// 接收一位
unsigned char wire_ReceiveBit()	{
	unsigned char i,_bit;
	wire_DQ = 0;			//拉低总线
	i = 2; while (--i); 	//延时5us
	wire_DQ = 1;			//拉低总线
	i = 2; while (--i); 	//延时5us
	_bit = wire_DQ;			//读取总线
	i = 24; while (--i); 	//延时50us
	return _bit;
}
// 发送一个字节
void wire_SendByte(unsigned char byte) {
	unsigned char i;
	for ( i = 0; i < 8; i++) {
		wire_SendBit(byte & (0x01 << i));
	}
}
// 接收一个字节
unsigned char wire_ReceiveByte() {
	unsigned char i;
	unsigned char byte;
	for ( i = 0; i < 8; i++) {
		if (wire_ReceiveBit()) {
			byte |= (0x01 << i);
		}
	}
	return byte;
}

