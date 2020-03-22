class Solution {
 public:
  double myPow(double x, int n) {
    double t = 1;
    if (n < 0) {
      x = 1 / x;
      t = x;
      n = -(n + 1);
    }
    return t * helper(x, n);
  }

  double helper(double x, int n) {
    if (!n) {
      return 1.0;
    }
    double t = helper(x, n / 2);
    return n % 2 & 1 ? t * t * x : t * t;
  }
};
