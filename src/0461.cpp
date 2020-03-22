class Solution {
 public:
  int hammingDistance(int x, int y) {
    int t = x ^ y;
    int res = 0;
    while (t) {
      ++res;
      t &= t - 1;
    }
    return res;
  }
};
