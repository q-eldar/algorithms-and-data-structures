// good explanation : https://www.youtube.com/watch?v=f2ic2Rsc9pU
// Stanford c++ : https://youtu.be/uFJhEPrbycQ?si=pNisTz1CmnEMARZo&t=2492
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void permutations(string str, int j) {
  if (j >= str.length()) {
    cout << str << endl;
    return;
  }
  for (int i = j; i < str.length(); i++) {
    swap(str[i], str[j]);
    permutations(str, j+1);
    swap(str[i], str[j]);
  }
}

int main() {
  string str{"abc"};
  permutations(str, 0);
}
// abc
// acb
// bac
// cba

