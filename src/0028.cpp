class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) {
      return 0;
    }
    vector<int> pi(needle.size());
    for (int i = 1, j = 0; i < pi.size(); ++i) {
      while (j > 0 && needle[i] != needle[j]) {
        j = pi[j - 1];
      }
      if (needle[i] == needle[j]) {
        ++j;
      }
      pi[i] = j;
    }
    for (int i = 0, j = 0; i < haystack.size(); ++i) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = pi[j - 1];
      }
      if (haystack[i] == needle[j]) {
        ++j;
      }
      if (j == needle.size()) {
        return i - needle.size() + 1;
      }
    }
    return -1;
  }
};
