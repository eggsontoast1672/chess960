#pragma once

#include <SDL2/SDL_render.h>

extern float BOARD_WIDTH;
extern float BOARD_HEIGHT;

extern float CELL_WIDTH;
extern float CELL_HEIGHT;

extern float BOARD_ORIGIN_X;
extern float BOARD_ORIGIN_Y;

void update_board_layout(int window_width, int window_height);
void draw_board(SDL_Renderer *renderer);
