class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
      dp[i][0] = i;
    }
    for (int i = 1; i <= n; ++i) {
      dp[0][i] = i;
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        int r = (word1[i - 1] == word2[j - 1]) ? dp[i - 1][j - 1]
                                               : dp[i - 1][j - 1] + 1;
        int d = dp[i - 1][j] + 1;
        int u = dp[i][j - 1] + 1;
        dp[i][j] = min({d, r, u});
      }
    }
    return dp[m][n];
  }
};
