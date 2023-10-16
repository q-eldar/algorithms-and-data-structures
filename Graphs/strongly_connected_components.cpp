// directed graph is called stronngly connected when any pair of nodes can reach
// each other
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using AdjacentList = vector<vector<int>>;
enum class NodeState {UNVISITED, IN_PROGRESS, FINISHED};

class StronglyConnectedComponents {
private:
  AdjacentList adj_list;
  vector<NodeState> node_states;
  vector<int> finish_order;
  vector<vector<int>> scc;

  void transpose() {
    AdjacentList tmp = AdjacentList(adj_list.size());
    for (int u = 0; u < adj_list.size(); u++)
      for (int v : adj_list[u])
        tmp[v].push_back(u);

    adj_list = tmp;
  }
public:
  StronglyConnectedComponents(AdjacentList _adj_list)
    : adj_list {_adj_list}
    , node_states {vector<NodeState>(adj_list.size(), NodeState::UNVISITED)}
  {}

  vector<vector<int>> compute_scc() {
    for (int u = 0; u < adj_list.size(); u++) {
      if (node_states[u] == NodeState::UNVISITED)
        dfs(u);
    }

    vector<int> traverse_order(finish_order.rbegin(), finish_order.rend());
    transpose();
    fill(node_states.begin(), node_states.end(), NodeState::UNVISITED);
    finish_order.clear();

    for (int u : traverse_order) {
      if (node_states[u] == NodeState::UNVISITED) {
        dfs(u);
        scc.push_back(finish_order);
        finish_order.clear();
      }
    }

    transpose();
    fill(node_states.begin(), node_states.end(), NodeState::UNVISITED);
    return scc;
  }

  void dfs(int u) {
    node_states[u] = NodeState::IN_PROGRESS;
    for (int v : adj_list[u]) {
      switch (node_states[v]) {
      case NodeState::UNVISITED: dfs(v); break;
      case NodeState::IN_PROGRESS: break;
      case NodeState::FINISHED: break;
      }
    }
    node_states[u] = NodeState::FINISHED;
    finish_order.push_back(u);
  }
}; 

int main() {
  int n = 7;
  AdjacentList adjacencyList(n);
  vector<pair<int, int>> edges {{0, 1}, {0, 6}, {1, 4}, {2, 3}, {2, 5}, {3, 2}, {3, 5}, {4, 0}, {4, 5}, {6, 4}};
  for (auto [u, v] : edges) {
    adjacencyList[u].push_back(v);
  }

  StronglyConnectedComponents components(adjacencyList);
  auto scc = components.compute_scc();
  cout << "Strongly connected components:" << endl;
  for (auto component : scc) {
    for (int u : component) {
      cout << u << " ";
    }
    cout << endl;
  }
}
