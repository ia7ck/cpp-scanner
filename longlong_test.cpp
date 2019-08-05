#include "scanner.cpp"
#include <cassert>

int main() {

  Scanner sc;
  auto n = sc.readInt<long long>(-1234567890123456789, -1234567890123456789);
  assert(n == -1234567890123456789);
  sc.readEof();

  return 0;
}
