class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      int t = target - nums[i];
      if (m.count(t)) {
        return {i, m[t]};
      }
      m.emplace(nums[i], i);
    }
    return {-1, -1};
  }
};
