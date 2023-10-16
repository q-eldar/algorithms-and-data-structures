#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> &weights, vector<int> &values, int W, int i) {
  if (W == 0)
    return 0;
  
  if (i >= weights.size())
    return 0;

  if (weights[i] > W)
    return knapsack(weights, values, W, i+1);
  
  int inc = knapsack(weights, values, W - weights[i], i+1) + values[i];
  int exl = knapsack(weights, values, W, i+1);

  return max(inc, exl);
}

int knapsack_tab(vector<int> &weights, vector<int> &values, int W) {
  vector<vector<int>> table(weights.size() + 1,
                            vector<int>(W + 1, 0));

  for (int i = 0; i <= weights.size(); i++) {
    for (int w = 0; w <= W; w++) {
      if (i == 0 || w == 0)
        table[i][w] = 0;
      else if (weights[i-1] <= w)
        table[i][w] = max(values[i-1] + table[i-1][w-weights[i-1]], table[i-1][w]);
      else
        table[i][w] = table[i-1][w];
    }
  }
  return table[weights.size()][W];
}

int main() {
  vector<int> weights{24, 10, 10, 7};
  vector<int> values{24, 16, 16, 11};
  int W = 26;
  // cout << knapsack(weights, values, W, 0) << endl;
  cout << knapsack_tab(weights, values, W) << endl;
}
