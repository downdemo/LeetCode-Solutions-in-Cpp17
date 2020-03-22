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
  int diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    depth(root, res);
    return res;
  }

  int depth(TreeNode* root, int& res) {
    if (!root) {
      return 0;
    }
    int l = depth(root->left, res);
    int r = depth(root->right, res);
    res = max(res, l + r);
    return 1 + max(l, r);
  }
};
