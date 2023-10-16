// We are given an input array of meeting time intervals, intervals, where each interval has a start time and an end time. Your task is to find the minimum number of meeting rooms required to hold these meetings.

//     An important thing to note here is that the specified end time for each meeting is exclusive.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
  vector<pair<int,int>> intervals {
    {2,8},
    {3,4},
    {3,9},
    {5,11},
    {8,20},
    {11,15}
  };

  sort(intervals.begin(), intervals.end(),
       [](const auto& left, const auto& right) {
         return left.first < right.first;
       });

  priority_queue<int, vector<int>, std::greater<int>> Q;
  Q.push(intervals[0].second);

  for (int i = 1; i < intervals.size(); i++) {
    if (Q.top() <= intervals[i].first) {
      Q.pop();
      Q.push(intervals[i].second);
    } else
      Q.push(intervals[i].second);
  }

  cout << Q.size() << endl;
}
