### Test
`$ ./test.sh`

### File
- scanner.cpp
    - Scanner
    - Included by other C++ files.
- [target]_test.cpp
    - Test [target].in

### Example
space_separeted_int.in
```
3 1 4 1 5 9
```

space_separeted_int_test.cpp
```cpp
#include "scanner.cpp"
#include <cassert>
#include <vector>

int main() {

  Scanner sc;
  std::vector<int> want = {3, 1, 4, 1, 5, 9};
  for (size_t i = 0; i < want.size(); i++) {
    auto a = sc.readInt(want[i], want[i]);
    assert(a == want[i]);
    if (i + 1 < want.size()) sc.readSpace();
  }
  sc.readEof();

  return 0;
}
```
