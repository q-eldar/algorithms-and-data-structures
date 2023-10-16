// https://leetcode.com/problems/house-robber-ii/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int rob(vector<int>& nums, int n) {
  if (n >= nums.size())
    return 0;
  int take = nums[n] + rob(nums, n + 2); // take
  int no_take = rob(nums, n + 1); // not take
  return max(take, no_take);
}

int main() {
  vector<int> nums{2, 7, 9, 3, 1, 13};
  cout << rob(nums, 0) << endl;
}
