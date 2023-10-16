// https://leetcode.com/problems/longest-increasing-subsequence/
#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int lis(vector<int> nums, int index, int last) {
  if (index >= nums.size())
    return 0;
  if (nums[index] < last)
    return 0;
  int res = INT_MIN;
  for (int i = index; i < nums.size(); i++){
    for (int j = i+1; j < nums.size(); j++) {
      int ans = lis(nums, j, nums[i]);
      // if (ans != -1 || ans != 0)
      res = max(res, 1+ans);
    }    
  }
  
  return res;
}

int main() {
  vector<int> nums{10,9,2,5,3,7,101,18};
  cout << lis(nums, 0, INT_MIN) << endl; 
}
