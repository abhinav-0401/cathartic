#include <stdio.h>

#include "include/common.h"
#include "include/chunk.h"
#include "include/debug.h"

int main(int argc, const char* argv[]) {
    printf("congratulations\n");

    Chunk chunk;
    init_chunk(&chunk);

    int const_index = add_const(&chunk, 1.2);
    write_chunk(&chunk, OP_CONSTANT);
    write_chunk(&chunk, const_index);
    write_chunk(&chunk, OP_RETURN);

    disassemble_chunk(&chunk, "test chunk");
    free_chunk(&chunk);

    return 0;
}