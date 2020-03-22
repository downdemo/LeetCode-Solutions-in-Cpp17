/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
 public:
  vector<int> preorder(Node* root) {
    vector<int> res;
    if (!root) {
      return res;
    }
    stack<Node*> s;
    s.emplace(root);
    while (!s.empty()) {
      Node* t = s.top();
      res.emplace_back(t->val);
      s.pop();
      for (auto it = t->children.rbegin(); it != t->children.rend(); ++it) {
        s.emplace(*it);
      }
    }
    return res;
  }
};
