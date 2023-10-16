#include <vector>
#include <string>

#include "llist_node.cpp"

class LList {
public:
  Node *head = new Node(0);
  LList() { head = nullptr; }
  LList(Node *node) { head = node; }
  void insert_at_head(Node *node) {
    if (head != nullptr) {
      node->next = head;
      head = node;
    } else
      head = node;
  }

  void make_llist(std::vector<int>& vec) {
    for (int i = vec.size() -1; i >= 0; i--) {
      Node *node = new Node(vec[i]);
      insert_at_head(node);
    }
  }
  
  std::string to_string() {
    std::string result = "[";
    Node *temp = head;
    while (temp != nullptr) {
      result += std::to_string(temp->data);
      temp = temp->next;
      if (temp != nullptr) result += ",";
    }
    result += "]";
    return result;
  }
};
