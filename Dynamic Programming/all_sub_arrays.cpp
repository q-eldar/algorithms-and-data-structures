#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void sub_arrays(vector<int> seq, int s, int e) {
  if (e == seq.size())
    return;
  else if (s > e)
    sub_arrays(seq, 0, e + 1);
  else {
    copy(seq.begin() + s, seq.begin() + e + 1, ostream_iterator<int>(cout, " ")); cout << endl;
    sub_arrays(seq, s + 1, e);
  }
}

int main() {
  vector<int> seq{1, 2, 3};
  sub_arrays(seq, 0, 0);
}
