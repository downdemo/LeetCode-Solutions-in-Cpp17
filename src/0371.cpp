class Solution {
 public:
  int getSum(int a, int b) {
    int sum = a ^ b;
    int carry = static_cast<unsigned>(a & b) << 1;
    if (carry) {
      return getSum(sum, carry);
    }
    return sum;
  }
};
