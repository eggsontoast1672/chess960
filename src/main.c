#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rwops.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

#include "board.h"
#include "logging.h"
#include "piece.h"
#include "position.h"

int main(void) {
  srand(time(NULL));

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    log_sdl_error("Failed to initialize SDL");
    return 1;
  }

  SDL_Window *window =
      SDL_CreateWindow("Occident", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    log_sdl_error("Failed to create window");
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    log_sdl_error("Failed to create renderer");
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  load_piece_textures(renderer);

  struct Position position = generate_valid_position();

  int window_should_close = 0;
  while (!window_should_close) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_g) {
          position = generate_valid_position();
        }
        break;
      case SDL_QUIT:
        window_should_close = 1;
        break;
      }
    }

    SDL_RenderClear(renderer);
    draw_board(renderer);
    draw_position(renderer, &position);
    SDL_RenderPresent(renderer);
  }

  free_piece_textures();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
