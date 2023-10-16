#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;

int nth_tribonacci(int n) {
  vector<int> nums(n + 1);
  nums[0] = 0;
  nums[1] = 1;
  nums[2] = 1;

  for (int i = 3; i <= n; i++) {
    nums[i] = nums[i-1] + nums[i-2] + nums[i-3];
  }
  return nums[n];
}

int nth_tribonacci_with_exchange(int n) {
  int first = 0;
  int second = 1;
  int third = 1;
  for (int i = 3; i <= n; i++) {
    first= std::exchange(second, std::exchange(third, third + second + first));
  }
  return third;
}
int main() {
  // cout << nth_tribonacci(10) << endl;
  cout << nth_tribonacci_with_exchange(5) << endl;
}
