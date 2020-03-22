class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int sz = points.size();
    if (sz < 3) {
      return sz;
    }
    int res = 0;
    for (int i = 0; i < sz; ++i) {
      int cnt = 0;
      int mx = 0;
      unordered_map<string, int> m;
      for (int j = i + 1; j < sz; ++j) {
        int dx = points[j][0] - points[i][0];
        int dy = points[j][1] - points[i][1];
        if (dx == 0 && dy == 0) {
          ++cnt;
        } else {
          string k = getK(dx, dy);
          ++m[k];
          mx = max(mx, m[k]);
        }
      }
      res = max(res, mx + cnt + 1);
    }
    return res;
  }

 private:
  string getK(int x, int y) {
    int a = x;
    int b = y;
    while (b) {
      int t = a % b;
      a = b;
      b = t;
    }
    x /= a;
    y /= a;
    return to_string(x) + "#" + to_string(y);
  }
};
