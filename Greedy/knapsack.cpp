#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<pair<int,int>> vp{{60, 10}, {100, 20}, {120, 30}};
  auto cmp = [](auto& p1, auto& p2) {
    return p1.first/p1.second < p2.first/p2.second;
  };
  sort(begin(vp), end(vp), cmp);
  int total_w = 50;

  
  for (const auto& [value, weight] : vp) {
    
  }
}
