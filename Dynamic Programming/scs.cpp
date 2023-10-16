#include <iostream>
#include <string>
#include <vector>
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

auto lcs(string str1, string str2){
  vector<vector<int>> LCS(str1.length() + 1, vector<int>(str2.length() + 1, 0));
  
  for (int i = 0; i <= str1.length(); i++) {
    for (int j = 0; j <= str2.length(); j++) {
      if (i == 0 || j == 0)
        LCS[i][j] = 0;
      else if (str1[i-1] == str2[j-1])
        LCS[i][j] = 1 + LCS[i-1][j-1];
      else
        LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
    }
  }

  return LCS;
}

string scs(string str1, string str2) {
  auto lcs_table = lcs(str1, str2);

  // print(lcs_table);
  
  int lcs_size = lcs_table[str1.length()][str2.length()];
  string ans;
  ans.resize(lcs_size);  
  
  int i = 0;
  int j = 0;
  for (i = str1.size(), j = str2.size(); i > 0 && j > 0;) {
    if (str1[i-1] == str2[j-1]) {
      ans += str1[i-1];
      i--;
      j--;
    } else if (lcs_table[i-1][j] > lcs_table[i][j-1]) {
      ans += str1[i-1];
      i--;
    } else {
      ans += str2[j-1];
      j--;
    }
  }

  
  while (i--)
    ans += str1[i];
  while (j--)
    ans += str2[j];

  reverse(ans.begin(), ans.end());
  return ans;
}
int main() {
  string str1{"abac"};
  string str2{"cab"};

  cout << scs(str1, str2) << endl;
}
