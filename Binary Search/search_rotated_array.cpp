#include <iostream>
#include <vector>
using namespace std;

// int get_high(int high, int size, int t) {
//   return (high + (size + (t - 1)) % size) % t;
// }

// int get_low(int low, int size, int t) {
//   return low + (size + (t)) % size;
// }

// int get_mid()

int search(vector<int> nums, int target) {
  int low = 0;
  int high = nums.size() - 1;
  while (low <= high) {
    int mid = low + (high - low)/2;
    if (nums[mid] == target)
      return mid;
    if (nums[low] < nums[mid]) {
      if (nums[low] <= target && target < nums[mid])
        high = mid - 1;
      else
        low = mid + 1;
    } else {
      if (nums[mid] < target && target <= nums[high])
        low = mid + 1;
      else
        high = mid - 1;
    }
  }
  return -1;
}

int main() {
  vector<int> nums{3,4,5,6,7,1,2};
  int target = 7;
  cout << search(nums, target) << endl;
}
