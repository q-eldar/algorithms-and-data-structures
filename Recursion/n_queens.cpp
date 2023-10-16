#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void print(const vector<int>& row) {
  for (const auto& item : row)
    cout << item << " ";
  cout << endl;
}

void print_board(vector<vector<int>> &board) {
  for (const auto& row : board) {
    print(row);
  }
}

bool is_safe(const vector<vector<int>>& board, int row, int col) {
  for (int i = 0; i < row; i++)
    if (board[i][col])
      return false;

  // left diagonal
  int x = row;
  int y = col;
  while(x >= 0 && y >= 0) {
    if (board[x][y] == 1) return false;
    x--;
    y--;
  }
  // right diagonal
  x = row;
  y = col;
  while (x >=0 && y < board[0].size()) {
    if (board[x][y] == 1) return false;
    x--;
    y++;
  }

  return true;
}

bool queens(vector<vector<int>>& board, int row) {
  if (row == board[0].size()) {
    print_board(board);
    cout << endl;
    return false;
  }
  
  for (int col = 0; col < board[0].size(); col++) {
    if(is_safe(board, row, col)) {
      board[row][col] = 1;
      if (queens(board, row+1))
        return true;
      board[row][col] = 0;
    }
  }
  return false;
}

int main() {
  int n = 4;
  vector<vector<int>> board = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  };
  queens(board, 0);
}
