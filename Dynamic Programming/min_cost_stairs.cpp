// https://leetcode.com/problems/min-cost-climbing-stairs/
#include <iostream>
#include <vector>
using namespace std;

int min_stairs(vector<int> &cost, vector<int> &dp, int i) {
  if (i <= 0)
    return 0;
  if (dp[i] != -1)
    return dp[i];
  return dp[i] = min(
                     cost[i-1] + min_stairs(cost, dp, i-1),
                     cost[i-2] + min_stairs(cost, dp, i-2));
}

int min_stairs_dp(vector<int> cost) {
  int n = cost.size();
  vector<int> dp(n + 1, -1);
  dp[0] = cost[0];
  dp[1] = cost[1];
  
  for (int i = 2; i <= n; i++) {
    dp[i] = min(dp[i-1], dp[i-2])  + cost[i];
  }

  return dp[n];
}

int main() {
  vector<int> cost{1,100,1,1,1,100,1,1,100,1};
  int n = cost.size();
  vector<int> dp(n + 1, -1);
  cout << min_stairs(cost, dp, cost.size()) << endl;
  // cout << min_stairs_dp(cost) << endl;
}
