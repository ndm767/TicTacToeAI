#include "aiPlayer.h"

#include <iostream>
#include <map>

AIPlayer::AIPlayer() {}

AIPlayer::~AIPlayer() {}

void AIPlayer::makeMove(Board *b) {
  auto emptyMoves = b->getEmpty();
  std::map<std::pair<int, int>, int> moveRanking;
  for (auto m : emptyMoves) {
    moveRanking[m] = tryMove(m.first, m.second, *b);
  }

  std::pair<int, int> maxPair = emptyMoves.at(0);
  int maxNum = moveRanking[maxPair];
  for (auto [a, b] : moveRanking) {
    if (b > maxNum) {
      maxNum = b;
      maxPair = a;
    }
  }

  b->move(maxPair.first, maxPair.second);
}

int AIPlayer::tryMove(int row, int column, Board b, int depth) {
  int numSuccess = 0;

  b.move(row, column);
  if (b.checkWin()) {
    if (b.getWinner() == 'o') {
      // make sure that if there is a move that can immediately win, that move
      // is taken
      if (depth == 0)
        return 800;
      return 1;
    } else if (b.getWinner() == 'x') {
      return -1;
    } else {
      return 0;
    }
  } else {
    auto emptyMoves = b.getEmpty();
    if (emptyMoves.size() == 0) {
      return 0;
    }
    for (auto m : emptyMoves) {
      numSuccess += tryMove(m.first, m.second, b, depth + 1);
    }
  }

  return numSuccess;
}
