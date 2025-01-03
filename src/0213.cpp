class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int sz = nums.size();
    if (sz == 1) {
      return nums[0];
    }
    if (sz == 2) {
      return max(nums[0], nums[1]);
    }
    vector<int> dp_no_first(sz);
    vector<int> dp_no_last(sz - 1);
    dp_no_first[1] = nums[1];
    dp_no_first[2] = max(nums[1], nums[2]);
    dp_no_last[0] = nums[0];
    dp_no_last[1] = max(nums[0], nums[1]);
    for (int i = 3; i < dp_no_first.size(); ++i) {
      dp_no_first[i] = max(dp_no_first[i - 1], dp_no_first[i - 2] + nums[i]);
    }
    for (int i = 2; i < dp_no_last.size(); ++i) {
      dp_no_last[i] = max(dp_no_last[i - 1], dp_no_last[i - 2] + nums[i]);
    }
    return max(dp_no_first.back(), dp_no_last.back());
  }
};
