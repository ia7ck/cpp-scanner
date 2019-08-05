#include "scanner.cpp"

int main() {

  Scanner sc;
  sc.readInt<long long>(-1234567890123456789, -1234567890123456789);
  sc.readEof();

  return 0;
}
