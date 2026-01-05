#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fsm/fsm.h"
#include "utf/utf.h"


int main(int _, char *argv[]) {
    int32_t (*get_sym)(void);

    if (strcmp(argv[1], "--utf16") == 0) {
        printf("UTF-16 Mode\n");
        get_sym = is_utf16_LE() ? get_utf16_LE : get_utf16_BE;
    } else {
        printf("UTF-8 Mode\n");
        get_sym = get_utf8;
    }

    FSM *fsm = fsm_create();

    int32_t c; // codepoint
    while ((c = get_sym()) != EOF) {
        fsm_step(fsm, (uint32_t) c);
    }

    fsm_finish(fsm);
    uint64_t ans = fsm_get_bcd_count(fsm);

    printf("Количество полнотелых BCD чисел: %llu\n", ans);

    free(fsm);


    return 0;
}
