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
  int kthSmallest(TreeNode* root, int k) {
    if (!root) {
      return 0;
    }
    int res = 0;
    stack<TreeNode*> s;
    TreeNode* t = root;
    while (t || !s.empty()) {
      while (t) {
        s.emplace(t);
        t = t->left;
      }
      t = s.top();
      s.pop();
      if (k-- == 1) {
        res = t->val;
        break;
      }
      t = t->right;
    }
    return res;
  }
};
