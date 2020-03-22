class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int sz = matrix.size();
    for (int i = 0; i < sz; ++i) {
      for (int j = i + 1; j < sz; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};
