class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> res;
    multiset<pair<int, int>> s;
    for (auto& x : buildings) {
      s.emplace(x[0], -x[2]);
      s.emplace(x[1], x[2]);
    }
    multiset<int> m{0};
    int pre = 0;
    int mx = 0;
    for (auto& [x, y] : s) {
      if (y < 0) {
        m.emplace(-y);
      } else {
        m.erase(m.find(y));
      }
      mx = *m.rbegin();
      if (mx != pre) {
        res.emplace_back(vector<int>{x, mx});
        pre = mx;
      }
    }
    return res;
  }
};
