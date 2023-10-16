// Educative : You need to find the minimum number of refueling stops that a car
// needs to make to cover a distance, target. For simplicity, assume that the
// car has to travel from west to east in a straight line. There are various
// fuel stations on the way that are represented as a 2-D array of stations,
// i.e., stations[i] =[di,fi]=[di​,fi​], where didi​ is the distance (in miles) of
// the ithith gas station from the starting position, and fifi​ is the amount of
// fuel (in liters) that it stores. Initially, the car starts with k liters of
// fuel. The car consumes one liter of fuel for every mile traveled. Upon
// reaching a gas station, the car can stop and refuel using all the petrol
// stored at the station. If it cannot reach the target, the program returns
// −1−1.

// also

// leetcode 134 : https://www.youtube.com/watch?v=lJwbPZGo05A
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <numeric>
#include <queue>
using namespace std;

int MinRefuelStops(int target, int startFuel, std::vector<std::vector<int>>& stations) {
    if (startFuel >= target) {
        return 0;
    }
    
    std::priority_queue<int> maxHeap;
    int i = 0;
    int n = stations.size();
    int stops = 0;
    int maxDistance = startFuel;
    
    while (maxDistance < target) {
        if (i < n && stations[i][0] <= maxDistance) {
            maxHeap.push(stations[i][1]);
            i++;
        }
        else if (maxHeap.empty()) {
            return -1;
        }
        else {
            maxDistance += maxHeap.top();
            maxHeap.pop();
            stops++;
        }
    }
    
    return stops;
}

int main() {
  vector<vector<int>> stations {
    {2,5},
    {3,1},
    {6,4},
    {12,6}
  };

  int target = 15;
  int starting_fuel = 3;

  cout
    << MinRefuelStops(target, starting_fuel, stations)
    << endl;
}
