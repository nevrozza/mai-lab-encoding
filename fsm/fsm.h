//
// Created by nevrozq on 05.01.2026.
//

#ifndef FSM_H
#define FSM_H
#include <stdint.h>

typedef enum {
    AT_START,
    IN_BCD, // Надеемся, что BCD (если это не так, то переход в IN_WORD)
    IN_WORD
} FSMState;

typedef struct FSM FSM;

FSM* fsm_create();

void fsm_step(FSM *fsm, uint32_t codepoint);

void fsm_finish(FSM *fsm);

uint64_t fsm_get_bcd_count(const FSM *fsm);
#endif //FSM_H
