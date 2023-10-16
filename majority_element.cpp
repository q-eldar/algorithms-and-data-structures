#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> &nums) {
  for (const auto& item : nums)
    cout << item << " ";
  cout << endl;
}

int majority_element(vector<int> &nums) {
  print(nums);
  auto pivot = partition(nums.begin(), nums.end(), [&](int a) {
    return a >= nums[0];
  });
  cout << pivot - nums.begin() << endl;  
  print(nums);
  return 0;
}

int main() {
  vector<int> nums{2,3,1,3,2,3,3};
  majority_element(nums);
}
