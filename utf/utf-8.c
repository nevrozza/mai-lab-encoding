//
// Created by nevrozq on 05.01.2026.
//

#include <math.h>
#include <stdio.h>

#include "utf.h"

int32_t get_utf8() {
    const int b1 = getchar();
    if (b1 == EOF) return EOF;
    else if (b1 < 128) return b1;


    int32_t c = 0; // codepoint
    uint8_t bytes_count = 0;

    if (b1 >= 0b11110000) {
        c = b1 & 0b00000111;
        bytes_count = 3;
    } else if (b1 >= 0b11100000) {
        c = b1 & 0b00001111;
        bytes_count = 2;
    } else if (b1 >= 0b11000000) {
        c = b1 & 0b00011111;
        bytes_count = 1;
    }

    // следующие байты
    for (int _ = 0; _ < bytes_count; _++) {
        const int b = getchar();
        if (b == EOF || (b & 0b11000000) != 0b10000000) return EOF;
        c = (c << 6) | (b & 0b00111111);
    }
    return c;
}
