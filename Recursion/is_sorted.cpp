#include <iostream>
using namespace std;

bool isSortedUtil(int *arr, int i, int n) {
  if (i >= n)
    return true;

  if (arr[i-1] > arr[i])
    return false;

  return isSortedUtil(arr, i+1, n);
}

bool isSorted(int *arr, int n){
  return isSortedUtil(arr, 1, n);
}

int main() {
  int arr[] = {1, 2, 3, 7, 9, 11};
  cout << isSorted(arr, sizeof(arr)/sizeof(arr[0])) << endl;
}
