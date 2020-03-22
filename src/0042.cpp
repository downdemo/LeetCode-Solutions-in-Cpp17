class Solution {
 public:
  int trap(vector<int>& height) {
    int sz = height.size();
    vector<int> l(sz);
    vector<int> r(sz);
    for (int i = 1; i < sz; ++i) {
      l[i] = max(l[i - 1], height[i - 1]);
    }
    for (int i = sz - 2; i >= 0; --i) {
      r[i] = max(r[i + 1], height[i + 1]);
    }
    int res = 0;
    for (int i = 0; i < sz; i++) {
      res += max(0, min(l[i], r[i]) - height[i]);
    }
    return res;
  }
};
