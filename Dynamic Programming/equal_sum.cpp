#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

bool equal_sum(vector<int> &nums, int i, int sum) {
  if (i == nums.size())
    return false;
  if (nums[i] == sum)
    return true;
  if (nums[i] > sum)
    return equal_sum(nums, i+1, sum);

  int take = equal_sum(nums, i+1, sum-nums[i]);
  int no_take = equal_sum(nums, i+1, sum);

  return take || no_take;
}

bool isSubsetSum(vector<int> arr, int n, int sum)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
 
    // If last element is greater than sum, then
    // ignore it
    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum);
 
    /* else, check if sum can be obtained by any of
        the following
        (a) including the last element
        (b) excluding the last element
    */
    return isSubsetSum(arr, n - 1, sum)
           || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}
 
int main() {
  vector<int> nums{1, 3, 5};
  int sum = accumulate(nums.begin(), nums.end(), 0);
  cout << isSubsetSum(nums, nums.size(), sum / 2) << endl;
  // cout << equal_sum(nums, 0, sum/2) << endl;
}
