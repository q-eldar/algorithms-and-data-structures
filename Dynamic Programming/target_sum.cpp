#include <iostream>
#include <vector>
using namespace std;

int target_sum(vector<int> nums, int i, int sum) {
  if (i == nums.size()) {
    if (sum == 0)
      return 1;
    return 0;
  }

  int take_plus = target_sum(nums, i+1, sum + nums[i]);
  int take_minus = target_sum(nums, i+1, sum - nums[i]);
  // int no_take = target_sum(nums, i+1, sum);

  return take_plus + take_minus;
}

int main() {
  vector<int> nums{1, 1, 1, 1};
  int sum = 2;
  cout << target_sum(nums, 0, sum) << endl;
}
