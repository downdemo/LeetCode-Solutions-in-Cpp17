class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> dp;
    if (numRows == 0) {
      return dp;
    }
    dp.emplace_back(vector<int>{1});
    if (numRows == 1) {
      return dp
    };
    dp.emplace_back(vector<int>{1, 1});
    if (numRows == 2) {
      return dp;
    }
    for (int i = 2; i < numRows; ++i) {
      vector<int> t(i + 1);
      t.back() = 1;
      t.front() = 1;
      for (int j = 1; j < t.size() - 1; ++j) {
        t[j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
      dp.emplace_back(t);
    }
    return dp;
  }
};
