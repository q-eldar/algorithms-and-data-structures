// https://leetcode.com/problems/decode-ways/
#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int decode(string str, int i) {
  if (i == str.length())
    return 1;
  
  if (str[i] == '0')
    return 0;
  
  int res = decode(str, i+1);
  
  if (i+1 < str.size() && stoi(str.substr(i, i+2)) <= 26)
    res = 1 + decode(str, i+2);
  
  return res;
}

int main() {
  string str{"12"};
  cout << decode(str, 0) << endl;
}
