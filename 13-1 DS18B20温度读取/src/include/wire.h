#ifndef __WIRE_H__
#define __WIRE_H__

unsigned char wire_Init();
void wire_SendBit(unsigned char _bit);
unsigned char wire_ReceiveBit();
void wire_SendByte(unsigned char byte);
unsigned char wire_ReceiveByte();
#endif // !__WIRE_H__
