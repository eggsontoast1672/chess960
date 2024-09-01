#pragma once

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

typedef enum PieceColor {
  PIECE_COLOR_BLACK,
  PIECE_COLOR_WHITE,
  PIECE_COLOR_COUNT,
} PieceColor;

typedef enum PieceType {
  PIECE_TYPE_BISHOP,
  PIECE_TYPE_KING,
  PIECE_TYPE_KNIGHT,
  PIECE_TYPE_PAWN,
  PIECE_TYPE_QUEEN,
  PIECE_TYPE_ROOK,
  PIECE_TYPE_COUNT,
} PieceType;

extern SDL_Texture *piece_textures[PIECE_COLOR_COUNT][PIECE_TYPE_COUNT];

void free_piece_textures(void);
void load_piece_textures(SDL_Renderer *renderer);
