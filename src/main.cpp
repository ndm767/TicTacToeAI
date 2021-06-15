#include <iostream>

#include "aiPlayer.h"
#include "board.h"
#include "player.h"

int main(int argc, char *argv[]) {
  AIPlayer ai;
  Player p;
  Board b;

  while (!b.checkWin()) {
    b.print();
    if (b.getTurn() == Turn::X) {
      p.getMove(&b);
    } else {
      ai.makeMove(&b);
    }
  }

  b.print();
  char w = b.getWinner();
  if (w == 'N')
    std::cout << "Nobody wins!" << std::endl;
  else
    std::cout << w << " wins!" << std::endl;
  return 0;
}
