#ifndef __AT24C02_H__
#define __AT24C02_H__
void at24c02_WriteByte(unsigned char WordAddress, unsigned char byte);
unsigned char at24c02_ReadByte(unsigned char WordAddress);
#endif  // !__AT24C02_H__