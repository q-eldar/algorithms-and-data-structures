#include <iostream>
#include <vector>
#include <queue>
#include <exception>
#include <algorithm>
using namespace std;

using AdjacencyList = vector<vector<int>>;

class NoPathExistsException : public runtime_error {
public:
  NoPathExistsException() : runtime_error("No path exists between the nodes.") {}
};

class ShortestPaths {
private:
  const AdjacencyList adjacency_list;
  vector<int> distances;
  vector<int> parents;
  // undiscovered nodes will have -1 as distance / parent
  static constexpr int UNKNOWN = -1;
public:
  ShortestPaths(AdjacencyList &_adjacency_list)
    : adjacency_list {_adjacency_list}
    , distances {vector<int>(_adjacency_list.size(), UNKNOWN)}
    , parents {vector<int>(_adjacency_list.size(), UNKNOWN)}
  {}

  void bfs(int start) {
    this->distances.assign(this->distances.size(), UNKNOWN);
    this->parents.assign(this->parents.size(), UNKNOWN);
    queue<int> unexplored;
    unexplored.push(start);
    distances[start] = 0;
    parents[start] = start;

    while (!unexplored.empty()) {
      int u = unexplored.front();
      unexplored.pop();
      for (int v : adjacency_list[u]) {
        if (parents[v] == UNKNOWN) {
          parents[v] = u;
          distances[v] = distances[u] + 1;
          unexplored.push(v);
        }
      }
    }
  }

  vector<int> shortest_path(int from, int to) {
    bfs(from);
    if (parents[to] == UNKNOWN) {
      throw NoPathExistsException();
    }
    vector<int> path;
    path.push_back(to);
    int curr = to;
    while (curr != from) {
      curr = parents[curr];
      path.push_back(curr);
    }
    reverse(path.begin(),path.end());
    return path;
  }
};

int main() {
  int n = 6;
  AdjacencyList adjacencyList(n);
  vector<pair<int, int>> edges {{0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 0}, {3, 4}, {4, 3}, {4, 5}};
  for (auto [u, v] : edges) {
    adjacencyList[u].push_back(v);
  }

  ShortestPaths shortestPaths(adjacencyList);
  vector<int> path04 = shortestPaths.shortest_path(0, 4);
  cout << "Shortest path from 0 to 4: ";
  for (int u : path04) {
    cout << u << " ";
  }
  cout << endl;
}
