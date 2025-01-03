class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return "";
    }
    string s{strs[0]};
    for (int i = 1; i < strs.size(); ++i) {
      const string& x = strs[i];
      int cur = 0;
      while (s[cur] == x[cur]) {
        ++cur;
        if (cur == s.size() || cur == x.size()) {
          break;
        }
      }
      s = s.substr(0, cur);
    }
    return s;
  }
};
