class Solution {
 public:
  int compress(vector<char>& chars) {
    int sz = chars.size();
    int l = 0;
    int r = 0;
    int cur = 0;
    while (l != sz) {
      while (r < sz && chars[l] == chars[r]) {
        ++r;
      }
      chars[cur] = chars[l];
      if (r - l > 1) {
        string cnt = to_string(r - l);
        for (int i = 0; i < cnt.size(); ++i) {
          chars[++cur] = cnt[i];
        }
      }
      l = r;
      ++cur;
    }
    return cur;
  }
};
