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
    if (rows[row][column] == ' ') {
      if (pTurn == Turn::X) {
        rows[row][column] = 'x';
        numX++;
        pTurn = Turn::O;
      } else {
        rows[row][column] = 'o';
        numO++;
        pTurn = Turn::X;
      }
    }
  }
}

bool Board::checkWin() {
  if (numX < 3 && numO < 3) {
    return false;
  }
  // check rows
  for (int i = 0; i < 3; i++) {
    if (rows[i][0] == rows[i][1] && rows[i][1] == rows[i][2] &&
        rows[i][2] != ' ') {
      winner = rows[i][0];
      return true;
    }
  }

  // check columns
  for (int i = 0; i < 3; i++) {
    if (rows[0][i] == rows[1][i] && rows[1][i] == rows[2][i] &&
        rows[2][i] != ' ') {
      winner = rows[0][i];
      return true;
    }
  }

  // check diagonal
  if (rows[0][0] == rows[1][1] && rows[1][1] == rows[2][2] &&
      rows[1][1] != ' ') {
    winner = rows[1][1];
    return true;
  }
  if (rows[0][2] == rows[1][1] && rows[1][1] == rows[2][0] &&
      rows[1][1] != ' ') {
    winner = rows[1][1];
    return true;
  }

  // check if there is no winner
  if (numX == 5 && numO == 4) {
    winner = 'N';
    return true;
  }
  return false;
}

void Board::print() {
  rows[0].print();
  std::cout << "---------" << std::endl;
  rows[1].print();
  std::cout << "---------" << std::endl;
  rows[2].print();
  std::cout << std::endl << std::endl;
}

Turn Board::getTurn() { return pTurn; }

std::vector<std::pair<int, int>> Board::getEmpty() {
  std::vector<std::pair<int, int>> ret;
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (rows[x][y] == ' ') {
        ret.push_back(std::make_pair(x, y));
      }
    }
  }
  return ret;
}

char Board::getWinner() { return winner; }
