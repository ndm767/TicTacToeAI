#pragma once

#include <utility>
#include <vector>

#include "row.h"

enum class Turn { X, O };

class Board {
private:
  char winner;
  int numX, numO;
  Row rows[3];
  Turn pTurn;

public:
  Board();
  ~Board();

  void move(int row, int column);
  bool checkWin();

  void print();

  Turn getTurn();

  std::vector<std::pair<int, int>> getEmpty();
  char getWinner();
};
