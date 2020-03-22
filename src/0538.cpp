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
  TreeNode* convertBST(TreeNode* root) {
    int pre = 0;
    dfs(root, pre);
    return root;
  }

  void dfs(TreeNode* root, int& pre) {
    if (!root) {
      return;
    }
    dfs(root->right, pre);
    root->val += pre;
    pre = root->val;
    dfs(root->left, pre);
  }
};
