#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianOfStream {
private:
  vector<int> left_heap{};
  vector<int> right_heap{};
public:

  MedianOfStream(){
    std::make_heap(left_heap.begin(), left_heap.end());
    std::make_heap(right_heap.begin(), right_heap.end(), greater());
  }
  // This function should take a number and store it
  void InsertNum(int num){
    left_heap.push_back(num);
    std::push_heap(left_heap.begin(), left_heap.end());
    if (left_heap.size() > right_heap.size() + 1) {
      std::pop_heap(left_heap.begin(), left_heap.end());
      int left_top = left_heap.back();
      left_heap.pop_back();
      right_heap.push_back(left_top);
      std::push_heap(right_heap.begin(), right_heap.end(), greater());
    }
  }
  // This function should return the median of the stored numbers
  double FindMedian(){
    int left_size = left_heap.size();
    int right_size = right_heap.size();
    if (left_size + right_size > 0) {
      if ((left_size + right_size) % 2 == 0)
        return (left_heap.at(0) + right_heap.at(0)) / 2.0;
      else
        return left_heap.at(0) * 1.0;
    }
    return 0.0;
  }
};

int main() {
  MedianOfStream ms;
  ms.InsertNum(22);
  cout << ms.FindMedian() << endl;
  ms.InsertNum(35);
  cout << ms.FindMedian() << endl;
  ms.InsertNum(30);
  cout << ms.FindMedian() << endl;  
}
