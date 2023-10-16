#include <iostream>
#include <vector>
using namespace std;

using AdjacencyList = vector<vector<int>>;

enum class NodeState {UNVISITED, IN_PROGRESS, FINISHED};

class CycleDetector {
private:
  const AdjacencyList adjacency_list;
  vector<NodeState> node_states;
  bool cycle_found = false;
public:
  CycleDetector(AdjacencyList _adjacency_list)
    : adjacency_list(_adjacency_list)
    , node_states{vector<NodeState>(adjacency_list.size(), NodeState::UNVISITED)} {}
  
  void dfs(int u) {
    node_states[u] = NodeState::IN_PROGRESS;

    for (int v : adjacency_list[u]) {
      switch (node_states[v]) {
      case NodeState::UNVISITED: dfs(v); break;
      case NodeState::IN_PROGRESS: cycle_found = true; break;
      case NodeState::FINISHED: break;
      }
    }
    node_states[u] = NodeState::FINISHED;
  }

  bool contains_cycle() {
    for (int u = 0; u < (int)adjacency_list.size(); u++) {
      if (node_states[u] == NodeState::FINISHED) continue;
      dfs(u);
    }
    return cycle_found;
  }
};


int main() {
  int n = 5;
  AdjacencyList adjacencyList(n);
  vector<pair<int, int>> edges {{0, 1}, {0, 2}, {1, 3}, {2, 1}, {3, 0}, {4, 1}};
  for (auto [u, v] : edges) {
    adjacencyList[u].push_back(v);
  }

  CycleDetector cycleDetector(adjacencyList);
  cout << "Contains cycle: " << cycleDetector.contains_cycle() << endl;
}
