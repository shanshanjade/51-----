#include "REG52.H"
#include "delay.h"
unsigned char MatrixKey(){
    unsigned char keyNum = 0;
    P1 = 0xFF;  P13 = 0;
    if (P17 == 0) {delay(20); while (P17 == 0); delay(20); keyNum = 1;}
    if (P16 == 0) {delay(20); while (P16 == 0); delay(20); keyNum = 5;}
    if (P15 == 0) {delay(20); while (P15 == 0); delay(20); keyNum = 9;}
    if (P14 == 0) {delay(20); while (P14 == 0); delay(20); keyNum = 13;}
    P1 = 0xFF;  P12 = 0;
    if (P17 == 0) {delay(20); while (P17 == 0); delay(20); keyNum = 2;}
    if (P16 == 0) {delay(20); while (P16 == 0); delay(20); keyNum = 6;}
    if (P15 == 0) {delay(20); while (P15 == 0); delay(20); keyNum = 10;}
    if (P14 == 0) {delay(20); while (P14 == 0); delay(20); keyNum = 14;}
    P1 = 0xFF;  P11 = 0;
    if (P17 == 0) {delay(20); while (P17 == 0); delay(20); keyNum = 3;}
    if (P16 == 0) {delay(20); while (P16 == 0); delay(20); keyNum = 7;}
    if (P15 == 0) {delay(20); while (P15 == 0); delay(20); keyNum = 11;}
    if (P14 == 0) {delay(20); while (P14 == 0); delay(20); keyNum = 15;}
    P1 = 0xFF;  P10 = 0;
    if (P17 == 0) {delay(20); while (P17 == 0); delay(20); keyNum = 4;}
    if (P16 == 0) {delay(20); while (P16 == 0); delay(20); keyNum = 8;}
    if (P15 == 0) {delay(20); while (P15 == 0); delay(20); keyNum = 12;}
    if (P14 == 0) {delay(20); while (P14 == 0); delay(20); keyNum = 16;}
    
    return keyNum;
}