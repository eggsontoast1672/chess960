#include "asset.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL_image.h>

#include "logging.h"

#define ASSET_DIR "/home/paul/.local/share/chess960"
#define MAX_PATH 256

static char *get_asset_path(const char *filename) {
  char *path = calloc(MAX_PATH, sizeof(char));
  if (path == NULL) {
    log_error("Failed to allocate %d bytes of memory", MAX_PATH);
    exit(1);
  }
  snprintf(path, MAX_PATH, ASSET_DIR "/%s", filename);
  return path;
}

SDL_Texture *load_asset(SDL_Renderer *renderer, const char *filename) {
  char *path = get_asset_path(filename);
  SDL_Texture *texture = IMG_LoadTexture(renderer, path);
  if (texture == NULL) {
    log_sdl_error("Failed to load texture '%s'", filename);
    exit(1);
  }
  free(path);
  return texture;
}
