#include <iostream>
#include <vector>
using namespace std;

using Int_Matrix = vector<vector<int>>;

void print(const vector<int>& arr) {
  for (const auto& item : arr)
    cout << item << " ";
}

void print(const vector<vector<int>>& arr) {
  for (const auto& item : arr) {
    print(item);
    cout << endl;
  }
  cout << endl;
}

int unique_paths(int m, int n) {
  Int_Matrix grid(m, vector<int>(n, 0));

  for (int i = 0; i < n; i++)
    grid[0][i] = 1;

  for (int i = 0; i < m; i++) {
    grid[i][0] = 1;
  }

  print(grid);
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      grid[i][j] = grid[i-1][j] + grid[i][j-1];
    }
  }
  print(grid);
  return grid[m-1][n-1];
}

int main() {
  int m{3};
  int n{7};
  cout << unique_paths(m,n) << endl;
}
