#include "piece.h"

#include <assert.h>
#include <stdio.h>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

#include "asset.h"
#include "util.h"

static const char *piece_color_to_string(PieceColor color) {
  switch (color) {
  case PIECE_COLOR_BLACK:
    return "black";
  case PIECE_COLOR_WHITE:
    return "white";
  default:
    return "";
  }
}

const char *piece_type_to_string(PieceType type) {
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
  default:
    return "";
  }
}

#define ASSET_NAME_MAX 64

static char *get_asset_name(PieceColor color, PieceType type) {
  char *asset_name = chess_allocate(ASSET_NAME_MAX, sizeof(char));
  const char *color_string = piece_color_to_string(color);
  const char *type_string = piece_type_to_string(type);
  snprintf(asset_name, ASSET_NAME_MAX, "%s-%s.png", color_string, type_string);
  return asset_name;
}

SDL_Texture *piece_textures[PIECE_COLOR_COUNT][PIECE_TYPE_COUNT] = {0};

void free_piece_textures(void) {
  for (PieceColor color = 0; color < PIECE_COLOR_COUNT; ++color) {
    for (PieceType type = 0; type < PIECE_TYPE_COUNT; ++type) {
      SDL_DestroyTexture(piece_textures[color][type]);
    }
  }
}

void load_piece_textures(SDL_Renderer *renderer) {
  for (PieceColor color = 0; color < PIECE_COLOR_COUNT; ++color) {
    for (PieceType type = 0; type < PIECE_TYPE_COUNT; ++type) {
      char *asset_name = get_asset_name(color, type);
      piece_textures[color][type] = load_asset(renderer, asset_name);
    }
  }
}
