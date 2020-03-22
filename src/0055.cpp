class Solution {
 public:
  bool canJump(vector<int>& nums) {
    if (nums.empty()) {
      return false;
    }
    if (nums.size() == 1 && nums[0] >= 0) {
      return true;
    }
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    if (dp[0] == 0) {
      return false;
    }
    for (int i = 1; i < dp.size(); ++i) {
      dp[i] = max(dp[i - 1] - 1, nums[i - 1]);
      if (dp[i] == 0) {
        return false;
      }
    }
    return true;
  }
};
