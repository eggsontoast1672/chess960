#include "board.h"

#include <SDL2/SDL_render.h>

const float BOARD_WIDTH = 600.0f;
const float BOARD_HEIGHT = 600.0f;

const float CELL_WIDTH = BOARD_WIDTH / 8.0f;
const float CELL_HEIGHT = BOARD_HEIGHT / 8.0f;

void draw_board(SDL_Renderer *renderer) {
  for (int row = 0; row < 8; ++row) {
    for (int column = 0; column < 8; ++column) {
      if ((row + column) % 2 == 0) {
        SDL_SetRenderDrawColor(renderer, 0xf0, 0xd9, 0xb5, 0xff);
      } else {
        SDL_SetRenderDrawColor(renderer, 0xb5, 0x88, 0x63, 0xff);
      }
      SDL_Rect rect = {row * CELL_WIDTH, column * CELL_HEIGHT, CELL_WIDTH,
                       CELL_HEIGHT};
      SDL_RenderFillRect(renderer, &rect);
    }
  }
}
