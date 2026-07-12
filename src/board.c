#include "board.h"

#include <SDL2/SDL_render.h>

float BOARD_WIDTH = 600.0f;
float BOARD_HEIGHT = 600.0f;

float CELL_WIDTH = 75.0f;
float CELL_HEIGHT = 75.0f;

float BOARD_ORIGIN_X = 0.0f;
float BOARD_ORIGIN_Y = 0.0f;

void update_board_layout(int window_width, int window_height) {
  float size =
      (float)(window_width < window_height ? window_width : window_height);
  BOARD_WIDTH = size;
  BOARD_HEIGHT = size;
  CELL_WIDTH = size / 8.0f;
  CELL_HEIGHT = size / 8.0f;
  BOARD_ORIGIN_X = ((float)window_width - size) / 2.0f;
  BOARD_ORIGIN_Y = ((float)window_height - size) / 2.0f;
}

void draw_board(SDL_Renderer *renderer) {
  for (int row = 0; row < 8; ++row) {
    for (int column = 0; column < 8; ++column) {
      if ((row + column) % 2 == 0) {
        SDL_SetRenderDrawColor(renderer, 0xf0, 0xd9, 0xb5, 0xff);
      } else {
        SDL_SetRenderDrawColor(renderer, 0xb5, 0x88, 0x63, 0xff);
      }
      SDL_Rect rect = {BOARD_ORIGIN_X + row * CELL_WIDTH,
                       BOARD_ORIGIN_Y + column * CELL_HEIGHT, CELL_WIDTH,
                       CELL_HEIGHT};
      SDL_RenderFillRect(renderer, &rect);
    }
  }
}
