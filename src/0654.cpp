/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return constructMaximumBinaryTree(nums, 0, nums.size());
  }

  TreeNode* constructMaximumBinaryTree(vector<int>& nums, int l, int r) {
    if (l == r) {
      return nullptr;
    }
    int max_index =
        max_element(nums.begin() + l, nums.begin() + r) - nums.begin();
    TreeNode* root = new TreeNode(nums[max_index]);
    root->left = constructMaximumBinaryTree(nums, l, max_index);
    root->right = constructMaximumBinaryTree(nums, max_index + 1, r);
    return root;
  }
};
