class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet{wordDict.begin(), wordDict.end()};
    vector<bool> dp(s.size() + 1);
    dp[0] = true;
    for (int i = 1; i < dp.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] && wordSet.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    vector<string> res;
    if (!dp.back()) {
      return res;
    }
    vector<string> path;
    dfs(wordSet, dp, res, path, s, 0);
    return res;
  }

  void dfs(unordered_set<string>& wordSet, vector<bool>& dp,
           vector<string>& res, vector<string>& path, string_view s, int n) {
    if (!dp[n]) {
      return;
    }
    if (n == s.size()) {
      string t;
      for (int i = 0; i < path.size() - 1; ++i) {
        t += (path[i] + " ");
      }
      t += path.back();
      res.emplace_back(t);
    }
    for (int i = n; i < s.size(); ++i) {
      string t{s.substr(n, i - n + 1)};
      if (wordSet.count(t)) {
        path.emplace_back(t);
        dfs(wordSet, dp, res, path, s, i + 1);
        path.pop_back();
      }
    }
  }
};
