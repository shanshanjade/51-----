#ifndef __UART_H__
#define __UART_H__
void UartInit(void);
void uart_Send_Byte(unsigned char byte);
void uart_Send_String(char*mystring);
#endif // !__UART_H__