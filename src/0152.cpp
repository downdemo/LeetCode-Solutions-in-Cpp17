class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int sz = nums.size();
    vector<int> dpMax(sz + 1, INT_MIN);
    vector<int> dpMin(sz + 1, INT_MAX);
    dpMin[0] = 1;
    dpMax[0] = 1;
    int res = INT_MIN;
    for (int i = 0; i < sz; ++i) {
      int a = dpMax[i] * nums[i];
      int b = dpMin[i] * nums[i];
      dpMax[i + 1] = max({a, b, nums[i]});
      dpMin[i + 1] = min({a, b, nums[i]});
      res = max(res, dpMax[i + 1]);
    }
    return res;
  }
};
