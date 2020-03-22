class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int l = matrix[0][0];
    int r = matrix.back().back();
    while (l < r) {
      int m = l + (r - l) / 2;
      int cnt = 0;
      for (auto& x : matrix) {
        cnt += upper_bound(x.begin(), x.end(), m) - x.begin();
      }
      if (k <= cnt) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
