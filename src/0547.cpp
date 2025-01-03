class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    if (M.empty() || M[0].empty()) {
      return 0;
    }
    vector<int> p{MakeSet(M.size())};
    for (int i = 0; i < M.size(); ++i) {
      for (int j = 0; j < M[0].size(); ++j) {
        if (M[i][j] == 1) {
          Union(p, i, j);
        }
      }
    }
    int res = 0;
    for (int i = 0; i < p.size(); ++i) {
      if (p[i] == i) {
        ++res;
      }
    }
    return res;
  }

 private:
  vector<int> MakeSet(int n) {
    vector<int> res(n);
    iota(res.begin(), res.end(), 0);
    return res;
  }

  int FindSet(vector<int>& p, int i) {
    while (p[i] != i) {
      i = p[i];
    }
    return i;
  }

  void Union(vector<int>& p, int parent, int child) {
    p[FindSet(p, child)] = p[FindSet(p, parent)];
  }
};
