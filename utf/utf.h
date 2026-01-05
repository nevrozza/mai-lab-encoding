//
// Created by nevrozq on 05.01.2026.
//

#ifndef UTF_H
#define UTF_H
#include <stdbool.h>
#include <stdint.h>


int32_t get_utf8();

bool is_utf16_LE();

int32_t get_utf16(bool is_LE);


// wrappers для передачи функции с "переданным" параметром в main
int32_t get_utf16_LE();
int32_t get_utf16_BE();

#endif //UTF_H
