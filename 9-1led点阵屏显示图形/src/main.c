#include "REG52.H"
#include "delay.h"
#include "matrixLED.h"
char animation[] = {0x00, 0xFF, 0x89, 0xFF, 0x89, 0x89, 0xFF, 0x00, 0x1E, 0x22, 0x42, 0xFF, 0x42, 0x42, 0x22, 0x1E};
void main() {
    MatrixLED_Init();
    unsigned char i;

    while (1) {
        for (i = 0; i < 8; i++) {
            matrixLED_ShowColumn(i, animation[i]);
        }
    }
}
