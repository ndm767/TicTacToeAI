#pragma once

class Row {
private:
  char pos[3];

public:
  Row();
  ~Row();
  void print();
  char &operator[](int i);
};
