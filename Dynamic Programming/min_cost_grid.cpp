#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int min_cost(vector<vector<int>> cost, int x, int y, int dest_x, int dest_y) {
  if (x == dest_x && y == dest_y)
    return cost[x][y];
  if (x >= cost[0].size() || y >= cost[0].size())
    return INT_MAX;
  
  return cost[x][y] + min(min_cost(cost, x+1, y, dest_x, dest_y),
                          min_cost(cost, x, y+1, dest_x, dest_y)); 
}

int main() {
  vector<vector<int>> cost = {{1, 2, 3}, 
                              {4, 8, 2}, 
                              {1, 5, 3}};
  cout << min_cost(cost, 0, 0, 2, 2) << endl; 
  return 0;
}
