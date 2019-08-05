#include "scanner.cpp"
#include <vector>

int main() {

  Scanner sc;
  std::vector<int> want = {3, 1, 4, 1, 5, 9};
  for (size_t i = 0; i < want.size(); i++) {
    sc.readInt(want[i], want[i]);
    if (i + 1 < want.size()) sc.readNewline();
  }
  sc.readEof();
  
  return 0;
}