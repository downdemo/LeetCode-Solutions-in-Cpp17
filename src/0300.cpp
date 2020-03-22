class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    vector<int> v{nums[0]};
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > v.back()) {
        v.emplace_back(nums[i]);
      } else {
        *lower_bound(v.begin(), v.end(), nums[i]) = nums[i];
      }
    }
    return v.size();
  }
};
