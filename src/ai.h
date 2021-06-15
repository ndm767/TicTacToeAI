#pragma once

#include "board.h"

class AI {
public:
  AI();
  ~AI();
  void makeMove(Board *b);

private:
  int tryMove(bool aiMove, int row, int column, Board b);
};
