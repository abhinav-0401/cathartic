#pragma once

#include "common.h"

#define GROW_CAPACITY(capacity) \
    (capacity < 8 ? 8 : (capacity * 2))

#define GROW_ARRAY(type, code, old_capacity, new_capacity) \
    (type*)reallocate(code, sizeof(type) * old_capacity, sizeof(type) * new_capacity)

#define FREE_ARRAY(type, pointer, old_count) \
    reallocate(pointer, sizeof(type) * old_count, 0)

void* reallocate(void* pointer, size_t old_size, size_t new_size);