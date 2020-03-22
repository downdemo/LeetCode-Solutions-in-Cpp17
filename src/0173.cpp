/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    TreeNode* t = root;
    while (t) {
      s.emplace(t);
      t = t->left;
    }
  }

  /** @return the next smallest number */
  int next() {
    TreeNode* t = s.top();
    int res = t->val;
    s.pop();
    t = t->right;
    while (t) {
      s.emplace(t);
      t = t->left;
    }
    return res;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !s.empty(); }

 private:
  stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
