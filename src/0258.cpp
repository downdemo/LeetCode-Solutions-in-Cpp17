class Solution {
 public:
  int addDigits(int num) {
    if (!num) {
      return 0;
    }
    int res = num % 9;
    if (!res) {
      return 9;
    }
    return res;
  }
};
