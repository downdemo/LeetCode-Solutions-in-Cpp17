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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* t = root;
    while (t || !s.empty()) {
      while (t) {
        s.emplace(t);
        t = t->left;
      }
      t = s.top();
      s.pop();
      res.emplace_back(t->val);
      t = t->right;
    }
    return res;
  }
};
