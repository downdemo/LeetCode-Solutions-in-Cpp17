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
  vector<int> postorder(Node* root) {
    vector<int> res;
    if (!root) {
      return res;
    }
    stack<pair<Node*, int>> s;
    s.emplace(root, 0);
    while (!s.empty()) {
      auto& [t, i] = s.top();
      if (i == t->children.size()) {
        res.emplace_back(t->val);
        s.pop();
      } else {
        s.emplace(t->children[i++], 0);
      }
    }
    return res;
  }
};
