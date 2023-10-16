#include <iostream>
#include <vector>
using namespace std;

int sub_seq(vector<int> seq, int i, int j) {
  if (i == j)
    return 1;
  if (i == (j-1) && seq[i] == seq[j])
    return 2;
  if (seq[i] == seq[j])
    return sub_seq(seq, i+1, j-1) + 2;
  return max(sub_seq(seq, i+1, j), sub_seq(seq, i, j-1));
}

int main() {
  vector<int> seq{'B','B','A','B','C','B','C','A','B'};
  int n = 9;
  cout << sub_seq(seq, 0, seq.size() - 1) << endl;
  return 0;
}
