#include "piece.h"

#include <assert.h>
#include <stdio.h>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

struct Piece black_bishop = {PIECE_COLOR_BLACK, PIECE_TYPE_BISHOP};
struct Piece black_king = {PIECE_COLOR_BLACK, PIECE_TYPE_KING};
struct Piece black_knight = {PIECE_COLOR_BLACK, PIECE_TYPE_KNIGHT};
struct Piece black_pawn = {PIECE_COLOR_BLACK, PIECE_TYPE_PAWN};
struct Piece black_queen = {PIECE_COLOR_BLACK, PIECE_TYPE_QUEEN};
struct Piece black_rook = {PIECE_COLOR_BLACK, PIECE_TYPE_ROOK};

struct Piece white_bishop = {PIECE_COLOR_WHITE, PIECE_TYPE_BISHOP};
struct Piece white_king = {PIECE_COLOR_WHITE, PIECE_TYPE_KING};
struct Piece white_knight = {PIECE_COLOR_WHITE, PIECE_TYPE_KNIGHT};
struct Piece white_pawn = {PIECE_COLOR_WHITE, PIECE_TYPE_PAWN};
struct Piece white_queen = {PIECE_COLOR_WHITE, PIECE_TYPE_QUEEN};
struct Piece white_rook = {PIECE_COLOR_WHITE, PIECE_TYPE_ROOK};

static SDL_Texture *piece_textures[PIECE_COLOR_COUNT][PIECE_TYPE_COUNT];

void draw_piece(SDL_Renderer *renderer, struct Piece piece) {
  SDL_RenderCopy(renderer, piece_textures[piece.color][piece.type], NULL, NULL);
}

void free_piece_textures(void) {
  for (enum PieceColor color = 0; color < PIECE_COLOR_COUNT; ++color) {
    for (enum PieceType type = 0; type < PIECE_TYPE_COUNT; ++type) {
      if (piece_textures[color][type] != NULL) {
        SDL_DestroyTexture(piece_textures[color][type]);
      }
    }
  }
}

int load_piece_textures(SDL_Renderer *renderer) {
  for (enum PieceColor color = 0; color < PIECE_COLOR_COUNT; ++color) {
    for (enum PieceType type = 0; type < PIECE_TYPE_COUNT; ++type) {
      char file[32];
      const char *color_string = piece_color_to_string(color);
      const char *type_string = piece_type_to_string(type);
      sprintf(file, "../assets/%s-%s.png", color_string, type_string);

      piece_textures[color][type] = IMG_LoadTexture(renderer, file);
      if (piece_textures[color][type] == NULL) {
        fprintf(stderr, "[ERROR] Failed to load texture '%s'\n", file);
        fprintf(stderr, "[ERROR] %s\n", IMG_GetError());
        return -1;
      }
    }
  }
  return 0;
}

const char *piece_color_to_string(enum PieceColor color) {
  switch (color) {
  case PIECE_COLOR_BLACK:
    return "black";
  case PIECE_COLOR_WHITE:
    return "white";
  case PIECE_COLOR_COUNT:
    assert(0);
  }
}

const char *piece_type_to_string(enum PieceType type) {
  switch (type) {
  case PIECE_TYPE_BISHOP:
    return "bishop";
  case PIECE_TYPE_KING:
    return "king";
  case PIECE_TYPE_KNIGHT:
    return "knight";
  case PIECE_TYPE_PAWN:
    return "pawn";
  case PIECE_TYPE_QUEEN:
    return "queen";
  case PIECE_TYPE_ROOK:
    return "rook";
  case PIECE_TYPE_COUNT:
    assert(0);
  }
}
