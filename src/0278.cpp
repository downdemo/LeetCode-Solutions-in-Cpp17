// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    int l = 1;
    int r = n;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (isBadVersion(m)) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};