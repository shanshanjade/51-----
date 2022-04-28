#include "delay.h"
#include "REG52.H"
// Function:延时1us
// Input:延时的微秒数
// Output:无
// Return:无
// Others:无
void delay_us(unsigned char t) {
    while (t--)
        ;
}

// Function:延时1us
// Input:延时的毫秒数
// Output:无
// Return:无
// Others:无
void delay_ms(unsigned int t) {
    unsigned int x, y;
    for (x = t; x > 0; x--)
        for (y = 110; y > 0; y--)
            ;
}
