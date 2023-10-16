#include <iostream>
#include <vector>
#include <string>
using namespace std;
using CHAR_MATRIX = vector<vector<char>>;

bool check(CHAR_MATRIX &m, string &word, int row, int col, int word_index) {
  if (row < 0 || col < 0 || word_index >= word.length())
    return false;
  if (m[row][col] == word[word_index])
    return true;
  return false;
}

bool word_search(CHAR_MATRIX& m, string word, int row, int col, int word_index){
  if (word_index == word.length())
    return true;
  
  if (word_index > static_cast<int>(word.length()))
    return false;
      
  if (row >= static_cast<int>(m.size()) || col >= static_cast<int>(m[0].size())) 
    return false;

  for (int i : {0, 1, -1}) {
    for (int j : {0, 1, -1}) {
      if ((i == 0 && j == 0) || (i != j) || (i == 1 && j == -1) || (i == -1 && j == 1)) {
        if (check(m, word, row + i, col + j, word_index)) {
          if (word_search(m, word, row + i, col + j, word_index+1)) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

int main() {
  CHAR_MATRIX m{
    {'e', 'd', 'x', 'i', 'w'},
    {'p', 'u', 'f', 'm', 'q'},
    {'i', 'c', 'a', 't', 'e'},
    {'m', 'a', 'l', 'c', 'a'},
    {'j', 't', 'i', 'v', 'e'}
  };
  string word{"educative"};

  cout << word_search(m, word, 0, 0, 0) << endl;
  // cout << check(m, word, 0, 0, word.length()) << endl;
}
