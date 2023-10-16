// https://leetcode.com/problems/maximum-product-subarray/
// solution: https://www.youtube.com/watch?v=hnswaLJvr6g
#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

int max_product(vector<int>& nums) {
  int pre = 1, suff = 1;
  int ans = INT_MIN;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    if (pre == 0) pre = 1;
    if (suff == 0) suff = 1;

    pre = pre * nums[i];
    suff = suff * nums[n - i - 1];
    ans = max({ans, pre, suff});
  }
  return ans;
}

int main() {
  vector<int> nums{2,3,-2,4};
  cout << max_product(nums) << endl;
}
