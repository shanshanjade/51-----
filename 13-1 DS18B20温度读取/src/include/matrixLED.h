#ifndef __MATRIXLED_H__
#define __MATRIXLED_H__
void MatrixLED_Init();
void _74hc595_WriteByte(unsigned char byte);
void matrixLED_ShowColumn(unsigned char column, unsigned char mydata);
#endif // !__MATRIXLED_H__