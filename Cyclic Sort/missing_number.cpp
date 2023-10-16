#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &arr) {
  for (const auto& item : arr)
    cout << item << " ";
  cout << endl;
}

int missing_number(vector<int> &nums) {
  int i = 0;
  while (i < nums.size()) {
    if (nums[i] < nums.size() && i != nums[i]) {
      swap(nums[i], nums[nums[i]]);
      // print(nums);
    } else
      i++;
  }

  for (int i = 0; i < nums.size(); i++)
    if (i != nums[i])
      return i;
  return -1;
}

int main() {
  vector<int> nums{0, 1, 2};
  cout << missing_number(nums) << endl;
}
