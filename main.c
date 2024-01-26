#include <stdint.h>
#include <stdio.h>

#define MEMORY_MAX (1 << 16) // a << b is eqv to (a x 2^b)
uint16_t memory[MEMORY_MAX];

// LC-3: 10 total regs each is 16 bit
// 8 gen purpose regs, 1 PC, 1 Cond flag reg 
enum {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, // PC reg
    R_COND,
    R_COUNT // value 10
};

uint16_t reg[R_COUNT]; // reg[10]

enum {
    OP_BR = 0,
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};

enum {
    FL_POS = 1 << 0, // pos
    FL_ZRO = 1 << 1, // 0
    FL_NEG = 1 << 2, // neg
}

int main() {
    // load args
    // setup

    reg[R_COND] = FL_ZRO; // 0 cond flag

    enum { PC_START = 0x3000 }; 
    reg[R_PC] = PC_START;

    int running = 1;
    while (running) {
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;

        switch(op)
        {
            case OP_ADD:

                break;
        }
    }
}
