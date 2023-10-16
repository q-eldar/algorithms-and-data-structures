// https://leetcode.com/problems/coin-change/
#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int coin_change(vector<int>& coins, vector<int> &memo, int sum) {
  if (sum < 0)
    return -1;
  if (sum == 0)
    return 0;
  if (memo[sum-1] != 0)
    return memo[sum-1];
  
  int res = INT_MAX;
  for (int i = 0; i < coins.size(); i++) {
    int ans = coin_change(coins, memo, sum - coins[i]);
    if (ans >= 0 && ans < res) {
      res = 1 + ans;
    }
  }
  memo[sum-1] = (res != INT_MAX) ? res : -1;
  return memo[sum-1];
}

int main() {
  vector<int> coins{2, 5, 3, 6};
  int amount = 10;
  vector<int> memo(amount, 0);

  cout << coin_change(coins, memo, amount) << endl;
}
