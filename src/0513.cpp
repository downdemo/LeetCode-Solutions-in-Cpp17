/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.emplace(root);
    int res;
    while (!q.empty()) {
      int n = q.size();
      res = q.front()->val;
      for (int i = 0; i < n; ++i) {
        TreeNode* t = q.front();
        q.pop();
        if (t->left) {
          q.emplace(t->left);
        }
        if (t->right) {
          q.emplace(t->right);
        }
      }
    }
    return res;
  }
};
