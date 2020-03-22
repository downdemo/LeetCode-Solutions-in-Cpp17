class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> v(n, string(n, '.'));
    dfs(res, v, n, 0);
    return res;
  }

  void dfs(vector<vector<string>>& res, vector<string>& v, int n, int row) {
    if (n == row) {
      res.emplace_back(v);
      return;
    }
    for (int col = 0; col < v[0].size(); ++col) {
      if (isValid(v, row, col)) {
        v[row][col] = 'Q';
        dfs(res, v, n, row + 1);
        v[row][col] = '.';
      }
    }
  }

  bool isValid(const vector<string>& v, int row, int col) {
    for (auto& x : v) {
      if (x[col] == 'Q') {
        return false;
      }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (v[i][j] == 'Q') {
        return false;
      }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < v[0].size(); --i, ++j) {
      if (v[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }
};
