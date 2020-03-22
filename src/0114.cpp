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
  void flatten(TreeNode* root) {
    while (root) {
      if (root->left) {
        TreeNode* t = getLeftMostRight(root);
        if (t) {
          t->right = root->right;
          root->right = root->left;
          root->left = nullptr;
        }
      }
      root = root->right;
    }
  }

  TreeNode* getLeftMostRight(TreeNode* root) {
    if (!root || !root->left) {
      return nullptr;
    }
    TreeNode* t = root->left;
    while (t->right) {
      t = t->right;
    }
    return t;
  }
};
