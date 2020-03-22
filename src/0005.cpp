class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() <= 1) {
      return s;
    }
    string str{"#"};
    for (auto& x : s) {
      str += x;
      str += '#';
    }
    int sz = str.size();
    vector<int> p(sz);
    int start = 0;
    int maxLen = 0;

    int id = 0;
    int mx = 0;

    for (int i = 0; i < sz; ++i) {
      if (i < mx) {
        p[i] = min(p[2 * id - i], mx - i);
      } else if (i == mx) {
        p[i] = 1;
      }
      while (i >= p[i] && str[i - p[i]] == str[i + p[i]]) {
        ++p[i];
      }
      if (mx < i + p[i]) {
        id = i;
        mx = i + p[i];
      }
      if (p[i] - 1 > maxLen) {
        start = i;
        maxLen = p[i] - 1;
      }
    }
    return s.substr((start - p[start] + 1) / 2, maxLen);
  }
};
