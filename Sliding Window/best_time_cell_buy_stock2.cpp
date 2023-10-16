// its simpler than you think!!!!
#include <iostream>
#include <vector>
using namespace std;

int profit(vector<int> prices) {
  int profit = 0;
  int max_profit = 0;
  int buy_stock = prices[0];
  int cell_stock = prices[0];
  for (int stock_price : prices) {
    if (buy_stock > stock_price) {
      buy_stock = stock_price;
      cell_stock = stock_price;
    }

    if (cell_stock < stock_price) {
      cell_stock = stock_price;
    } else if (cell_stock > stock_price) {
      profit += max_profit;
      max_profit = 0;
      buy_stock = stock_price;
    }
  
    max_profit = max(max_profit, cell_stock - buy_stock);
    
  }
  cout << profit << endl;
  cout << max_profit << endl;
  if (max_profit > profit)
    return max_profit;
  return profit;
}

int main() {
  vector<int> prices{7,1,5,3,6,4};
  cout << profit(prices) << endl;
}
