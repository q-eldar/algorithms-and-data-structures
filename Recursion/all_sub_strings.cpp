#include <iostream>
#include <string>

using namespace std;
/*
abc
ab
ac
a
bc
b
c
*/
void all_subseqs(string str, string& sub, int index) {
  // cout << sub << endl;
  for (int i = index; i < str.length(); i++) {
    sub.push_back(str[i]);
    all_subseqs(str, sub, i+1);
    cout << sub << endl;
    sub.pop_back();
  }
}

int main() {
  string str{"abc"};
  string sub{};
  all_subseqs(str, sub, 0);
}
