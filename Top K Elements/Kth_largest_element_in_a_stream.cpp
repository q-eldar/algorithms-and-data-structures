#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kth_largest(vector<int> nums, int k) {
  priority_queue<int, vector<int>, greater<int>> heap;

  for (int i = 0; i < nums.size(); i++) {
    heap.push(nums[i]);
    if (heap.size() > k)
      heap.pop();
  }

  return heap.top();
}

int main() {
  vector<int> nums{6,8,7,5,9,4,2,3,40,30};
  int k = 6;
  cout << kth_largest(nums, k) << endl;
}
