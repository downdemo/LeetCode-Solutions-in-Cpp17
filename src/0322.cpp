class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (coins.empty()) {
      return -1;
    }
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (auto& x : coins) {
        if (i >= x) {
          dp[i] = min(dp[i], dp[i - x] + 1);
        }
      }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};