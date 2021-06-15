#pragma once

#include "board.h"

class AIPlayer {
public:
  AIPlayer();
  ~AIPlayer();
  void makeMove(Board *b);

private:
  int tryMove(bool aiMove, int row, int column, Board b);
};
