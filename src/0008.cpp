class Solution {
 public:
  int myAtoi(string s) {
    if (s.empty()) {
      return 0;
    }
    long res = 0;
    int cur = 0;
    bool postive = true;
    while (cur < s.size() && s[cur] == ' ') {
      ++cur;
    }
    if (cur >= s.size()) {
      return 0;
    }
    if (s[cur] == '+') {
      ++cur;
    } else if (s[cur] == '-') {
      postive = false;
      ++cur;
    }
    while (cur < s.size() && isdigit(s[cur])) {
      if (res > INT_MAX) {
        break;
      }
      res = res * 10 + (s[cur] - '0');
      ++cur;
    }
    if (!postive) {
      res = -res;
    }
    if (res >= INT_MAX) {
      return INT_MAX;
    }
    if (res <= INT_MIN) {
      return INT_MIN;
    }
    return res;
  }
};
