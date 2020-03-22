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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* t = root;
    while (t || !s.empty()) {
      while (t) {
        res.emplace_back(t->val);
        s.emplace(t);
        t = t->left;
      }
      t = s.top();
      s.pop();
      t = t->right;
    }
    return res;
  }
};
