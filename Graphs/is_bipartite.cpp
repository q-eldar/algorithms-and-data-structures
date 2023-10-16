#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using AdjacentList = vector<vector<int>>;
enum class NodeState {UNVISITED, RED, BLUE};

class IsBipartite {
private:
  AdjacentList adj_list;  
  vector<NodeState> node_state;
public:
  IsBipartite(AdjacentList _adj_list)
    : adj_list {_adj_list}
    , node_state {vector<NodeState>(adj_list.size(), NodeState::UNVISITED)}
  {}

  bool is_bipartite() {
    for (int u = 0; u < adj_list.size(); u++)
      if (node_states[u] == NodeState::UNVISITED)
        dfs(u, true);

    for (int u = 0; u < adj_list.size(); u++)
      for (int v : adj_list[u])
        if (node_states[u] == node_states[v])
          return false;

    return true;
  }
  
  void dfs(int u, bool red) {
    node_states[u] = red ? NodeState::RED : NodeState::BLUE;

    for (int b : adj_list[u])
      if (node_states[v] == NodeState::UNVISITED)
        dfs(v, !red);
  }
};

int main() {
  int n = 7;
  AdjacentList adj_list(n);
  vector<pair<int, int>> edges {{1,2}, {3,2}, {5,2}, {4,3}, {4,5}, {5,6}};
  for (auto [u, v] : edges) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  IsBipartite is_bipartite(adj_list);
}
