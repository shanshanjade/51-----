#include "delay.h"
// void delay(unsigned int n)  //@12.000MHz
// {
//     unsigned char i, j, k;
//     i = 2;
//     j = 239;
//     k = 0;
//     for (k = 0; k < n; k++) {
//         do {
//             while (--j)
//                 ;
//         } while (--i);
//     }
// }
void delay(unsigned int n)  //@12.000MHz
{
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 120; j++) {
            /* code */
        }
    }
}
