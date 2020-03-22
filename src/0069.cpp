class Solution {
 public:
  int mySqrt(int x) {
    if (x <= 1) {
      return x;
    }
    int l = 1;
    int r = x;
    while (l < r) {
      int m = l + (r - l) / 2;
      int t = x / m;
      if (m == t) {
        return m;
      } else if (m > t) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l - 1;
  }
};
