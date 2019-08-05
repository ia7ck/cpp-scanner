#include "scanner.cpp"
#include <cassert>

int main() {

  Scanner sc;
  sc.readInt<int>(-1234567890, -1234567890);
  sc.readEof();

  return 0;
}
