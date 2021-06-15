#include "board.h"

#include <iostream>

Board::Board() {
  winner = ' ';
  numX = 0;
  numO = 0;
  pTurn = Turn::X;
}

Board::~Board() {}

void Board::move(int row, int column) {
  if (column < 3 && column >= 0 && row < 3 && row >= 0) {
    if (rows[column][row] == ' ') {
      if (pTurn == Turn::X) {
        rows[column][row] = 'x';
        numX++;
        pTurn = Turn::O;
      } else {
        rows[column][row] = 'o';
        numO++;
        pTurn = Turn::X;
      }
    }
  }
}

bool Board::checkWin() { return true; }

void Board::print() {
  rows[0].print();
  std::cout << "--------" << std::endl;
  rows[1].print();
  std::cout << "--------" << std::endl;
  rows[2].print();
}

Turn Board::getTurn() { return pTurn; }

std::vector<std::pair<int, int>> Board::getEmpty() {
  return std::vector<std::pair<int, int>>{std::make_pair(0, 0)};
}

char Board::getWinner() { return winner; }
