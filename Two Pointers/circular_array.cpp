#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int next(vector<int> &nums, int current_index) {
  return abs(int(nums.size()) +
             nums[current_index] + current_index) % int(nums.size());
}

bool is_circular_array(vector<int> &nums) {
  int size = nums.size();
  for (int i = 0; i < size; i++) {
    int slow = i;
    int fast = i;
    while (true) {
      slow = next(nums, slow);
      fast = next(nums, next(nums, fast));
      
      if (nums[slow] * nums[i] < 0 ||
          nums[fast] * nums[i] < 0 ||
          abs(nums[slow] % size) == 0 ||
          abs(nums[fast] % size) == 0)
        break;
      
      if (slow == fast)
        return true;
    }
  }
  return false;
}

int main() {
  vector<vector<int>> v_of_nums{
    {1,3,-2,-4,1},
    {2,1,-1,-2,2},
    {3,3,1,-1,2},
    {3,-3,2,-2},
    {1,4,3,2,1},
    {-2,-3,1,-3,2},
    {5,-1,1,1,-7,-9},
    {2,5,-4,3,-1,4}
  };
  
  for (auto &nums : v_of_nums)
    cout << is_circular_array(nums) << endl;
  // cout << next(nums, 3) << endl;
}
