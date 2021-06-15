#include "aiPlayer.h"

AIPlayer::AIPlayer() {}

AIPlayer::~AIPlayer() {}

void AIPlayer::makeMove(Board *b) {
  auto m = b->getEmpty();
  b->move(m.at(0).first, m.at(0).second);
}

int AIPlayer::tryMove(bool aiMove, int row, int column, Board b) {}
