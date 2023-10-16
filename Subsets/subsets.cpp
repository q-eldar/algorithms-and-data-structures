#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> subs) {
  for (const auto& item : subs)
    cout << item << " ";
  cout << endl;
}
// // Subsets with backtracking
// void all_subsets(vector<int> nums, vector<vector<int>> &subsets,
//                  vector<int> &current, int n) {
//   if (n + 1 >= nums.size())
//     subsets.push_back(current);

//   for (int i = n; i < nums.size(); i++) {
//     current.push_back(nums[i]);
//     all_subsets(nums, subsets, current, i+1);
//     current.pop_back();
//   }
// }

// Subsets with include/exclude
void all_subsets(vector<int> nums, vector<int> &current, int n) {
  if (n >= nums.size()) {
    print(current);
    return;
  }
  current.push_back(nums[n]);
  all_subsets(nums, current, n+1);
  current.pop_back();
  all_subsets(nums, current, n+1);
}

vector<vector<int>> FindAllSubsets(vector<int> nums)
{
  vector<vector<int>> subsets;
  vector<int> current;
  // all_subsets(nums, subsets, current, 0);
  return subsets; 
}

int main() {
  vector<int> nums{1,2,3};
  vector<int> current;
  all_subsets(nums, current, 0);
  // auto res = FindAllSubsets(nums);
  // for (const auto& v : res) {
  //   for (const auto& i : v) {
  //     cout << i << " ";
  //   }
  //   cout << endl;
  // }
}
