#include "scanner.cpp"
#include <cassert>

int main() {

  Scanner sc;
  auto s = sc.readString(3, 3);
  assert(s == "abc");
  sc.readEof();

  return 0;
}
