#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <numeric>
using namespace std;

bool is_equal_subset_sum(vector<int> &nums, int sum, int i) {
  if (sum == 0)
    return true;
  if (i == nums.size())
    return false;
  if (sum < 0)
    return false;

  int inc = is_equal_subset_sum(nums, sum-nums[i], i+1);
  int exl = is_equal_subset_sum(nums, sum, i+1);

  return inc or exl; 
}

bool is_equal_subset_sum_memo(vector<int> &nums, vector<vector<int>> &memo,
                              int sum, int i) {
  if (sum == 0)
    return memo[i][sum] = true;
  
  if (i == nums.size())
    return memo[i][sum] = false;
  
  if (memo[i][sum] != -1)
    return memo[i][sum];
  
  if (sum < 0)
    return false;

  int inc = is_equal_subset_sum(nums, sum-nums[i], i+1);
  int exl = is_equal_subset_sum(nums, sum, i+1);

  memo[i][sum] = inc or exl;
  return memo[i][sum];
}

void print_table(vector<vector<bool>> &table) {
  for (const auto& row : table) {
    for (const auto& item : row) {
      cout << item << " ";
    }
    cout << endl;
  }
}

bool is_equal_subset_sum_tab(vector<int> &nums, int S) {
  vector<vector<bool>> table(S + 1, vector<bool>(nums.size() + 1, false));
  
  for (int sum = 0; sum <= S; sum++) {
    for (int i = 0; i <= nums.size(); i++) {
      if (sum == 0)
        table[sum][i] = true;
      else if (i == 0)
        table[sum][i] = false;
      else if (sum < nums[i-1])
        table[sum][i] = table[sum][i-1];
      else
        table[sum][i] = table[sum-nums[i-1]][i-1] or table[sum][i-1];
      cout << sum << endl;
      print_table(table);
    }
  }
  
  return table[S][nums.size()];
}

int main() {
  vector<int> nums{4,2,4};
  
  int sum = accumulate(nums.begin(), nums.end(), 0);
  if (sum % 2 != 0)
    cout << 0 << endl;
  else {
    sum = sum/2;
    // vector<vector<int>> memo(nums.size() + 1, vector<int>(sum + 1, -1));
    // cout << is_equal_subset_sum(nums, sum, 0) << endl;
    // cout << is_equal_subset_sum_memo(nums, memo, sum, 0) << endl;
    cout << is_equal_subset_sum_tab(nums, sum) << endl;
  }
}
