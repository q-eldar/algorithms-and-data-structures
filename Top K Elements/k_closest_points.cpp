#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <cmath>
using namespace std;

vector<pair<int,int>> k_closest_points(vector<pair<int,int>> points, int k) {
  priority_queue<tuple<double, int, int>,
                 vector<tuple<double, int, int>>,
                 less<tuple<double, int, int>>> heap;
  
  for (const auto& [x,y] : points) {
    heap.push(std::make_tuple(std::sqrt(std::pow(x,2)+std::pow(y,2)), x, y));
    if (heap.size() > k)
      heap.pop();
  }
  
  vector<pair<int,int>> result{};
  while(!heap.empty()) {
    const auto& [dist, x, y] = heap.top();
    result.push_back({x,y});
    heap.pop();
  }
  
  return result;
}

int main() {
  vector<pair<int,int>> points{
    {1, -3}, {4, -2}, {2, -1}, {-2, 2}, {5, 3}, {3, -2}
  };
  int k = 4;
  auto k_points = k_closest_points(points, k);

  for (const auto& [x,y] : k_points)
    cout << "(" << x << ", " << y << ")";
  cout << endl;
}
