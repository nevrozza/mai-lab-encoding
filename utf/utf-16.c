//
// Created by nevrozq on 05.01.2026.
//


#include <stdio.h>
#include "utf.h"

#define HS_START (int16_t)0xD800
#define HS_END (int16_t)0xDBFF
#define LS_START (int16_t)0xDC00
#define LS_END (int16_t)0xDFFF

bool is_utf16_LE() {
    const int b1 = getchar(), b2 = getchar();
    return b1 == 0xFF && b2 == 0xFE;
}

int16_t read16(const bool is_LE) {
    const int b1 = getchar(), b2 = getchar();
    if (b1 == EOF || b2 == EOF) return EOF;
    if (is_LE) {
        return (int16_t) (b1 | (b2 << 8));
    }
    return (int16_t) ((b1 << 8) | b2); //BE
}

int32_t get_utf16(const bool is_LE) {
    const int16_t c1 = read16(is_LE);
    if (c1 == EOF) return EOF;

    if (c1 >= HS_START && c1 <= HS_END) {
        const int16_t c2 = read16(is_LE);
        if (c2 == EOF) return EOF;
        if (c2 >= LS_START && c2 <= LS_END) {
            return 0x10000 + ((c1 - HS_START) << 10) + (c2 - LS_START);
        }
        // error?
    }
    return c1;
}

int32_t get_utf16_LE() {
    return get_utf16(true);
}

int32_t get_utf16_BE() {
    return get_utf16(false);
}
