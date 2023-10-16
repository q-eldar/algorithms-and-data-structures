#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <numeric>
using namespace std;

void print(const vector<pair<int,int>> &nums) {
  for (const auto& [a, b] : nums)
    cout << "[" << a << "," << b << "]" << " ";
  cout << endl;
}

int schedule (vector<pair<int,int>> &nums) {
  sort(nums.begin(), nums.end(), [](const auto& l, const auto& r) {
    return make_pair(l.first, -1 * abs(l.second - l.first)) < make_pair(r.first, -1 * abs(r.second - r.first)); 
  });

  int cost = accumulate(nums.begin(), nums.begin() + nums.size()/2, 0,
                        [](auto &a, auto &b) {
                          return a + b.first;
                        });
  cost = accumulate(nums.begin() + nums.size()/2, nums.end(), cost,
                        [](auto &a, auto &b) {
                          return a + b.second;
                        });

  return cost;
}

int main() {
  vector<pair<int,int>> nums{
    {10, 20}, {400, 50}, {30, 100}, {30, 20}
  };
  cout << schedule(nums) << endl;
}
