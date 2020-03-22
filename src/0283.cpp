class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int l = 0;
    int cur = 0;
    while (cur < nums.size()) {
      if (nums[cur] == 0) {
        ++cur;
      } else {
        nums[l++] = nums[cur++];
      }
    }
    for (int i = l; i < nums.size(); ++i) {
      nums[i] = 0;
    }
  }
};
