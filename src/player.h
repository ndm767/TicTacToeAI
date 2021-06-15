#pragma once

#include "board.h"

class Player {
public:
  Player();
  ~Player();
  void getMove(Board *b);
};
