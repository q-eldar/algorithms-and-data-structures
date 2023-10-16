#include <iostream>
#include <vector>
using namespace std;

int profit(vector<int> prices) {
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
    }

    max_profit = max(max_profit, cell_stock - buy_stock);
  }
  return max_profit;
}

int main() {
  vector<int> prices{7,6,4,3,1};
  cout << profit(prices) << endl;
}
