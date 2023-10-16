#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using INT_MATRIX = vector<vector<int>>;

int kth_smallest_in_sorted_array(INT_MATRIX matrix, int k) {
  std::priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,
                      greater<tuple<int,int,int>>> min_heap;
  
  for (int i = 0; i < matrix[0].size(); i++) {
    min_heap.push(std::make_tuple(matrix[i][0], i, 0));
  }

  int row = 0, col = 0, value = -1;
  while(!min_heap.empty() && k-- > 0) {
    tie(value, row, col) = min_heap.top();
    cout << k << ": " << value << " " << row << " " << col << endl;
    min_heap.pop();
    if (col + 1 < matrix[0].size())
      min_heap.push(std::make_tuple(matrix[row][col+1], row, col+1));
    }
  
  return value;
}

int main() {
  INT_MATRIX m = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  int k = 4;
  
  cout << kth_smallest_in_sorted_array(m,k) << endl;
}
