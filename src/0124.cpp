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
  int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    dfs(root, res);
    return res;
  }

  int dfs(TreeNode* root, int& res) {
    if (!root) {
      return 0;
    }
    int l = max(dfs(root->left, res), 0);
    int r = max(dfs(root->right, res), 0);
    res = max(res, l + r + root->val);
    return root->val + max(l, r);
  }
};
