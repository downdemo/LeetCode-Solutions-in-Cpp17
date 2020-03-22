class Solution {
 public:
  string reverseWords(string s) {
    trim(s);
    reverse(s.begin(), s.end());
    int l = 0;
    int r = 0;
    while (l < s.size()) {
      while (l < s.size() && s[l] == ' ') {
        ++l;
      }
      r = l + 1;
      while (r < s.size() && s[r] != ' ') {
        ++r;
      }
      reverse(s.begin() + l, s.begin() + r);
      l = r;
    }
    return s;
  }

  void trim(string& s) {
    int l = 0;
    int r = 0;
    int cur = 0;
    while (cur < s.size() && l < s.size()) {
      while (l < s.size() && s[l] == ' ') {
        ++l;
      }
      r = l + 1;
      while (r < s.size() && s[r] != ' ') {
        ++r;
      }
      if (l >= s.size()) {
        break;
      }
      for (int i = l; i < r; ++i) {
        s[cur] = s[i];
        ++cur;
      }
      if (cur >= s.size()) {
        return;
      }
      s[cur] = ' ';
      ++cur;
      l = r;
    }
    s = s.substr(0, cur - 1);
  }
};
