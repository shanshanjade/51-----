#include "REG52.h"
#include "delay.h"
unsigned char key_keyNum;
unsigned char key(){
    unsigned char temp = 0;
    temp = key_keyNum;
    key_keyNum = 0;
    return temp;
}
unsigned char key_GetState(){
    unsigned char keyNum = 0;
    if(P31 == 0){keyNum=1;}
    if(P30 == 0){keyNum=2;}
    if(P32 == 0){keyNum=3;}
    if(P33 == 0){keyNum=4;}
    return keyNum;
}
void key_loop(){
    static unsigned char nowState, lastState;
    lastState = nowState;
    nowState = key_GetState();
    if (lastState == 1 && nowState == 0)
        key_keyNum = 1;
    if (lastState == 2 && nowState == 0)
        key_keyNum = 2;
    if (lastState == 3 && nowState == 0)
        key_keyNum = 3;
    if (lastState == 4 && nowState == 0)
        key_keyNum = 4;
}