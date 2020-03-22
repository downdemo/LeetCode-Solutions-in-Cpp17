class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    if (nums.empty()) {
      return;
    }
    int sz = nums.size();
    nth_element(nums.begin(), nums.begin() + sz / 2, nums.end());
    int m = nums[sz / 2];
#define a(i) nums[(2 * (i) + 1) % (sz | 1)]
    int i = 0;
    int j = 0;
    int k = sz - 1;
    while (j <= k) {
      if (a(j) > m) {
        swap(a(i), a(j));
        ++i;
        ++j;
      } else if (a(j) < m) {
        swap(a(j), a(k));
        --k;
      } else {
        ++j;
      }
    }
  }
};
