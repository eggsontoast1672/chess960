#pragma once

#include "piece.h"

struct Position {
  enum PieceType back_rank[8];
};

struct Position generate_position(void);
struct Position generate_valid_position(void);

int are_bishops_opposite_colors(const struct Position *position);
int is_king_between_rooks(const struct Position *position);
int is_valid_position(const struct Position *position);

void draw_position(SDL_Renderer *renderer, const struct Position *position);
void draw_black_pieces(SDL_Renderer *renderer, const struct Position *position);
void draw_white_pieces(SDL_Renderer *renderer, const struct Position *position);
