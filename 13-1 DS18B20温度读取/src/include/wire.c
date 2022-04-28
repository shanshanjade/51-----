#include "REG52.H"
#include "wire.h"
sbit wire_DQ = P3 ^ 7;

/*****延时子程序*****/
void delay(unsigned int t){
	for(;t>0;t--);
}

// 初始化
unsigned char wire_Init(){ 
    unsigned char AckBit;
    wire_DQ = 1;
	delay(8);
    wire_DQ = 0;			//拉低总线
	delay(80);
    wire_DQ = 1;          	//释放总线
	delay(8);
    AckBit = wire_DQ;		//读取总线
	delay(4);
    return AckBit; // 返回 0 为应答， 返回 1 为非应答
}
// 发送一个字节
void wire_SendByte(unsigned char byte) {
	unsigned char i;
	for ( i = 0; i < 8; i++) {
		wire_DQ = 0;
		wire_DQ = byte & 0x01;
		delay(4);
		wire_DQ = 1;
		byte >>= 1; 
	}
	delay(4);
}
// 接收一个字节
unsigned char wire_ReceiveByte() {
	unsigned char i;
	unsigned char byte;
	for ( i = 0; i < 8; i++) {
		wire_DQ = 0;
		byte >>= 1;
		wire_DQ = 1;
		if (wire_DQ) byte |= 0x80;
		delay(4);
	}
	return byte;
}

