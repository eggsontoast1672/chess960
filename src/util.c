#include "util.h"

#include <stdlib.h>

#include "logging.h"

void *chess_allocate(size_t members, size_t size) {
  void *pointer = calloc(members, size);
  if (pointer == NULL) {
    size_t bytes = members * size;
    log_error("Failed to allocate %d bytes of memory", bytes);
    exit(1);
  }
  return pointer;
}
