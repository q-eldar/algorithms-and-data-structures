// https://leetcode.com/problems/climbing-stairs/
#include <iostream>
#include <vector>
using namespace std;

int stairs(int n) {
  vector<int> dp(n+1, -1);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }
  return dp[n];
}

int main() {
  int n{2};
  cout  << stairs(n) << endl;
}
