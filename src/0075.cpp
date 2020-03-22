class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int cur = 0;
    int l = 0;
    int r = nums.size();
    while (cur < r) {
      if (nums[cur] == 0) {
        swap(nums[cur++], nums[l++]);
      } else if (nums[cur] == 2) {
        swap(nums[cur], nums[--r]);
      } else {
        ++cur;
      }
    }
  }
};
