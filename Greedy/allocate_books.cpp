#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int numberOfStudents(int arr[], int n, int maxLen) {
	int total = 0, numPainters = 1; 

	for (int i = 0; i < n; i++) { 
		total += arr[i]; 

		if (total > maxLen) { 
			total = arr[i]; 
			numPainters++; 
		} 
	} 

	return numPainters; 
}

int findPages(int arr[], int n, int m) { 
	int low = *max_element(arr, arr+n);
  int high = accumulate(arr, arr+n, 0);
  while (low < high) {
    int mid = low + (high - low) / 2;
    int requred_students = numberOfStudents(arr, n, mid);
    // cout << "low: " << low << " high: " << high << " mid: " << mid << " required students: " << requred_students << endl;
    if (requred_students <= m)
      high = mid;
    else
      low = mid + 1;
  }
	return low; 
} 

int main() {
  int arr[] = {12, 34, 67, 90};
  cout << findPages(arr, 4, 2) << endl;
}
