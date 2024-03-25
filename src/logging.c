#include "logging.h"

#include <stdarg.h>
#include <stdio.h>

#include <SDL2/SDL_error.h>

void log_sdl_error(const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  fprintf(stderr, "[ERROR] ");
  vfprintf(stderr, format, ap);
  fprintf(stderr, "\n[ERROR] %s\n", SDL_GetError());
  va_end(ap);
  return;
}
