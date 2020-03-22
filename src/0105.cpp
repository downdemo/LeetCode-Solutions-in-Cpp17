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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
  }

  TreeNode* buildTree(vector<int>& preorder, int l1, int r1,
                      vector<int>& inorder, int l2, int r2) {
    if (l1 >= r1 || l2 >= r2) {
      return nullptr;
    }
    TreeNode* t = new TreeNode(preorder[l1]);
    int pos = find(inorder.begin() + l2, inorder.begin() + r2, preorder[l1]) -
              inorder.begin();
    t->left = buildTree(preorder, l1 + 1, l1 + 1 + pos - l2, inorder, l2, pos);
    t->right = buildTree(preorder, l1 + 1 + pos - l2, r1, inorder, pos + 1, r2);
    return t;
  }
};
