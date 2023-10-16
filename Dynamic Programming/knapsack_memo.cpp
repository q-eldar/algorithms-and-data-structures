#include <iostream>
#include <vector>
#include <iomanip>

int FindKnapsackRec(int capacity, std::vector<int> &weights, std::vector<int> &values, int n, std::vector<std::vector<int>> &dp) {
  // Base case
  if (n == 0 || capacity == 0)
    return 0;

  // If we have solved it earlier, then return the result from memory
  if (dp[n][capacity] != -1)
    return dp[n][capacity];

  // Otherwise, we solve it for the new combination and save the results in the memory
  if (weights[n - 1] <= capacity) {
    dp[n][capacity] = std::max(
                               values[n - 1] + FindKnapsackRec(capacity - weights[n - 1], weights, values, n - 1, dp),
                               FindKnapsackRec(capacity, weights, values, n - 1, dp));
    return dp[n][capacity];
  }
  dp[n][capacity] = FindKnapsackRec(capacity, weights, values, n - 1, dp);
  return dp[n][capacity];
}

int FindKnapsack(int capacity, std::vector<int> &weights, std::vector<int> &values, int n) {
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, -1));
  return FindKnapsackRec(capacity, weights, values, n, dp);
}

// Driver code
int main() {
  std::vector<std::vector<int>> weights = {{1, 2, 3, 5}, {4}, {2}, {3, 6, 10, 7, 2}, {3, 6, 10, 7, 2, 12, 15, 10, 13, 20}};
  std::vector<std::vector<int>> values = {{1, 5, 4, 8}, {2}, {3}, {12, 10, 15, 17, 13}, {12, 10, 15, 17, 13, 12, 30, 15, 18, 20}};
  std::vector<int> capacity = {6, 3, 3, 10, 20};
  std::vector<int> n = {4, 1, 1, 5, 10};

  // Let's uncomment this and check the effect of dynamic programming using memoization

  // weights.push_back({63,  55,  47,  83,  61,  82,   6,  34,   9,  38,   6,  69,  17,
  //     50,   7, 100, 101,   4,  41,  28, 119,  78,  98,  38,  75,  35,
  //      8,  10,  16,  93,  34,  23,  51,  79, 118,  86,  85, 109,  88,
  //     72,  99,  36,  21,  80,  42,  44,  62,   7,  54,   7,   6,   0,
  //     65,  25,  44,  86,  76,  18,  11,  10, 104,  17,  36,  91,  78,
  //     88,  79, 103,   1,   4,  34,  94,  73,  21,   8,   9,  79,  25,
  //    106,  76,  39,  78,   1,  92, 104,  84,  40, 100, 116,  84,  23,
  //     79, 109,  79,  71,  72, 116,  90,  79,  26});
  // values.push_back({35,  47,   8, 103,  83,  71,  11, 107,   9,  34,  41,  54,  73,
  //     72, 108, 100,  46,  27,  79,  98,  49,  63,  41, 116,  57,  86,
  //     51,  47,  88, 118,  65,   0,  64,  11,  45,  47,  36,  50, 114,
  //     90, 105,  55,  93,  12,  73,  96,  50,  27,  36,  97,  12,  21,
  //    107,  34, 106,  37,  84,  38, 110,  60,  34, 104,  92,  56,  94,
  //    109,  81,  17,  24, 106,  50,  68,  90,  73,  46,  99,   5,   5,
  //     22,  27,  58,  24,  20,  80,  37,   1,  16,  39,  26,  32,  12,
  //     47,  22,  28,  50,  95,   6, 105, 101,  20});
  // capacity.push_back(1000);
  // n.push_back(100);

  for (int i = 0; i < values.size(); ++i) {
    std::cout << i + 1 << ". We have a knapsack of capacity " << capacity[i] << " and we are given the following list of item values and weights:\n";
    std::cout << std::string(30, '-') << std::endl;
    std::cout << "Weights   |     Values\n";
    std::cout << std::string(30, '-') << std::endl;
    for (int j = 0; j < values[i].size(); ++j)
      std::cout << std::left << std::setw(10) << weights[i][j] << "|" << std::string(5, ' ') << values[i][j] << std::endl;
    int result = FindKnapsack(capacity[i], weights[i], values[i], n[i]);
    std::cout << "\nThe maximum we can earn is: " << result << std::endl;
    ;
    std::cout << std::string(100, '-') << std::endl
              << std::endl;
  }
  return 0;
}
