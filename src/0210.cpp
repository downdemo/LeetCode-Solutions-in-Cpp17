class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> m;
    vector<int> indegree(numCourses);
    for (auto& x : prerequisites) {
      m[x[1]].emplace_back(x[0]);
      ++indegree[x[0]];
    }
    queue<int> q;
    for (int i = 0; i < indegree.size(); ++i) {
      if (!indegree[i]) {
        q.emplace(i);
      }
    }
    vector<int> res;
    while (!q.empty()) {
      int n = q.front();
      q.pop();
      res.emplace_back(n);
      for (auto& x : m[n]) {
        --indegree[x];
        if (!indegree[x]) {
          q.emplace(x);
        }
      }
    }
    if (res.size() < numCourses) {
      return {};
    }
    return res;
  }
};
