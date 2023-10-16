// solution: https://takeuforward.org/data-structure/count-subsets-with-sum-k-dp-17/
// todo: learn tabulation
#include <iostream>
#include <vector>
using namespace std;

int count_subset_sum(vector<int>& nums, int i, int sum) {
  if (sum == 0)
    return 1;

  if (i == 0)
    return (nums[0] == sum) ? 1 : 0;
  
  int take = 0;
  if (nums[i] <= sum)
    take = count_subset_sum(nums, i-1, sum-nums[i]);

  int no_take = count_subset_sum(nums, i-1, sum);

  return take + no_take;
} 

int main() {
  vector<int> nums{1,2,3,4};
  int sum = 4;
  cout << count_subset_sum(nums, nums.size() - 1, sum) << endl;
}
