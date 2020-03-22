class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size() + nums2.size();
    int x = (n + 1) / 2;
    int y = (n + 2) / 2;
    return (findK(nums1, nums2, 0, 0, x) + findK(nums1, nums2, 0, 0, y)) / 2.0;
  }

  double findK(vector<int>& nums1, vector<int>& nums2, int a, int b, int k) {
    if (a >= nums1.size()) {
      return nums2[b + k - 1];
    }
    if (b >= nums2.size()) {
      return nums1[a + k - 1];
    }
    if (k == 1) {
      return min(nums1[a], nums2[b]);
    }
    int x = a + k / 2 - 1;
    int y = b + k / 2 - 1;
    int m1 = x < nums1.size() ? nums1[x] : INT_MAX;
    int m2 = y < nums2.size() ? nums2[y] : INT_MAX;
    return m1 < m2 ? findK(nums1, nums2, x + 1, b, k - k / 2)
                   : findK(nums1, nums2, a, y + 1, k - k / 2);
  }
};
