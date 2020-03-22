class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    if (envelopes.empty()) {
      return 0;
    }
    sort(envelopes.begin(), envelopes.end(),
         [](auto& x, auto& y) { return tie(x[0], y[1]) < tie(y[0], x[1]); });
    vector<int> v{envelopes[0][1]};
    for (int i = 1; i < envelopes.size(); ++i) {
      if (envelopes[i][1] > v.back()) {
        v.emplace_back(envelopes[i][1]);
      } else {
        *lower_bound(v.begin(), v.end(), envelopes[i][1]) = envelopes[i][1];
      }
    }
    return v.size();
  }
};
