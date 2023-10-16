// https://leetcode.com/problems/longest-palindromic-substring/
#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int lps(string str, string p, int i, int j) {
  if (i == j) {
    p += str[i];
    cout << p << endl;    
    return 1;
  }
    
  // if (i == (j-1) && str[i] == str[j]) {
  //   p += str[i];
  //   cout << ": " << p << endl;
  //   return 2;
  // }
    
  if (str[i] == str[j]) {
    p += str[i];
    return 2 + lps(str, p, i+1, j-1);
  }
    

  return max(lps(str, p, i+1, j), lps(str, p, i, j-1));
}

int main() {
  string str{"aaa"};
  string p;
  cout << lps(str, p, 0, str.length() - 1) << endl;
}
