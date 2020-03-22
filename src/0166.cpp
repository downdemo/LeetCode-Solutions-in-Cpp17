class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
      return "0";
    }
    string res;
    if ((numerator ^ denominator) < 0) {
      res += '-';
    }
    long a = labs(numerator);
    long b = labs(denominator);

    if (a < b) {
      res += "0.";
    } else {
      res += to_string(a / b);
      if (a % b == 0) return res;
      res += '.';
      a = a % b;
    }
    unordered_map<int, int> m;
    int cnt = 0;
    while (a % b) {
      a *= 10;
      res += to_string(a / b);
      a %= b;
      if (m.count(a)) {
        int dot_pos = res.find('.') + 1 + m[a];
        res.insert(dot_pos, "(");
        res += ')';
        break;
      }
      m[a] = ++cnt;
    }
    return res;
  }
};
