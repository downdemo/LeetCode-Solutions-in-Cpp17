class Solution {
 public:
  bool isValid(string s) {
    stack<char> stk;
    for (auto& x : s) {
      if (x == '(' || x == '{' || x == '[') {
        stk.emplace(x);
      } else if (!stk.empty() && stk.top() == m.at(x)) {
        stk.pop();
      } else {
        return false;
      }
    }
    return stk.empty();
  }

 private:
  const unordered_map<char, char> m{
      {')', '('},
      {'}', '{'},
      {']', '['},
  };
};
