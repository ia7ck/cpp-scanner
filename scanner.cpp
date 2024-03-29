#include <iostream>
#include <sstream>
struct Scanner {
  std::string pp(const char ch) {
    switch (ch) {
    case ' ':
      return "Space";
    case '\r':
      return "\\r";
    case '\n':
      return "\\n";
    case EOF:
      return "EOF";
    default:
      return std::string(1, ch);
    }
  }
  void readSpace() {
    auto ch = getchar();
    if (ch != ' ') {
      throw std::runtime_error(std::string("want: Space, got: ") + pp(ch));
    }
  }
  void readNewline() {
    auto ch = getchar();
    if (ch == '\r') {
      auto nxt_ch = getchar();
      if (nxt_ch != '\n') ungetc(nxt_ch, stdin);
      return;
    }
    if (ch != '\n') {
      throw std::runtime_error(std::string("want: Newline, got: ") + pp(ch));
    }
  }
  void readEof() {
    auto ch = getchar();
    if (ch != EOF) {
      throw std::runtime_error(std::string("want: EOF, got: ") + pp(ch));
    }
  }
  std::string readLine() {
    std::string ret;
    char ch;
    while (ch = getchar(), ch != '\r' and ch != '\n' and ch != EOF) {
      ret += ch;
    }
    ungetc(ch, stdin);
    return ret;
  }
  std::string readString(const size_t minLength, const size_t maxLength) {
    std::string ret;
    char ch;
    while (ch = getchar(),
           ch != ' ' and ch != '\r' and ch != '\n' and ch != EOF) {
      ret += ch;
    }
    ungetc(ch, stdin);
    if (not(minLength <= ret.size() and ret.size() <= maxLength)) {
      std::ostringstream os;
      os << "length of " << ret << " is not in [" << minLength << ", "
         << maxLength << "]";
      throw std::runtime_error(os.str());
    }
    return ret;
  }
  template <typename T>
  T readInt(const T lb, const T ub) {
    auto ch = getchar();
    if ((not isdigit(ch)) and (ch != '-')) {
      ungetc(ch, stdin);
      throw std::runtime_error(std::string("want: [0-9\\-]+, got: ") + pp(ch));
    }
    T ret = ch == '-' ? 0 : ch - '0';
    int sgn = ch == '-' ? -1 : +1;
    while (isdigit(ch = getchar())) {
      ret = ret * 10 + (ch - '0');
    }
    ungetc(ch, stdin);
    ret *= sgn;
    if (not(lb <= ret and ret <= ub)) {
      std::ostringstream os;
      os << ret << " is not in [" << lb << ", " << ub << "]";
      throw std::runtime_error(os.str());
    }
    return ret;
  }
};
