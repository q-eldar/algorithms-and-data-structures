#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int>> k_pairs_with_smalles_sum(vector<int> l1, vector<int> l2, int k) {
  vector<pair<int,int>> pairs{};
  for (int i = 0; i < l1.size(); i++) {
    int j = 0;
    while(j < l2.size() && k--) {
      int sum = l1[i] + l2[j];
      if (i == 0)
        pairs.push_back({l1[i], l2[j]});
      else 
      if (i > 0 && i + 1 < l1.size()) {
        if (sum < l1[i+1] + l2[0])
          pairs.push_back({l1[i], l2[j]});
        else
          continue;
      } else {
        
      }
      j++;
    }
  }
  return pairs;
}

int main() {
  int k = 3;
  vector<int> l1{2,8,9};
  vector<int> l2{1,3,6};

  vector<pair<int,int>> pairs = k_pairs_with_smalles_sum(l1,l2,k);

  for (const auto [start, end] : pairs)
    cout << "[" << start << ", " << end << "]" << ", ";
  cout << endl;
}
