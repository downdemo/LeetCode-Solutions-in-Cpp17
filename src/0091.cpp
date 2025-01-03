class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty() || s[0] == '0') {
      return 0;
    }
    vector<int> dp(s.size());
    dp[0] = 1;
    for (int i = 1; i < dp.size(); ++i) {
      dp[i] = s[i] == '0' ? 0 : dp[i - 1];
      if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
        dp[i] += i >= 2 ? dp[i - 2] : 1;
      }
    }
    return dp.back();
  }
};
