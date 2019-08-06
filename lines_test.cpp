#include "scanner.cpp"
#include <cassert>

int main() {

  Scanner sc;
  auto s = sc.readLine();
  assert(s == "abc de f");
  sc.readNewline();
  auto t = sc.readLine();
  assert(t == "g hi jkl");
  sc.readEof();

  return 0;
}