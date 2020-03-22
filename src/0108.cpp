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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfs(nums, 0, nums.size());
  }

  TreeNode* dfs(vector<int>& nums, int l, int r) {
    if (l >= r) {
      return nullptr;
    }
    int m = l + (r - l) / 2;
    TreeNode* t = new TreeNode(nums[m]);
    t->left = dfs(nums, l, m);
    t->right = dfs(nums, m + 1, r);
    return t;
  }
};
