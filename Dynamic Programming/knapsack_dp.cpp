#include <iostream>
#include <vector>
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

int knap(vector<int>& val, vector<int>& wt, int W, int n) {
  vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      if (i == 0 || w == 0)
        dp[i][w] = 0;
      else if (wt[i-1] > w)
        dp[i][w] = dp[i-1][w];
      else
        dp[i][w] = max(val[i-1] +
                       dp[i-1][w-wt[i-1]],
                       dp[i-1][w]);
    }
  }
  print(dp);
  return dp[n][W];
}

int main() {
  vector<int> val{1, 2, 3};
  vector<int> wt{4, 5, 1};
  int W = 4;
  cout << knap(val, wt, W, val.size()) << endl;
}
