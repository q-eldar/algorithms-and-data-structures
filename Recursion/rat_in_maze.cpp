#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void print(const vector<T>& row) {
  for (const auto& item : row)
    cout << item << " ";
  cout << endl;
}

template<typename T>
void print_board(vector<vector<T>>& board) {
  for (const auto& row : board) {
    print(row);
  }
}

void all_paths(vector<vector<char>>& maze, vector<vector<char>>& path, int row, int col, int dest_x, int dest_y) {
  if (row == dest_x && col == dest_y) {
    path[row][col] = '1';
    print_board(path);
    cout << endl;
    path[row][col] = '0';
  }
  
  if (row > dest_x || col > dest_y)
    return;

  if (maze[row][col] == 'X')
    return;
  
  // move left
  path[row][col] = '1';
  all_paths(maze, path, row, col+1, dest_x, dest_y);
  // move down
  all_paths(maze, path, row+1, col, dest_x, dest_y);
  path[row][col] = '0';
}

int main() {
  vector<vector<char>> maze = {
    {'0','0','0','0'},
    {'0','0','X','0'},
    {'0','0','0','X'},
    {'0','X','0','0'},
  };

  vector<vector<char>> path(maze.size(), vector<char>(maze.size(), '0'));
  all_paths(maze, path, 0, 0, 3, 3);
}
