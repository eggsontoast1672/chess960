#include "position.h"

#include <stdlib.h>

#include <SDL2/SDL_render.h>

#include "board.h"
#include "piece.h"

int are_bishops_opposite_colors(const Position *position) {
  ssize_t first_bishop_index = -1;
  for (size_t i = 0; i < 8; ++i) {
    if (position->back_rank[i] != PIECE_TYPE_BISHOP) {
      continue;
    }
    if (first_bishop_index == -1) {
      first_bishop_index = i;
    } else if (first_bishop_index % 2 == i % 2) {
      return 0;
    }
  }
  return 1;
}

Position generate_position(void) {
  Position position = {{
      PIECE_TYPE_ROOK,
      PIECE_TYPE_KNIGHT,
      PIECE_TYPE_BISHOP,
      PIECE_TYPE_QUEEN,
      PIECE_TYPE_KING,
      PIECE_TYPE_BISHOP,
      PIECE_TYPE_KNIGHT,
      PIECE_TYPE_ROOK,
  }};
  for (size_t i = 7; i >= 1; --i) {
    size_t j = rand() % (i + 1);
    PieceType temp = position.back_rank[i];
    position.back_rank[i] = position.back_rank[j];
    position.back_rank[j] = temp;
  }
  return position;
}

Position generate_valid_position(void) {
  while (1) {
    Position position = generate_position();
    if (is_valid_position(&position)) {
      return position;
    }
  }
}

int is_king_between_rooks(const Position *position) {
  int found_rook = 0;
  for (size_t i = 0; i < 8; ++i) {
    switch (position->back_rank[i]) {
    case PIECE_TYPE_KING:
      return found_rook;
    case PIECE_TYPE_ROOK:
      if (found_rook) {
        return 0;
      }
      found_rook = 1;
      break;
    default:
      continue;
    }
  }
  return 1;
}

int is_valid_position(const Position *position) {
  // Assume that there are the correct number of each piece, e.g. two rooks, two
  // bishops, two knights, one king, one queen
  return are_bishops_opposite_colors(position) &&
         is_king_between_rooks(position);
}

void draw_position(SDL_Renderer *renderer, const Position *position) {
  draw_black_pieces(renderer, position);
  draw_white_pieces(renderer, position);
}

void draw_black_pieces(SDL_Renderer *renderer,
                       const Position *position) {
  SDL_Rect rect = {0, 0, CELL_WIDTH, CELL_HEIGHT};
  for (size_t i = 0; i < 8; ++i) {
    rect.x = i * CELL_WIDTH;
    rect.y = 0;
    SDL_RenderCopy(renderer,
                   piece_textures[PIECE_COLOR_BLACK][position->back_rank[i]],
                   NULL, &rect);

    rect.y = CELL_HEIGHT;
    SDL_RenderCopy(renderer, piece_textures[PIECE_COLOR_BLACK][PIECE_TYPE_PAWN],
                   NULL, &rect);
  }
}

void draw_white_pieces(SDL_Renderer *renderer,
                       const Position *position) {
  SDL_Rect rect = {0, 0, CELL_WIDTH, CELL_HEIGHT};
  for (size_t i = 0; i < 8; ++i) {
    rect.x = i * CELL_WIDTH;
    rect.y = 7 * CELL_HEIGHT;
    SDL_RenderCopy(renderer,
                   piece_textures[PIECE_COLOR_WHITE][position->back_rank[i]],
                   NULL, &rect);

    rect.y = 6 * CELL_HEIGHT;
    SDL_RenderCopy(renderer, piece_textures[PIECE_COLOR_WHITE][PIECE_TYPE_PAWN],
                   NULL, &rect);
  }
}
