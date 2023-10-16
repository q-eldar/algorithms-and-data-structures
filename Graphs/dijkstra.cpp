// Dijkstra is single source shortest path algorithm in weighted graph
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

using NodeDistance = pair<int,int>;
using AdjacencyList = vector<vector<NodeDistance>>;

class NoPathExistsException: public runtime_error {
public:
  NoPathExistsException() : runtime_error("No path exists between the nodes") {}
};

class Dijkstra {
private:
  AdjacencyList adj_list;
  vector<int> distances;
  vector<int> parents;
  static constexpr int UNKNOWN = -1;

  void run_dijkstra(int start) {
    auto comparator = [](NodeDistance p1, NodeDistance p2) {
      return p1.second > p2.second || (p1.second == p2.second && p1.first > p2.first);
    };

    priority_queue<NodeDistance, vector<NodeDistance>, decltype(comparator)> distance_queue(comparator);
    vector<bool> visited(adj_list.size(), false);

    distance_queue.push({start,0});
    parents[start] = start;
    distances[start] = 0;

    while(!distance_queue.empty()) {
      auto [u, distance] = distance_queue.top();
      distance_queue.pop();
      if (visited[u]) continue;
      visited[u] = true;

      for (auto [v, weight] : adj_list[u]) {
        if (distances[v] == UNKNOWN || distances[u] + weight < distances[v]) {
          distances[v] = distances[u] + weight;
          parents[v] = u;
          distance_queue.push({v, distances[v]});
        }
      }
    }
  }
public:
  Dijkstra(AdjacencyList &_adj_list)
    : adj_list(_adj_list)
    , distances {vector<int>(adj_list.size(), UNKNOWN)}
    , parents {vector<int>(adj_list.size(), UNKNOWN)}
  {}

  pair<int, vector<int>> compute_shortest_path(int start, int end) {
    run_dijkstra(start);
    if (parents[end] == UNKNOWN)
      throw NoPathExistsException();

    int distance = distances[end];
    
    // reconstruct the path from parents
    vector<int> path;
    path.push_back(end);
    int current = end;
    while(current != start) {
      current = parents[current];
      path.push_back(current);
    }

    std::reverse(path.begin(), path.end());
    return make_pair(distance, path);
  }
};

int main() {
  int n = 5;
  AdjacencyList adjacencyList(n);
  vector<tuple<int, int, int>> edges {
    make_tuple(0, 1, 6),
    make_tuple(0, 2, 10),
    make_tuple(0, 3, 4),
    make_tuple(1, 0, 2),
    make_tuple(1, 2, 3),
    make_tuple(1, 4, 5),
    make_tuple(3, 1, 1),
    make_tuple(3, 4, 2),
    make_tuple(4, 2, 1)
  };
  for (auto [u, v, w] : edges) {
    adjacencyList[u].push_back(make_pair(v, w));
  }

  Dijkstra dijkstra(adjacencyList);
  auto [distance, path02] = dijkstra.compute_shortest_path(0, 2);
  cout << "Shortest path from 0 to 2: ";
  for (int u : path02) {
    cout << u << " ";
  }
  cout << endl << "Length of the path: " << distance;
}
