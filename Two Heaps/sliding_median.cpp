// https://github.com/Eric-programming/CodeSolution/blob/master/src/Sort/SlidingWindowMedian/SlidingWindowMedian.java
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

vector<int> median_sliding_window(vector<int> nums, int k) {
  vector<double> medians;
  unordered_map<int,int> outgoing_num;
  priority_queue<int> small_list;
  priority_queue<int, vector<int>, greater<int>> large_list;

  for (int i = 0; i < k; i++)
    small_list.push(nums[i]);

  for (int i = 0; i < k/2; i++) {
    large_list.push(small_list.top());
    small_list.pop();
  }

  int balance = 0;
  int i = k;
  while(true) {
    // if the window size is odd
    if (k & 1)
      medians.push_back(small_list.top());
    else
      medians.push_back(((long)smallList.top() + (long)largeList.top()) * 0.5);

    // break the loop is all elements have been processed
    if (i >= nums.size())
      break;

    int out_num = nums[i-k];
    int in_num = nums[i];
    i++;

    // if the outgoing number is from max heap
    if (out_num <= small_list.top())
      balance -= 1;
    else
      balance += 1;

    if (outgoing_num.find(out_num) != outgoing_num.end())
      outgoing_num[out_num] += 1;
    else
      outgoing_num[out_num] = 1;
  }
}

int main() {
  vector<int> nums{3, 1, 2, -1, 0, 5, 8};
  int k = 4;
}
