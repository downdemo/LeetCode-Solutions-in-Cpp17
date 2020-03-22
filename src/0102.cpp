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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
      return res;
    }
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty()) {
      vector<int> line;
      int n = q.size();
      while (n--) {
        TreeNode* t = q.front();
        q.pop();
        line.emplace_back(t->val);
        if (t->left) {
          q.emplace(t->left);
        }
        if (t->right) {
          q.emplace(t->right);
        }
      }
      res.emplace_back(line);
    }
    return res;
  }
};
