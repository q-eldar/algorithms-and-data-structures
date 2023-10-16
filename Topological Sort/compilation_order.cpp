#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

void print_graph(map<char, vector<char>> &graph) {
  for (auto& [key, vi] : graph) {
    cout << key << " -> ";
    for (auto i : vi)
      cout << i << " ";
    cout << endl;
  }  
}

void dfs(map<char, vector<char>> &graph, set<char> &visited,
         vector<char> &top_order, const char v) {
  visited.insert(v);
  cout << v << " ";
  for (const auto& node : graph[v])
    if (visited.find(node) == visited.end()) {
      dfs(graph, visited, top_order, node);
    }
  top_order.push_back(v);
}

auto compilation_order(vector<vector<char>> &dependencies) {
  map<char, vector<char>> graph;
  
  for (const auto& vc : dependencies) {
    const char to = vc[0];
    const char from = vc[1];
    graph[from].push_back(to);
  }

  print_graph(graph);
  set<char> visited;
  vector<char> top_order;
  for (const auto& [key, vi] : graph) {
    if (visited.find(key) == visited.end()) {
      dfs(graph, visited, top_order, key);
      cout << endl;
    }
  }
  if (graph.size() != top_order.size())
    return vector<char>{};
  reverse(top_order.begin(), top_order.end());
  return top_order;
}

int main() {
  vector<vector<char>> dependencies =
    {{'A', 'B'},
     {'B', 'A'}};
  auto top_order = compilation_order(dependencies);
  
  for (auto v : top_order)
    cout << v << " ";
  cout << endl;
}
