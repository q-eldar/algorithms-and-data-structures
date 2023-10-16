// recursive + bitmap : https://www.quora.com/Find-all-subsets-of-an-int-array-whose-sums-equal-a-given-targe
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &sub) {
  for (const auto& i : sub)
    cout << i << " ";
  cout << endl;
}

void k_sum(vector<int> &nums, vector<int> sub, int sum, int i) {
  if (sum == 0) {
    print(sub);
    return;
  }


  if(i == nums.size() && sum != 0){ 
		return; 
	} 
	 
  // if (sum == 0) {
  //   print(sub);    
  //   // sub.pop_back();
  //   k_sum(nums, sub, sum+nums[i], i-1);
  //   // return;
  // }
  if (sum < 0) {
    return;
  }

  
  k_sum(nums, sub, sum, i+1);
  sub.push_back(nums[i]);
  k_sum(nums, sub, sum-nums[i], i+1);
  
}

int main() {
  vector<int> nums{1,3,5,21,19,7,2};
  vector<int> sub{};
  int k = 10;
  k_sum(nums, sub, k, 0);
}
