class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> m;
    for (auto& x : tasks) {
      ++m[x];
    }
    priority_queue<int> q;
    for (auto& x : m) {
      q.emplace(x.second);
    }
    int res = 0;
    while (!q.empty()) {
      vector<int> v;
      int cnt = 0;
      for (int i = 0; i < n + 1; ++i) {
        if (!q.empty()) {
          v.emplace_back(q.top());
          q.pop();
          ++cnt;
        }
      }
      for (auto& x : v) {
        if (--x > 0) q.emplace(x);
      }
      res += q.empty() ? cnt : n + 1;
    }
    return res;
  }
};
