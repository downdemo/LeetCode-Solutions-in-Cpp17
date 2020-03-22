class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    nums.emplace(nums.begin(), 1);
    nums.emplace_back(1);
    int sz = nums.size();
    vector<vector<int>> dp(sz, vector<int>(sz));
    for (int n = 2; n < sz; ++n) {
      for (int i = 0; i + n < sz; ++i) {
        for (int j = i + 1; j < i + n; ++j) {
          int t = dp[i][j] + dp[j][i + n] + nums[i] * nums[j] * nums[i + n];
          dp[i][i + n] = max(dp[i][i + n], t);
        }
      }
    }
    return dp[0][sz - 1];
  }
};
