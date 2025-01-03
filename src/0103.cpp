/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
      return res;
    }
    deque<TreeNode*> q;
    q.emplace_back(root);
    bool seq = true;
    while (!q.empty()) {
      int n = q.size();
      vector<int> line;
      while (n--) {
        if (seq) {
          TreeNode* t = q.front();
          q.pop_front();
          line.emplace_back(t->val);
          if (t->left) {
            q.emplace_back(t->left);
          }
          if (t->right) {
            q.emplace_back(t->right);
          }
        } else {
          TreeNode* t = q.back();
          q.pop_back();
          line.emplace_back(t->val);
          if (t->right) {
            q.emplace_front(t->right);
          }
          if (t->left) {
            q.emplace_front(t->left);
          }
        }
      }
      seq = !seq;
      res.emplace_back(line);
    }
    return res;
  }
};
