class Solution {
 public:
  bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
    dp[0][0] = true;
    for (int i = 2; i < dp[0].size(); i += 2) {
      if (p[i - 1] != '*') {
        break;
      }
      dp[0][i] = true;
    }
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < p.size(); ++j) {
        if (s[i] == p[j] || p[j] == '.') {
          dp[i + 1][j + 1] = dp[i][j];
        } else if (p[j] == '*') {
          dp[i + 1][j + 1] = dp[i + 1][j - 1];
          if (s[i] == p[j - 1] || p[j - 1] == '.') {
            dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[i + 1][j] || dp[i][j + 1];
          }
        }
      }
    }
    return dp[s.size()][p.size()];
  }
};
