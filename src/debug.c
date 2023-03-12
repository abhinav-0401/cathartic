#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"

#include <stdio.h>

#include "include/debug.h"
#include "include/chunk.h"
#include "include/value.h"

void disassemble_chunk(Chunk* chunk, const char* name) {
    printf("== %s ==\n", name);

    // since instructions can have different sizes, we let disassemble_instructions increment the offset
    for (int offset = 0; offset < chunk->count;) {
        offset = disassemble_instruction(chunk, offset);
    }
}

static int simple_instruction(const char* op_name, int offset) {
    printf("%s\n", op_name);
    return offset + 1;
}

static int const_instruction(const char* op_name, Chunk* chunk, int offset) {
    uint8_t const_index = chunk->code[offset + 1];
    printf("%-16s %4d '", op_name, const_index);
    print_value(chunk->constants.values[const_index]);
    printf("'\n");
    return offset + 2;
}

int disassemble_instruction(Chunk* chunk, int offset) {
    printf("%04d ", offset);

    uint8_t instruction = chunk->code[offset];
    switch (instruction) {
        case OP_RETURN:
            return simple_instruction("OP_RETURN", offset);
        case OP_CONSTANT:
            return const_instruction("OP_CONSTANT", chunk, offset);
        default:
        printf("Unknown opcode %d\n", instruction);
        return offset + 1;
    }
}

#pragma clang diagnostic pop