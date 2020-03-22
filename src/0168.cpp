class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string res;
    while (columnNumber) {
      int t = columnNumber % 26;
      if (!t) {
        res.insert(res.begin(), 'Z');
        columnNumber = columnNumber / 26 - 1;
      } else {
        res.insert(res.begin(), 'A' + t - 1);
        columnNumber /= 26;
      }
    }
    return res;
  }
};
