#include "buzzer.h"
#include "INTRINS.H"
#include "REG52.H"
#include "delay.h"
// 蜂鸣器端口
sbit buzzer = P2 ^ 5;
unsigned int i;
// 蜂鸣器私有延时函数，延时500us
void buzzerDelay500us() {
    unsigned char i;
    _nop_();
    i = 247;
    while (--i)
        ;
}
// 蜂鸣器发声，ms发声时长
void buzzerTime(unsigned int ms) {
    for (i = 0; i < ms * 2; i++) {
        buzzer = !buzzer;
        buzzerDelay500us();
    }
}