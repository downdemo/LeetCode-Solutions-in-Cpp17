class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) {
      return 0;
    }
    sort(points.begin(), points.end(),
         [](vector<int>& x, vector<int>& y) { return x[1] < y[1]; });
    int res = 1;
    int t = points[0][1];
    for (auto& x : points) {
      if (t >= x[0] && t <= x[1]) {
        continue;
      } else {
        t = x[1];
        ++res;
      }
    }
    return res;
  }
};
