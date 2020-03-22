class Solution {
 public:
  int firstUniqChar(string s) {
    vector<int> v(26);
    for (auto& x : s) {
      ++v[x - 'a'];
    }
    int res = INT_MAX;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] == 1) {
        int pos = s.find(i + 'a');
        res = min(res, pos);
      }
    }
    return res == INT_MAX ? -1 : res;
  }
};
