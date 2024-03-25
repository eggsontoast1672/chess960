#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rwops.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

#include "piece.h"

const float SCREEN_WIDTH = 800.0f;
const float SCREEN_HEIGHT = 800.0f;

const float CELL_WIDTH = SCREEN_WIDTH / 8.0f;
const float CELL_HEIGHT = SCREEN_HEIGHT / 8.0f;

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

int main(void) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Failed to initialize SDL\n");
    return 1;
  }

  SDL_Window *window =
      SDL_CreateWindow("Occident", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    fprintf(stderr, "Failed to create window\n");
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer == NULL) {
    fprintf(stderr, "Failed to create renderer\n");
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  load_piece_textures(renderer);

  int window_should_close = 0;
  while (!window_should_close) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        window_should_close = 1;
      }
    }

    SDL_RenderClear(renderer);
    draw_board(renderer);
    draw_piece(renderer, white_king);
    SDL_RenderPresent(renderer);
  }

  free_piece_textures();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
