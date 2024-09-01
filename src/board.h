#pragma once

#include <SDL2/SDL_render.h>

extern const float BOARD_WIDTH;
extern const float BOARD_HEIGHT;

extern const float CELL_WIDTH;
extern const float CELL_HEIGHT;

void draw_board(SDL_Renderer *renderer);
