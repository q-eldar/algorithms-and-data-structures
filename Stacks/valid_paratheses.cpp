#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

bool check(char left, char right) {
  return (left == '(' && right == ')')
    || (left == '[' && right == ']')
    || (left == '{' && right == '}');
}

bool is_valid(string str) {
  stack<char> S;
  for (char ch : str) {
    if (!S.empty() && check(S.top(), ch)) {
      S.pop();
    } else
      S.push(ch);
  }
  return S.empty();
}

int main() {
  string str{"{}[]{}[{}])"};
  cout << is_valid(str) << endl;
}
