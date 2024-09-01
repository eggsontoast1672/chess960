#pragma once

#include <SDL2/SDL_render.h>

/**
 * Searches the asset directory for the supplied filename. If it exists, it
 * loads the filename as a PNG and returns a pointer to the texture data. If it
 * doesn't exist, it logs a message and exits with code 1.
 */
SDL_Texture *load_asset(SDL_Renderer *renderer, const char *filename);
