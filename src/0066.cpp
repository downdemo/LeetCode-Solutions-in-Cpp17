class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
      if (!carry) {
        break;
      }
      *it += carry;
      carry = *it / 10;
      *it %= 10;
    }
    if (carry) {
      digits.emplace(digits.begin(), carry);
    }
    return digits;
  }
};
