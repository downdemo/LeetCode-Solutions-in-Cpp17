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
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* t = root;
    TreeNode* last = root;
    while (t || !s.empty()) {
      while (t) {
        s.emplace(t);
        t = t->left;
      }
      t = s.top();
      if (!t->right || t->right == last) {
        s.pop();
        res.emplace_back(t->val);
        last = t;
        t = nullptr;
      } else {
        t = t->right;
      }
    }
    return res;
  }
};
