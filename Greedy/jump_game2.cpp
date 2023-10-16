// solution: https://www.youtube.com/watch?v=dJ7sWiOoK7g
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <numeric>
#include <queue>
using namespace std;

int min_jumps(vector<int> &nums) {
  std::priority_queue<int> max_heap;
  // farthest index we can reach
  int farthest_jump = 0;
  int current_jump = 0;
  int jumps = 0;
  
  int max_dist = nums[0];
  int target = nums.size();
  int i = 1;
  int n = nums.size();
  int min_hop = 1;
  // max_heap.push(nums[0]);

  while (max_dist <= target) {
    if (i < n && i <= max_dist) {
      max_heap.push(nums[i]);
      i++;
    } else if (max_heap.empty()) {
      return -1;
    } else {
      max_dist += max_heap.top();
      max_heap.pop();
      min_hop++;
    }
  }
  return min_hop;
}

int main() {
  vector<int> nums{1, 1};
  cout << min_jumps(nums) << endl;
}
