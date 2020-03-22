class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) {
      return -1;
    }
    int l = 0;
    int r = nums.size();
    while (l != r) {
      int m = l + (r - l) / 2;
      if (target == nums[m]) {
        return m;
      }
      if (nums[m] >= nums[l]) {
        if (target < nums[m] && target >= nums[l]) {
          r = m;
        } else {
          l = m + 1;
        }
      } else {
        if (target > nums[m] && target <= nums[r - 1]) {
          l = m + 1;
        } else {
          r = m;
        }
      }
    }
    return -1;
  }
};
