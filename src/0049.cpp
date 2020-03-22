class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, int> m;
    int i = -1;
    for (auto& x : strs) {
      string t{x};
      sort(t.begin(), t.end());
      if (!m.count(t)) {
        res.emplace_back(vector<string>{x});
        m.emplace(t, ++i);
      } else {
        res[m[t]].emplace_back(x);
      }
    }
    return res;
  }
};
