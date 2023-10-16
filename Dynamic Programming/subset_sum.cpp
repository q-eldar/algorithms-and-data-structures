#include <iostream>
#include <vector>
using namespace std;

bool subset_sum(vector<int> &nums, int i, int sum) {
  if (i == nums.size())
    return false;
  if (sum == 0)
    return true;

  if (sum < 0)
    return subset_sum(nums, i+1, sum);

  bool take = subset_sum(nums, i+1, sum-nums[i]);
  bool no_take = subset_sum(nums, i+1, sum);

  return take || no_take;
}

int main() {
  vector<int> nums{3, 5, 9};
  int sum = 2;
  cout << subset_sum(nums, 0, sum) << endl;
}
