// https://www.geeksforgeeks.org/coin-change-dp-7/
#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

using Int_Matrix = vector<vector<int>>;

int count_changes(vector<int>& coins, int i, int sum, Int_Matrix& memo) {
  if (i >= coins.size() || sum < 0)
    return 0;
  
  if (sum == 0)
    return memo[i][sum] = 1;
  
  if (memo[i][sum] != -1)
    return memo[i][sum];
  
  int take = count_changes(coins, i, sum-coins[i], memo);
  int no_take = count_changes(coins, i+1, sum, memo);
  memo[i][sum] = take + no_take;
  return memo[i][sum];
}

int main() {
  vector<int> coins{2, 5, 3, 6};
  int sum = 10;
  Int_Matrix memo(coins.size() + 1, vector<int>(sum + 1, -1));  
  cout << count_changes(coins, 0, sum, memo) << endl;
}
