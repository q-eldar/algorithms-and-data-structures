#include <iostream>
#include <vector>
using namespace std;

int knap(vector<int>& val, vector<int>& wt, int W, int n) {
  if (n == 0 || W == 0)
    return 0;
  if (wt[n-1] > W)
    return knap(val, wt, W, n-1);
  return max(val[n-1] +
             knap(val, wt, W - wt[n-1], n-1),
             knap(val, wt, W, n-1));
}

int main() {
  vector<int> val{60, 100, 120};
  vector<int> wt{ 10, 20, 30 };
  int W = 50;
  cout << knap(val, wt, W, val.size()) << endl;
}
