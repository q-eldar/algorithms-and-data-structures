#include <iostream>
#include <vector>
using namespace std;

int single_element(vector<int> nums) {
  int low = 0;
  int high = nums.size() - 1;

  while (low < high) {
    int mid = low + (high - low) / 2;
    if (mid % 2 != 0) {
      if (nums[mid] != nums[mid-1])
        high = mid - 1; 
      else
        low = mid + 1;
    } else {
      if (mid + 1 == nums.size())
        return mid;
      else if (nums[mid] != nums[mid+1])
        high = mid;
      else
        low = mid + 1;
    }
  } 
  
  return nums[low];
}

int main() {
  vector<int> nums{1, 1, 2, 2, 3, 3, 4, 4, 5, 8, 8};
  cout << single_element(nums) << endl;
}
