#include <iostream>
#include <vector>
using namespace std;

bool game(vector<int> &nums, int i) {

  while (--i >= 0) {
    if (nums[i] == 0)
      break;
  }
  if (i < 0)
    return true;
  
  int pos = i;
  while(--i + nums[i] <= pos);
  if (i < 0)
    return false;
  return game(nums, i);
}

bool JumpGame(std::vector<int> nums){
  int targetNumIndex = nums.size() - 1;
  for(int i = nums.size() - 2; i > -1; i--){
    if (targetNumIndex <= i + nums[i]){
      targetNumIndex = i;
    }
  }
  if(targetNumIndex == 0){
    return true;
  }
  return false;
}

int main() {
  vector<int> nums{3, 2, 0, 1, 4};
  // cout << game(nums, nums.size() - 1) << endl;
  cout << JumpGame(nums) << endl;
}
