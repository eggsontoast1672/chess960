#pragma once

#include "piece.h"

typedef struct __position {
  PieceType back_rank[8];
} Position;

Position generate_position(void);
Position generate_valid_position(void);

int are_bishops_opposite_colors(const Position *position);
int is_king_between_rooks(const Position *position);
int is_valid_position(const Position *position);

void draw_position(SDL_Renderer *renderer, const Position *position);
void draw_black_pieces(SDL_Renderer *renderer, const Position *position);
void draw_white_pieces(SDL_Renderer *renderer, const Position *position);
