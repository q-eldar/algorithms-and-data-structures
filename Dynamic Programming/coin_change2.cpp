#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coin_change(vector<int> &coins, int total, int i) {
  if (i >= coins.size())
      return -1;

  if (total == 0)
    return 0;
  
  if (total < 0)
    return -1;
  
  int inc = coin_change(coins, total - coins[i], i);
  int exl = coin_change(coins, total, i+1);
  
  if (inc != -1 && exl != -1)
    return min(inc + 1, exl);
  if (inc == -1)
    return exl;
  if (exl == -1)
    return inc + 1;
  return -1;
}

int main() {
  vector<int> coins{1,2,3};
  int total = 5;
  cout << coin_change(coins, total, 0) << endl;
}
