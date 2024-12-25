class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> t;
    dfs(res, t, candidates, 0, target);
    return res;
  }

  void dfs(vector<vector<int>>& res, vector<int>& t, vector<int>& candidates,
           int n, int target) {
    if (!target) {
      res.emplace_back(t);
      return;
    }
    for (int i = n; i < candidates.size(); ++i) {
      if (target - candidates[i] >= 0) {
        t.emplace_back(candidates[i]);
        dfs(res, t, candidates, i, target - candidates[i]);
        t.pop_back();
      }
    }
  }
};
