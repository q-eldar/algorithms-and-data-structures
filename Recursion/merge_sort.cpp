#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<int>& arr) {
  for (const auto& item : arr)
    cout << item << " ";
  cout << endl;
}

/*
  [1,3,2,4]
  [5,2,3,1]
 */
void merge(vector<int>& arr, int low, int high) {
  int mid = (low + high) / 2;
  int left_idx = low;
  int right_idx = mid + 1;
  int buffer_idx = left_idx;
  vector<int> buffer(arr.size());

  while (left_idx <= mid && right_idx <= high) {
    if (arr[left_idx] <= arr[right_idx])
      buffer[buffer_idx++] = arr[left_idx++];
    else {
      buffer[buffer_idx++] = arr[right_idx++];
    }
  }

  while (left_idx <= mid) buffer[buffer_idx++] = arr[left_idx++];
  while (right_idx <= high) buffer[buffer_idx++] = arr[right_idx++];

  for (int i = low; i <= high; i++)
    arr[i] = buffer[i];
}

void merge_sort(vector<int>& v, int low, int high) {
  if (low >= high)
    return;
  int mid = (low + high) / 2;
  merge_sort(v, low, mid);
  merge_sort(v, mid+1, high);
  // @alternative: https://en.cppreference.com/w/cpp/algorithm/inplace_merge
  merge(v, low, high);
}

int main() {
  // vector<int> v{1,3,2,4};
  vector<int> v{5,2,3,1};
  print(v);
  // merge(v, 0, 3);
  merge_sort(v, 0, 3);
  print(v);
}
