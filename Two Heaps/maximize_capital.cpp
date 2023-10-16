#include <iostream>
#include <vector>
#include <queue>
#include <string_view>
using namespace std;

int maximize_capital(int c, int k, vector<int> capitals, vector<int> profits) {
  int current_capital = c;
  vector<vector<int>> capitals_min_heap{};
  make_heap(capitals_min_heap.begin(), capitals_min_heap.end(), greater());
  vector<vector<int>> profits_max_heap{};
  make_heap(profits_max_heap.begin(), profits_max_heap.end());

  for (int x = 0; x < capitals.size(); x++) {
    capitals_min_heap.push_back({capitals[x], x});
    std::push_heap(capitals_min_heap.begin(), capitals_min_heap.end(), std::greater());
  }

  for (int y = 0; y < k; y++) {
    while (!capitals_min_heap.empty() && capitals_min_heap[0][0] <= current_capital) {
      std::pop_heap(capitals_min_heap.begin(), capitals_min_heap.end(), std::greater());
      int c = capitals_min_heap.back()[0];
      int i = capitals_min_heap.back()[1];
      capitals_min_heap.pop_back();
      profits_max_heap.push_back({profits[i], i});
      std::push_heap(profits_max_heap.begin(), profits_max_heap.end());
    }

    if (profits_max_heap.empty())
      break;

    std::pop_heap(profits_max_heap.begin(), profits_max_heap.end());
    int j = profits_max_heap.back()[0];
    profits_max_heap.pop_back();
    current_capital += j;
  }
  return current_capital;
} 

int main() {
  int c = 1;
  int k = 2;
  vector<int> capitals{1,2,2,3};
  vector<int> profits{2,4,6,8};
  cout << maximize_capital(c,k,capitals,profits) << endl;
}
