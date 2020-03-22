class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    return nth(nums, 0, nums.size() - 1, nums.size() - k);
  }

  int nth(vector<int>& nums, int l, int r, int k) {
    int n = partition(nums, l, r);
    if (n == k) {
      return nums[n];
    }
    return n > k ? nth(nums, l, n - 1, k) : nth(nums, n + 1, r, k);
  }

  int partition(vector<int>& nums, int l, int r) {
    int i = l;
    int j = r;
    while (i < j) {
      while (i < j && nums[j] >= nums[l]) {
        --j;
      }
      while (i < j && nums[i] <= nums[l]) {
        ++i;
      }
      if (i < j) {
        swap(nums[i], nums[j]);
      }
    }
    swap(nums[i], nums[l]);
    return i;
  }
};
