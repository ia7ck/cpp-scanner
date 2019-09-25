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

### Struct `Scanner` members

Method | Used In | Description
--- | --- | ---
`void readSpace(void)` | space_test.cpp |
`void readNewline(void)` | newline_test.cpp |
`void readEof(void)` | eof_test.cpp |
`std::string readLine()` | lines_test.cpp | Return single line without trailing newline.
`std::string readString(size_t minLength, size_t maxLength)` | string_test.cpp | Return space separated string.
`T readInt(T lowerBound, T upperBound)` | int_test.cpp | Usually, `T` = `int` or `long long int`
