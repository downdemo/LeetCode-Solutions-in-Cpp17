class Solution {
 public:
  vector<int> sortArray(vector<int> &nums) {
    heapSort(nums);
    return nums;
  }

  void heapSort(vector<int> &nums) {
    for (int i = nums.size() / 2 - 1; i >= 0; --i) {
      adjustHeap(nums, i, nums.size());
    }
    for (int i = nums.size() - 1; i > 0; --i) {
      swap(nums[0], nums[i]);
      adjustHeap(nums, 0, i);
    }
  }

  void adjustHeap(vector<int> &nums, int i, int m) {
    while (2 * i + 1 < m) {
      int l = 2 * i + 1;
      int r = 2 * i + 2;
      int mx = r < m && nums[l] < nums[r] ? r : l;
      if (nums[i] < nums[mx]) {
        swap(nums[i], nums[mx]);
        i = mx;
      } else {
        break;
      }
    }
  }
};
