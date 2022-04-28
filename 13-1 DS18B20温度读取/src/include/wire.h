#ifndef __WIRE_H__
#define __WIRE_H__

unsigned char wire_Init();
void wire_SendByte(unsigned char byte);
unsigned char wire_ReceiveByte();
#endif // !__WIRE_H__
