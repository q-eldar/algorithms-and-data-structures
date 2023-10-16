#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

using Int_Matrix = vector<vector<int>>;

int edit(string str1, string str2, int m, int n, vector<vector<int>>& dp) {
  if (m == 0)
    return n;
  if (n == 0)
    return m;
  if (dp[m][n] != -1)
    return dp[m][n];
  if (str1[m - 1] == str2[n - 1])
    dp[m][n] = edit(str1, str2, m - 1, n - 1, dp);
  else
    dp[m][n] = 1 + min({
        edit(str1, str2, m, n - 1, dp),
        edit(str1, str2, m - 1, n, dp),
        edit(str1, str2, m - 1, n - 1, dp)});
  
  return dp[m][n]; 
}

int main() {
  string str1{"sunday"};
  string str2{"saturday"};
  int m = str1.length();
  int n = str2.length();
  
  Int_Matrix dp(m + 1, vector<int>(n + 1, -1));
  cout << edit(str1, str2, m, n, dp) << endl;
}
