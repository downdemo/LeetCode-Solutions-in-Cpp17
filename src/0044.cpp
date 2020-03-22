class Solution {
 public:
  bool isMatch(string s, string p) {
    int i = 0;
    int j = 0;
    int markS = -1;
    int markP = -1;
    while (i < s.size()) {
      if (j < p.size() && (s[i] == p[j] || p[j] == '?')) {
        ++i;
        ++j;
      } else if (j < p.size() && p[j] == '*') {
        markS = i;
        markP = j;
        ++j;
      } else if (markP != -1) {
        i = ++markS;
        j = markP + 1;
      } else {
        return false;
      }
    }
    while (j < p.size() && p[j] == '*') {
      ++j;
    }
    return j == p.size();
  }
};
