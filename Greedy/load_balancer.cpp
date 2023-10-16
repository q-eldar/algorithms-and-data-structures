#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
  int arr[] = {16, 17, 15, 0, 20, 1, 1, 2};
  int n = sizeof(arr)/sizeof(arr[0]);
  int max_load = 0, load = 0, diff;
  load = accumulate(arr, arr + n, 0);
  if (!(load % n))
    cout << -1 << endl;

  load /= n;
  cout << load << endl;
  for(int i = 0; i < n; i++){
    diff += (arr[i] - load);
    cout << diff << " " << max_load << endl;
    if (diff < 0)
      max_load = max(max_load, -1*diff);
    else
      max_load = max(max_load, diff);
  }
  cout << max_load;
  return 0;
}
