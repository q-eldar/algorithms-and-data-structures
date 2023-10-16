#include <iostream>

#include "llist.cpp"

using namespace std;

Node *remove_nth_last_node(Node *head, int nth) {
  EduLinkedListNode* right = head;
  EduLinkedListNode* left = head;

  while (right->next && nth--)
    right = right->next;
  
  while(right->next) {
    right = right->next;
    left = left->next;
  }

  EduLinkedListNode *to_delete = nullptr;
    
  if (left == head) {
    EduLinkedListNode *to_delete = head;
    head = head->next;
  } else {
    left->next = left->next->next;
    EduLinkedListNode *to_delete = left->next;
  }
  if (to_delete != nullptr)
    delete to_delete;
  
  return head;
} 

int main() {
  vector<int> nums{10, 20, 30, 40, 50, 60};
  int nth = 6;
  LList l;
  l.make_llist(nums);
  cout << l.to_string() << endl;
  Node* head = remove_nth_last_node(l.head, nth);

  while (head) {
    cout << head->data << ", ";
    head = head->next;
  }
  cout << endl;
}
