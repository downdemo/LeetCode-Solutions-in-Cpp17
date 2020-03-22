class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    if (nums.empty()) {
      return 1;
    }
    int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
      while (nums[i] != i + 1 && nums[i] - 1 >= 0 && nums[i] - 1 < sz) {
        if (nums[i] == nums[nums[i] - 1]) {
          break;
        }
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
    for (int i = 0; i < sz; ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return sz + 1;
  }
};
