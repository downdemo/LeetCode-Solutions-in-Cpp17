class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](vector<int>& x, vector<int>& y) {
      return tie(y[0], x[1]) < tie(x[0], y[1]);
    });
    vector<vector<int>> res;
    for (auto& x : people) {
      res.emplace(res.begin() + x[1], x);
    }
    return res;
  }
};
