class Solution {
 public:
  int longestValidParentheses(string s) {
    int res = 0;
    vector<int> dp(s.size());
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          if (i == 1) {
            dp[i] = 2;
          } else {
            dp[i] = dp[i - 2] + 2;
          }
        } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
          if (i - dp[i - 1] < 2) {
            dp[i] = dp[i - 1] + 2;
          } else {
            dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
          }
        }
        res = max(res, dp[i]);
      }
    }
    return res;
  }
};
