class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> t;
    dfs(res, t, nums, 0);
    return res;
  }

  void dfs(vector<vector<int>>& res, vector<int>& t, vector<int>& nums, int n) {
    res.emplace_back(t);
    for (int i = n; i < nums.size(); ++i) {
      t.emplace_back(nums[i]);
      dfs(res, t, nums, i + 1);
      t.pop_back();
    }
  }
};
