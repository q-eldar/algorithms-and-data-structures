#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int res = INT_MAX;
int inc = 0;
int exl = 0;
int min_coins(vector<int> coins, int sum, int i) {
  
  if (i > coins.size() - 1)
    return -1;

  if (sum == 0)
      return 0;
  
  if (sum < 0)
    return -1;

  int inc = min_coins(coins, sum - coins[i], i);
  int exl = min_coins(coins, sum, i+1); 

  if (inc != -1 && exl != -1)
    return min(inc + 1, exl);
  if (inc == -1)
    return exl;
  if (exl == -1)
    return inc + 1;
  return -1;
}

int main() {
  vector<int> coins{9, 6, 5, 1};
  int n = 13;
  cout << min_coins(coins, n, 0) << endl;
}
