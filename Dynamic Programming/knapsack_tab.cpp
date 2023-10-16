#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> weights, vector<int> values, int W) {
  vector<vector<int>> table(weights.size() + 1, vector<int>(W + 1, 0));

  for (int i = 0; i <= weights.size(); i++) {
    for (int w = 0; w <= W; w++) {
      // initialize the table with 0 when either the row or column is 0
      if (i == 0 || w == 0)
        table[i][w] = 0;
      // take optimal items for capacity with w
      else if (weights[i-1] <= w)
        table[i][w] = max(values[i-1] + table[i-1][w-weights[i-1]], table[i-1][w]);
      // dont include item if the exceeds the current capacity w
      else
        table[i][w] = table[i-1][w];
    }
  }
  return table[weights.size()][W];
}

int main() {
  vector<int> weights{2,3,4,5};
  vector<int> values{1,2,5,6};
  int W = 8;

  cout << knapsack(weights, values, W) << endl;
}
