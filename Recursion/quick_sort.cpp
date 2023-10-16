#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& arr) {
  for (const auto& item : arr)
    cout << item << " ";
  cout << endl;
}

int partition(vector<int>& v, int low, int high) {
  int pivot_index = high;
  high = high - 1;
  // low = low + 1;
  while (low <= high) {
    if (v[high] < v[pivot_index]) {
      swap(v[high], v[low]);
      low++;
    } else high--;
  }
  swap(v[pivot_index], v[low]);

  return low;
}

void quick_sort(vector<int>& v, int low, int high) {
  if (low < high) {
    int pivot = partition(v, low, high);
    quick_sort(v, low, pivot - 1);
    quick_sort(v, pivot + 1, high);
  }
}

int main() {
  vector<int> v{5,2,3,1};
  print(v);
  // int pivot = partition(v, 0, v.size()-1);
  // cout << pivot << endl;
  quick_sort(v, 0, v.size() - 1);
  print(v);
}
