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
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    if (!root) {
      return res;
    }
    queue<Node*> q;
    q.emplace(root);
    while (!q.empty()) {
      vector<int> line;
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        Node* t = q.front();
        q.pop();
        line.emplace_back(t->val);
        for (auto& x : t->children) {
          q.emplace(x);
        }
      }
      res.emplace_back(line);
    }
    return res;
  }
};
