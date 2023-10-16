#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int rod_cut(vector<int> &price, int n) {
  int max_revenue = INT_MIN;
  if (n <= 0)
    return 0;
  else {
    for (int i = 1; i <= n; i++) {
      max_revenue = max(max_revenue, price[i] + rod_cut(price, n-i));
    }    
  }

  return max_revenue;
}

int main() {
  int n = 6;
  vector<int> price{0,2,5,8,9,10,11};
  cout << rod_cut(price, n) << endl;
}
