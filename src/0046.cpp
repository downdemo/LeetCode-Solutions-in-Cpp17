class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    dfs(res, nums, 0);
    return res;
  }

  void dfs(vector<vector<int>>& res, vector<int>& nums, int n) {
    if (n == nums.size()) {
      res.emplace_back(nums);
      return;
    }
    for (int i = n; i < nums.size(); ++i) {
      swap(nums[i], nums[n]);
      dfs(res, nums, n + 1);
      swap(nums[i], nums[n]);
    }
  }
};
