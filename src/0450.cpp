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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
      return nullptr;
    }
    if (key > root->val) {
      root->right = deleteNode(root->right, key);
      return root;
    }
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
      return root;
    }
    if (!root->left || !root->right) {
      TreeNode* t = root->left ? root->left : root->right;
      delete root;
      root = nullptr;
      return t;
    }
    TreeNode* t = root->right;
    while (t->left) {
      t = t->left;
    }
    swap(root->val, t->val);
    root->right = deleteNode(root->right, key);
    return root;
  }
};
