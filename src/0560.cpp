class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int res = 0;
    int sum = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (auto& x : nums) {
      sum += x;
      if (m.count(sum - k)) {
        res += m[sum - k];
      }
      ++m[sum];
    }
    return res;
  }
};
