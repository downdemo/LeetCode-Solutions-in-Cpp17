/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) {
      return nullptr;
    }
    Node* cur = head;
    while (cur) {
      Node* t = new Node(cur->val);
      t->next = cur->next;
      cur->next = t;
      cur = t->next;
    }

    cur = head;
    while (cur) {
      if (cur->random) {
        cur->next->random = cur->random->next;
      }
      cur = cur->next->next;
    }

    cur = head;
    Node* dummy = new Node(-1);
    Node* t = dummy;
    while (cur) {
      t->next = cur->next;
      t = t->next;
      cur->next = cur->next->next;
      cur = cur->next;
    }
    return dummy->next;
  }
};
