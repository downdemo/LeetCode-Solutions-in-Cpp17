class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    n = n * (n + 1) / 2;
    return accumulate(nums.begin(), nums.end(), n, minus<int>{});
  }
};
