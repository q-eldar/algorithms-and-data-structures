#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void print(vector<int> &arr) {
  for (const auto& item : arr)
    cout << item << " ";
  cout << endl;
}

pair<int,int> missing_number(vector<int> &nums) {
  int missing = 0;
  int duplicate = 0;
  print(nums);
  int i = 0;
  while (i < nums.size()) {
    int correct = nums[i] - 1;

    if (nums[i] != nums[correct]) {
      swap(nums[i], nums[nums[i] - 1]);
      print(nums);
    } else
      i+=1;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (i + 1 != nums[i]) {
      duplicate = nums[i];
      missing = i + 1;
    }
  }

  return make_pair(missing, duplicate);
}

int main() {
  vector<int> nums{3,1,2,5,2};

  auto [missing, duplicate] = missing_number(nums);
  cout << missing << " " << duplicate << endl;
}
