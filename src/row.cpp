#include "row.h"

#include <iostream>

Row::Row() {
  for (int i = 0; i < 3; i++)
    pos[i] = ' ';
}

Row::~Row() {}

void Row::print() {
  std::cout << pos[0] << " | " << pos[1] << " | " << pos[2] << std::endl;
}

char &Row::operator[](int i) { return pos[i]; }
