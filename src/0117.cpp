/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) {
      return nullptr;
    }
    queue<Node*> q;
    q.emplace(root);
    while (!q.empty()) {
      int n = q.size();
      Node* pre = nullptr;
      while (n--) {
        Node* cur = q.front();
        q.pop();
        if (!pre) {
          pre = cur;
        } else {
          pre->next = cur;
          pre = cur;
        }
        if (cur->left) {
          q.emplace(cur->left);
        }
        if (cur->right) {
          q.emplace(cur->right);
        }
      }
    }
    return root;
  }
};
