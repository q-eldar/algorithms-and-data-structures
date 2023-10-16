bool check(const vector<vector<int>>& board, int row, int col) {
  // check same row
  cout << "Checking row.." << endl;
  for (int i = 0; i < board[0].size(); i++) {
    cout << "board[" << row << "][" << i << "] "  << board[row][i] << endl; 
  }
  // check same col
  cout << "Checking column.." << endl;
  for (int i = 0; i < board[0].size(); i++) {
    cout << "board[" << i << "][" << col << "] "  << board[i][col] << endl;
    // if (board[0][col] != 0)
    //   return false;
  }
  // check diagonal
  cout << "Checking diagonal(top-left to bottom-right).." << endl;
  for (int i = 0; i < board[0].size(); i++) {
    if (i + abs(row-col) < board[0].size()) {
      cout << "board[" << i <<  "][" << i + abs(row-col) << "] " << board[i][i + abs(row-col)] << endl; 
    }
  }
  cout << "Checking diagonal(top-right to bottom-left).." << endl;
  for (int i = 0; i < board[0].size(); i++) {
    if (row + col - i >= 0 && row + col - i < board[0].size()) {
      cout << "board[" << i <<  "][" << row + col - i << "] " << board[i][row + col - i] << endl; 
    }
    
  }
  return true;
}
