#include <iostream>
#include <string>
#include <climits>
#include <utility>
using namespace std;

bool min_window_seq(string str1, string str2, int start, int j_pos, int &end) {
  if (j_pos == str2.length()) {
    end = start-1;
    return true;
  }
    

  for (int i = start, j = j_pos; i < str1.length() && j < str2.length(); i++) {
    if (str1[i] == str2[j]) {
      if(min_window_seq(str1, str2, i+1, j+1, end)) {

        return true;
      }
      j++;
    }
    if (j == 0)
      cout << str1.substr(start, end - start + 1) << endl;                
  }
  return false;
}

int main() {
  string str1{"abcdebdde"};
  string str2{"bde"};
  int end = 0;
  cout << min_window_seq(str1, str2, 0, 0, end) << endl;
}
