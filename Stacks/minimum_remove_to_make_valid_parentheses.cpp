#include <iostream>
#include <string>
#include <stack>
#include <utility>
using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::pair;

string make_valid(string str) {
  stack<pair<char, int>> invalid;
  string res = str;
  
  for (int i = 0; i < str.size(); i++) {
    char val = str[i];
    if (!invalid.empty() && invalid.top().first == '(' && val == ')')
      invalid.pop();
    else if (val == '(' || val == ')')
      invalid.push({val, i});
  }

  while (!invalid.empty()) {
    int index = invalid.top().second;
    res[index] = '\0';
    invalid.pop();
  }
  return res;
}

int main() {
  string str{")((ab)c))(ac(op)t(())("};
  cout << make_valid(str) << endl;

}
