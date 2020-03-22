class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    do {
      res.emplace_back(nums);
      nextPermutation(nums);
    } while (!is_sorted(nums.begin(), nums.end()));
    return res;
  }

  void nextPermutation(vector<int>& nums) {
    if (nums.size() <= 1) {
      return;
    }
    for (int i = nums.size() - 1; i > 0; --i) {
      if (nums[i - 1] < nums[i]) {
        sort(nums.begin() + i, nums.end());
        for (int j = i; j < nums.size(); ++j) {
          if (nums[j] > nums[i - 1]) {
            swap(nums[i - 1], nums[j]);
            return;
          }
        }
      }
    }
    reverse(nums.begin(), nums.end());
  }
};
