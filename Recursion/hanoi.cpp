#include <iostream>
using namespace std;

void hanoi(int n, char src, char dst, char aux) {
  if (n == 0)
    return;
  hanoi(n-1, src, aux, dst);
  cout << n << " " << src << " " << dst << endl;
  hanoi(n-1, aux, dst, src);
}

int main() {
  int n = 3;
  hanoi(n, 'A', 'C', 'B');
}
