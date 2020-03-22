class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    if (dungeon.empty() || dungeon[0].empty()) {
      return 1;
    }
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp.back().back() = max(1, 1 - dungeon.back().back());
    for (int i = m - 2; i >= 0; --i) {
      dp[i].back() = max(1, dp[i + 1].back() - dungeon[i].back());
    }
    for (int i = n - 2; i >= 0; --i) {
      dp.back()[i] = max(1, dp.back()[i + 1] - dungeon.back()[i]);
    }
    for (int i = m - 2; i >= 0; --i) {
      for (int j = n - 2; j >= 0; --j) {
        int tmp = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
        dp[i][j] = max(1, tmp);
      }
    }
    return dp[0][0];
  }
};
