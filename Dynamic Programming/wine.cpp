#include <iostream>
#include <vector>
using namespace std;

int max_price(vector<int> price, int start, int end, int year) {
  if (start > end)
    return 0;
  return max(max_price(price, start+1, end, year+1) + price[start] * year,
             max_price(price, start, end-1, year+1) + price[end] * year);
}

int main() {
  vector<int> price{2,3,5,1,4};
  int start = 0;
  int end = price.size() - 1;
  int year = 1;
  cout << max_price(price, start, end, year) << endl;
}
