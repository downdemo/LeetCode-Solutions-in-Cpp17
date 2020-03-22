class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (auto& x : tokens) {
      if (x == "+" || x == "-" || x == "*" || x == "/") {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        if (x == "+") {
          s.emplace(a + b);
        } else if (x == "-") {
          s.emplace(a - b);
        } else if (x == "*") {
          s.emplace(a * b);
        } else {
          s.emplace(a / b);
        }
      } else {
        s.emplace(stoi(x));
      }
    }
    return s.top();
  }
};
