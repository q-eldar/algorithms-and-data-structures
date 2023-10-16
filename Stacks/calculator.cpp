#include <iostream>
#include <string>
#include <stack>
using std::cout;
using std::endl;
using std::string;
using std::stack;

int eval(string expr) {
  stack<int> S;
  int current_num = 0;
  int preliminary_res = 0;
  
  for (const char token : expr) {
    switch(token) {
    case '(': { S.push(current_num); break; }
    case ')': {
      break;}
    case '+': {
      preliminary_res += current_number;
      current_number = 0;
      break; }
    case '-': {
      preliminary_res += -1 * current_number;
      current_number = 0;
      break; }
    case '0' ... '9': {
      curent_number += current_number * 10 + (int(token) - 48);
      break;}
    }
  }

  return -1;
}

int main() {
  string expr{"(8+100)"};
  cout << eval(expr) << endl;
}
