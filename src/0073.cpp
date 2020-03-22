class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return;
    }

    bool first_row_has_zero =
        any_of(matrix[0].begin(), matrix[0].end(), [](int x) { return !x; });

    bool first_col_has_zero =
        any_of(matrix.begin(), matrix.end(),
               [&](const vector<int>& x) { return !x[0]; });

    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (!matrix[i][j]) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (!matrix[i][0] || !matrix[0][j]) {
          matrix[i][j] = 0;
        }
      }
    }
    if (first_row_has_zero) {
      for_each(matrix[0].begin(), matrix[0].end(), [](int& x) { x = 0; });
    }
    if (first_col_has_zero) {
      for_each(matrix.begin(), matrix.end(), [&](vector<int>& x) { x[0] = 0; });
    }
  }
};
