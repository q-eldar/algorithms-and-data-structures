#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
using namespace std;

// Works if number of duplicates are 1
// int duplcate_number(vector<int> &nums) {
//   int n = nums.size();
//   int total_sum = ((n+1) * n) / 2;
//   return abs(total_sum -
//              accumulate(nums.begin(), nums.end(), 0) -
//              int(nums.size()));
// }

int main() {
  vector<int> nums{9, 6, 12, 7, 15, 8, 3, 13, 2, 10, 4, 14, 1, 11, 9, 5};
  cout << duplcate_number(nums) << endl;
}
