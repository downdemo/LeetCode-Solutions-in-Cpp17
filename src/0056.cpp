class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    if (intervals.empty()) {
      return res;
    }
    sort(intervals.begin(), intervals.end(),
         [](auto& x, auto& y) { return x[0] < y[0]; });
    for (int i = 0; i < intervals.size() - 1; ++i) {
      if (intervals[i][1] < intervals[i + 1][0]) {
        res.emplace_back(intervals[i]);
      } else {
        intervals[i + 1][0] = intervals[i][0];
        intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
      }
    }
    res.emplace_back(intervals.back());
    return res;
  }
};
