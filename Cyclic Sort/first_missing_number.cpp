#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void print(vector<int> &arr) {
  for (const auto& item : arr)
    cout << item << " ";
  cout << endl;
}

int first_missing_number(vector<int> &nums) {
  // nums.push_back(0);
  // swap(nums[0], nums[nums.size() - 1]);
  print(nums);
  int i = 0;
  while (i <= nums.size()) {
    if (nums[i] > 0 && nums[i] < nums.size() + 1 && i + 1 != nums[i]) {
      swap(nums[i], nums[nums[i] - 1]);
      print(nums);
    } else
      i++;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (i + 1 != nums[i])
      return i + 1;
    else
      i++;
  }

  return -1;
}

int main() {
  vector<int> nums{7,8,9,10};

  cout << first_missing_number(nums) << endl;
}
