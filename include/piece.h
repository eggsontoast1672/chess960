#pragma once

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

enum PieceColor {
  PIECE_COLOR_BLACK,
  PIECE_COLOR_WHITE,
  PIECE_COLOR_COUNT,
};

enum PieceType {
  PIECE_TYPE_BISHOP,
  PIECE_TYPE_KING,
  PIECE_TYPE_KNIGHT,
  PIECE_TYPE_PAWN,
  PIECE_TYPE_QUEEN,
  PIECE_TYPE_ROOK,
  PIECE_TYPE_COUNT,
};

struct Piece {
  enum PieceColor color;
  enum PieceType type;
};

extern struct Piece white_king;
extern struct Piece white_queen;
extern struct Piece white_bishop;
extern struct Piece white_knight;
extern struct Piece white_rook;
extern struct Piece white_pawn;

extern struct Piece black_king;
extern struct Piece black_queen;
extern struct Piece black_bishop;
extern struct Piece black_knight;
extern struct Piece black_rook;
extern struct Piece black_pawn;

void draw_piece(SDL_Renderer *renderer, struct Piece piece);
void free_piece_textures(void);
int load_piece_textures(SDL_Renderer *renderer);
const char *piece_color_to_string(enum PieceColor color);
const char *piece_type_to_string(enum PieceType type);
