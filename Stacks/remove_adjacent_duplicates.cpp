#include <iostream>
#include <string>
#include <stack>
using std::cout;
using std::endl;
using std::string;
using std::stack;

template<typename T>
class range {
private:
  T& iterable_;
  int start_;
public:
  explicit range(T& iterable, int start) : iterable_(iterable), start_(start) {}
  auto begin() const { return std::begin(iterable_) + 1; }
  auto end() const { return std::end(iterable_); }
};

string remove_adj(string str) {
  string res{};
  res.push_back(str[0]);
  for (const auto c : range(str, 1)) {
    if ( c == res.back())
      res.pop_back();
    else
      res.push_back(c);
  }
  return res;
}

int main() {
  string str{"aabbccdd"};
  cout << remove_adj(str) << endl;
}
