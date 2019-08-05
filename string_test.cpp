#include "scanner.cpp"
#include <cassert>

int main() {

  Scanner sc;
  auto s = sc.readString();
  assert(s == "abc");
  sc.readEof();

  return 0;
}
