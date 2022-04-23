#include "REG52.H"
#include "Timer0.h"
#include "delay.h"

sbit buzzer = P2 ^ 5;
#define SPEED 500
enum { O = 0,
       L1,
       L1_,
       L2,
       L2_,
       L3,
       L4,
       L4_,
       L5,
       L5_,
       L6,
       L6_,
       L7,
       M1,
       M1_,
       M2,
       M2_,
       M3,
       M4,
       M4_,
       M5,
       M5_,
       M6,
       M6_,
       M7,
       H1,
       H1_,
       H2,
       H2_,
       H3,
       H4,
       H4_,
       H5,
       H5_,
       H6,
       H6_,
       H7
};
unsigned int freqTable[] = {
    0,
    63628, 63731, 63835, 63928, 64021, 64103, 64185, 64260, 64331, 64400, 64463, 64528,
    64580, 64633, 64684, 64732, 64777, 64820, 64860, 64898, 64934, 64968, 65000, 65030,
    65058, 65085, 65110, 65134, 65157, 65178, 65198, 65217, 65235, 65252, 65268, 65283};
unsigned char code music[] = {
    // 1
    O, 4,
    O, 4,
    O, 4,
    M6, 2,
    M7, 2,

    H1, 4 + 2,
    M7, 2,
    H1, 4,
    H3, 4,

    M7, 4 + 4 + 4,
    M3, 2,
    M3, 2,
    // 2
    M6, 4 + 2,
    M5, 2,
    M6, 4,
    H1, 4,

    M5, 4 + 4 + 4,
    M3, 4,

    M4, 4 + 2,
    M3, 2,
    M4, 4,
    H1, 4,
    // 3
    M3, 4 + 4,
    O, 2,
    H1, 2,
    H1, 2,
    H1, 2,

    M7, 4 + 2,
    M4_, 2,
    M4_, 4,
    M7, 4,

    M7, 4 + 4,
    O, 4,
    M6, 2,
    M7, 2,
    // 4
    H1, 4 + 2,
    M7, 2,
    H1, 4,
    H3, 4,

    M7, 4 + 4 + 4,
    M3, 2,
    M3, 2,

    M6, 4 + 2,
    M5, 2,
    M6, 4,
    H1, 4,
    // 5
    M5, 4 + 4 + 4,
    M2, 2,
    M3, 2,

    M4, 4,
    H1, 2,
    M7, 2 + 2,
    H1, 2 + 4,

    H2, 2,
    H2, 2,
    H3, 2,
    H1, 2 + 8,
    // 6
    H1, 2,
    M7, 2,
    M6, 2,
    M6, 2,
    M7, 4,
    M5_, 4,

    M6, 4 + 4 + 4,
    H1, 2,
    H2, 2,

    H3, 4 + 2,
    H2, 2,
    H3, 4,
    H5, 4,
    //  7
    H2, 4 + 4 + 4,
    M5, 2,
    M5, 2,

    H1, 4 + 2,
    M7, 2,
    H1, 4,
    H3, 4,

    H3, 4 + 4 + 4 + 4,
            // 8
    M6, 2,
    M7, 2,
    H1, 4,
    M7, 4,
    H2, 2,
    H2, 2,

    H1, 4 + 2,
    M5, 2 + 6,

    H4, 4,
    H3, 4,
    H2, 4,
    H1, 4,
    // 9
    H3, 4 + 4 + 4,
    H3, 4,

    H6, 4 + 4,
    H5, 4,
    H5, 4,

    H3, 2,
    H2, 2,
    H1, 4 + 4,
    O, 2,
    H1, 2,
    // 10
    H2, 4,
    H1, 2,
    H2, 2,
    H2, 4,
    H5, 4,

    H3, 4 + 4 + 4,
    H3, 4,

    H6, 4 + 4,
    H5, 4 + 4,
    // 11
    H3, 2,
    H2, 2,
    H1, 4 + 4,
    O, 2,
    H1, 2,

    H2, 4,
    H1, 2,
    H2, 2 + 4,
    M7, 4,

    M6, 4 + 4 + 4,

    0xFF

};
unsigned char code music2[] = {
    M5, 2,
    M5, 2,
    M5, 2,
    M5, 2,
    M3, 2,
    M4, 2,

    M5, 6,
    M7, 6,

    M6, 2,
    M6, 2,
    M6, 2,
    M6, 2,
    M4, 2,
    M6, 2,

    M5, 6+6,

    M5, 2,
    M5, 2,
    M5, 2,
    M5, 2,
    M7, 2,
    M6, 2,

    M5, 6,
    M4, 6,

    M4, 2,
    M4, 2,
    M4, 2,
    M4, 2,
    M3, 2,
    M2, 2,

    M1, 6+6,

    H1, 2,
    H1, 2,
    H1, 2,
    H1, 2,
    M5, 2,
    M6, 2,

    H1, 4,
    H1, 2,
    H3, 6,

    H2, 2,
    H2, 2,
    H2, 2,
    H2, 2,
    H1, 2,
    M7, 2,

    M6, 4+4,

    M7, 2,
    M7, 2,
    M7, 2,
    M7, 2,
    M7, 2,
    H1, 2,

    H2, 6,
    M5, 6,

    M7, 2,
    M7, 2,
    H1, 2,
    H2, 2,
    H1, 2,
    M7, 2,

    H1, 6+6,
    0xFF
};

unsigned char *tape[] = {music, music2}; 


unsigned char freqSelect, musicSelect, tapeSelect;
void main() {
    timer0_Init();
    while (1) {
        if (tape[tapeSelect][musicSelect] != 0xFF) {
            freqSelect = tape[tapeSelect][musicSelect];
            musicSelect++;
            delay(SPEED / 4 * tape[tapeSelect][musicSelect]);
            musicSelect++;
            TR0 = 0;
            delay(5);
            TR0 = 1;
        } else {
            musicSelect = 0; freqSelect = 0;
            tapeSelect = ++tapeSelect % 2;
            // TR0 = 0;
            // while (1)
            //     ;
        }
    }
}
void Timer0_Routine() interrupt 1 {
    if (freqTable[freqSelect]) {
        TL0 = freqTable[freqSelect] % 256;
        TH0 = freqTable[freqSelect] / 256;
        buzzer = !buzzer;
    }
}