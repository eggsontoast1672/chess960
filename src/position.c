#include "position.h"

#include "piece.h"
#include <stdlib.h>

int are_bishops_opposite_colors(const struct Position *position) {
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

struct Position generate_position(void) {
  struct Position position = {{
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
    enum PieceType temp = position.back_rank[i];
    position.back_rank[i] = position.back_rank[j];
    position.back_rank[j] = temp;
  }
  return position;
}

struct Position generate_valid_position(void) {
  while (1) {
    struct Position position = generate_position();
    if (is_valid_position(&position)) {
      return position;
    }
  }
}

int is_king_between_rooks(const struct Position *position) {
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

int is_valid_position(const struct Position *position) {
  // Assume that there are the correct number of each piece, e.g. two rooks, two
  // bishops, two knights, one king, one queen
  return are_bishops_opposite_colors(position) &&
         is_king_between_rooks(position);
}
