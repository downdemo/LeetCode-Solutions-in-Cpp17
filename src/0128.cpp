class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int res = 0;
    for (auto& x : nums) {
      if (!s.count(x - 1)) {
        int cnt = 1;
        while (s.count(x + cnt)) {
          ++cnt;
        }
        res = max(res, cnt);
      }
    }
    return res;
  }
};
