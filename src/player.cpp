#include "player.h"

#include <iostream>
#include <string>

Player::Player() {}

Player::~Player() {}

void Player::getMove(Board *b) {
  std::string input;
  std::cin >> input;
  int mX, mY;
  if (input.length() < 2) {
    mX = 0;
    mY = 0;
  } else {
    mX = std::stoi(input.substr(0, 1));
    mY = std::stoi(input.substr(1, 1));
  }

  b->move(mX, mY);
}
