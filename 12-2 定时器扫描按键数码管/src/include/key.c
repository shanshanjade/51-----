#include "REG52.h"
#include "delay.h"
unsigned char key(){
    unsigned char keyNum = 0;
    if(P31 == 0){delay(20);while(P31 == 0);delay(20);keyNum=1;}
    if(P30 == 0){delay(20);while(P30 == 0);delay(20);keyNum=2;}
    if(P32 == 0){delay(20);while(P32 == 0);delay(20);keyNum=3;}
    if(P33 == 0){delay(20);while(P33 == 0);delay(20);keyNum=4;}
    return keyNum;
}
