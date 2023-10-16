#include <iostream>
#include <vector>
using namespace std;

int lis(vector<int> seq, int last, int i) {
  if (i >= seq.size())
    return 0;
  if (seq[i] < last)
    return lis(seq, last, i+1);

  return lis(seq, seq[i], i+1) + 1;
}

int main() {
  vector<int> seq{10, 9, 3, 5, 4, 11, 7, 8};
  cout << lis(seq, seq[0], 1) << endl;
}
