class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    if (nums.size() < 2) {
      return false;
    }
    int n = accumulate(nums.begin(), nums.end(), 0);
    if (n % 2 & 1) {
      return false;
    }
    bitset<10001> b{1};
    for (auto& x : nums) {
      b |= (b << x);
    }
    return b[n / 2];
  }
};