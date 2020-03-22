class Solution {
 public:
  int calculate(string s) {
    stack<int> data;
    string operand{"+"};
    char op = '+';
    s += '$';
    for (auto& x : s) {
      if (x == ' ') {
        continue;
      }
      if (isdigit(x)) {
        operand += x;
      } else {
        if (op == '*') {
          data.top() *= stoi(operand);
        } else if (op == '/') {
          data.top() /= stoi(operand);
        } else {
          data.emplace(stoi(operand));
        }
        operand = x == '-' ? "-" : "+";
        op = x;
      }
    }
    int res = 0;
    while (!data.empty()) {
      res += data.top();
      data.pop();
    }
    return res;
  }
};
