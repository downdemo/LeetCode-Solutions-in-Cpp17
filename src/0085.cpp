class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int res = 0;
    vector<int> dp(matrix[0].size() + 1);
    for (auto& x : matrix) {
      for (int i = 0; i < x.size(); ++i) {
        if (x[i] == '1') {
          ++dp[i];
        } else {
          dp[i] = 0;
        }
      }
      res = max(res, largestRectangleArea(dp));
    }
    return res;
  }

  int largestRectangleArea(const vector<int>& heights) {
    stack<int> s;
    int res = 0;
    for (int i = 0; i < heights.size(); ++i) {
      while (!s.empty() && heights[i] < heights[s.top()]) {
        int t = s.top();
        s.pop();
        res = max(res, heights[t] * (s.empty() ? i : (i - s.top() - 1)));
      }
      s.emplace(i);
    }
    return res;
  }
};
