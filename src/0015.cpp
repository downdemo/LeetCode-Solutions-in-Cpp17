class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int sz = nums.size();
    if (sz < 3) return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < sz - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int l = i + 1;
      int r = sz - 1;
      int target = -nums[i];
      while (l < r) {
        if (nums[l] + nums[r] == target) {
          while (l < r && nums[l] == nums[l + 1]) {
            ++l;
          }
          while (l < r && nums[r] == nums[r - 1]) {
            --r;
          }
          res.emplace_back(vector<int>{nums[i], nums[l], nums[r]});
          ++l;
          --r;
        } else if (nums[l] + nums[r] > target) {
          --r;
        } else {
          ++l;
        }
      }
    }
    return res;
  }
};
