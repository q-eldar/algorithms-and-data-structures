#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> start{10, 12, 20};
  vector<int> finish{20, 25, 30};

  sort(begin(finish), end(finish));
  
  int count = 1;
  int fin = finish[0];
  for(int i = 1; i < finish.size(); i++) {
    if (start[i] >= fin) {
      fin = finish[i];
      count++;
    }
  }

  cout << count << endl;
}
