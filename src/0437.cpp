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
  int pathSum(TreeNode* root, int sum) {
    if (!root) {
      return 0;
    }
    int res = 0;
    dfs(root, res, sum);
    res += pathSum(root->left, sum);
    res += pathSum(root->right, sum);
    return res;
  }

  void dfs(TreeNode* root, int& res, int n) {
    if (!root) {
      return;
    }
    if (root->val == n) {
      ++res;
    }
    dfs(root->left, res, n - root->val);
    dfs(root->right, res, n - root->val);
  }
};
