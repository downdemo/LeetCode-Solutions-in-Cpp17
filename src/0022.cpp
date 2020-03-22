class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    dfs(res, "", n, n);
    return res;
  }

  void dfs(vector<string>& res, string s, int l_parenthese, int r_parenthese) {
    if (l_parenthese == 0 && r_parenthese == 0) {
      res.emplace_back(s);
      return;
    }
    if (l_parenthese <= r_parenthese) {
      if (l_parenthese > 0) {
        dfs(res, s + '(', l_parenthese - 1, r_parenthese);
      }
      if (r_parenthese > 0) {
        dfs(res, s + ')', l_parenthese, r_parenthese - 1);
      }
    }
  }
};
