class Solution {
 public:
  bool isPalindrome(string s) {
    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
      while (l < r && !isalnum(s[l])) {
        ++l;
      }
      while (l < r && !isalnum(s[r])) {
        --r;
      }
      if (toupper(s[l]) == toupper(s[r])) {
        ++l;
        --r;
      } else {
        return false;
      }
    }
    return true;
  }
};
