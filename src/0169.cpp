class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int cnt = 0;
    int res = INT_MIN;
    for (auto& x : nums) {
      if (cnt == 0) {
        res = x;
      }
      if (res == x) {
        ++cnt;
      } else {
        --cnt;
      }
    }
    return res;
  }
};
