class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 1;
    int r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] < nums[0]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l != nums.size() ? nums[l] : nums[0];
  }
};
