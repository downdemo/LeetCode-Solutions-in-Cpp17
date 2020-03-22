class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> m1;
    for (auto& x : s1) {
      ++m1[x];
    }
    int l = 0;
    unordered_map<char, int> m2;
    for (int r = 0; r < s2.size(); ++r) {
      char c = s2[r];
      ++m2[c];
      while (m2[c] > m1[c]) {
        --m2[s2[l]];
        ++l;
      }
      if (r - l + 1 == s1.size()) {
        return true;
      }
    }
    return false;
  }
};
