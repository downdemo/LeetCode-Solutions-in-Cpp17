class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    if (board.empty() || board[0].empty()) {
      return;
    }
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int cnt = 0;
        if (i > 0 && j > 0 && board[i - 1][j - 1] > 0) {
          ++cnt;
        }
        if (i > 0 && board[i - 1][j] > 0) {
          ++cnt;
        }
        if (i > 0 && j + 1 < n && board[i - 1][j + 1] > 0) {
          ++cnt;
        }
        if (j > 0 && board[i][j - 1] > 0) {
          ++cnt;
        }
        if (j + 1 < n && board[i][j + 1] > 0) {
          ++cnt;
        }
        if (i + 1 < m && j > 0 && board[i + 1][j - 1] > 0) {
          ++cnt;
        }
        if (i + 1 < m && board[i + 1][j] > 0) {
          ++cnt;
        }
        if (i < m - 1 && j + 1 < n && board[i + 1][j + 1] > 0) {
          ++cnt;
        }
        if (cnt == 3 && !board[i][j]) {
          board[i][j] = -1;
        }
        if (cnt != 2 && cnt != 3 && board[i][j] == 1) {
          board[i][j] = 2;
        }
      }
    }
    for (auto& x : board) {
      for (auto& y : x) {
        if (y == -1) {
          y = 1;
        } else if (y == 2) {
          y = 0;
        }
      }
    }
  }
};
