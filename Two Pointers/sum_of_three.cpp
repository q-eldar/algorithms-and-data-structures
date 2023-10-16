// TODO: complete the algorithm

// Given an array of integers, nums, and an integer value, target, determine if
// there are any three integers in nums whose sum is equal to the target, that
// is, nums[i] + nums[j] + nums[k] == target. Return TRUE if three such integers
// exist in the array. Otherwise, return FALSE.
#include <iostream>
#include <vector>
#include <algorithms>
using namespace std;

// 1,2,3,4,5,7,8
bool sum_of_three(vector<int> &nums, target) {
  sort(nums.begin(); nums.end());
  int left = 0;
  int right = nums.size() - 1;
  int first = nums[left];
  int rest_of = target-first;
  left++;
  while (left < right) {
    if (nums[left] + nums[right] == rest_of)
      return true;
    else if (nums[left] + nums[right] < rest_of)
      left++;
    else
      right++;
  }
}

int main() {
  vector<int> nums{3,7,1,2,8,4,5};
  int target = 10;
  cout << sum_of_three(nums, target) << endl;
}
