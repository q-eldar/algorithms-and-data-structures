#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void print(const vector<int>& arr) {
  for (const auto& item : arr)
    cout << item << " ";
}

void print(const vector<vector<int>>& arr) {
  for (const auto& item : arr) {
    print(item);
    cout << endl;
  }
  cout << endl;
}

int edit(string str1, string str2, int i, int j) {
  if (i >= str1.length() || j >= str2.length())
    return 0;
  if (str1[i] == str2[j])
    return edit(str1, str2, i+1, j+1);

  int replace = edit(str1, str2, i+1, j+1);
  int remove = edit(str1, str2, i+1, j);
  int insert = edit(str1, str2, i, j+1);
  
  return 1 + min({insert, remove, replace}); 
}

int main() {
  string str1{"sunday"};
  string str2{"saturday"};

  cout << edit(str1, str2, 0, 0) << endl;
}
