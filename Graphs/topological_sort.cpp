#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
using namespace std;

using AdjacencyList = vector<vector<int>>;
enum class NodeState {UNVISITED, IN_PROGRESS, FINISHED};

class GraphIsCyclicException : public std::runtime_error{
public:
  GraphIsCyclicException() : runtime_error("The graph contains a cycle.") {}
};

class TopologicalSort {
private:
  const AdjacencyList adj_list;
  vector<NodeState> node_states;
  vector<int> finish_order;
public:
  TopologicalSort(AdjacencyList _adj_list)
    : adj_list {_adj_list}
    , node_states {vector<NodeState>(adj_list.size(), NodeState::UNVISITED)}
  {}

  void dfs(int u) {
    node_states[u] = NodeState::IN_PROGRESS;

    for (int v : adj_list[u]) {
      switch (node_states[v]) {
      case NodeState::UNVISITED : dfs(v); break;
      case NodeState::IN_PROGRESS: throw GraphIsCyclicException(); break;
      case NodeState::FINISHED: break;
      }
    }
    node_states[u] = NodeState::FINISHED;
    finish_order.push_back(u);
  }

  vector<int> computeTopologicalSort() {
    for (int u = 0; u < (int)this->adj_list.size(); ++u) {
      if (this->node_states[u] == NodeState::FINISHED) continue;
      dfs(u);
    }
    reverse(this->finish_order.begin(), this->finish_order.end());
    return this->finish_order;
  }  
};

int main() {
  int n = 5;
  AdjacencyList adjacencyList(n);
  vector<pair<int, int>> edges {{0, 1}, {0, 4}, {2, 4}, {2, 1}, {3, 0}, {4, 1}};
  for (auto [u, v] : edges) {
    adjacencyList[u].push_back(v);
  }

  TopologicalSort topologicalSort(adjacencyList);
  vector<int> topSort = topologicalSort.computeTopologicalSort();
  cout << "Topological sort:";
  for (int u : topSort) {
    cout << " " << u;
  }
}
