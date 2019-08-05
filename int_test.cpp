#include "scanner.cpp"
#include <cassert>

int main() {

  Scanner sc;
  auto n = sc.readInt<int>(-1234567890, -1234567890);
  assert(n == -1234567890);
  sc.readEof();

  return 0;
}
