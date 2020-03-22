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
  int rob(TreeNode* root) {
    auto [a, b] = dfs(root);
    return max(a, b);
  }

  pair<int, int> dfs(TreeNode* root) {
    if (!root) {
      return {0, 0};
    }
    auto [l1, l2] = dfs(root->left);
    auto [r1, r2] = dfs(root->right);
    int a = root->val + l2 + r2;
    int b = max(l1, l2) + max(r1, r2);
    return {a, b};
  }
};
