class Solution {
 public:
  int minSteps(int n) {
    vector<int> t{primers(n)};
    int res = 0;
    while (n > 1) {
      for (auto& x : t) {
        if (n % x == 0) {
          n /= x;
          res += x;
          break;
        }
      }
    }
    return res;
  }

  vector<int> primers(int n) {
    vector<int> res;
    if (n < 2) {
      return res;
    }
    vector<bool> dp(n + 1, true);
    for (int i = 2; i < dp.size(); ++i) {
      if (dp[i]) {
        res.emplace_back(i);
      }
      for (int j = 0; j < res.size() && i * res[j] < dp.size(); ++j) {
        dp[i * res[j]] = false;
        if (i % res[j] == 0) {
          break;
        }
      }
    }
    return res;
  }
};
