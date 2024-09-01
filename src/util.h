#pragma once

#include <stddef.h>

/**
 * Allocates memory on the heap. If the allocation fails, this function will log
 * an error message to stderr and exit with code 1. The total number of bytes
 * allocated will be equal to (members * size), similar to how calloc works.
 */
void *chess_allocate(size_t members, size_t size);
