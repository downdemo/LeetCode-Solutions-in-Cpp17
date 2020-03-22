class Solution {
 public:
  int flipLights(int n, int m) {
    bitset<3> b;
    unordered_set<bitset<3>> s;
    dfs(b, s, min(m, 3), min(n, 3));
    return s.size();
  }

  void dfs(bitset<3>& b, unordered_set<bitset<3>>& s, int m, int n) {
    if (!m) {
      s.emplace(b);
      return;
    }
    bitset<3> t = b;
    flip_all(b, n);
    dfs(b, s, m - 1, n);
    flip_even(b, n);
    dfs(b, s, m - 1, n);
    flip_odd(b, n);
    dfs(b, s, m - 1, n);
    flip_3k_append_1(b, n);
    dfs(b, s, m - 1, n);
    b = t;
  }

  void flip_all(bitset<3>& b, int n) {
    for (int i = 0; i < n; ++i) {
      b.flip();
    }
  }

  void flip_even(bitset<3>& b, int n) {
    for (int i = 1; i < n; i += 2) {
      b.flip(i);
    }
  }

  void flip_odd(bitset<3>& b, int n) {
    for (int i = 0; i < n; i += 2) {
      b.flip(i);
    }
  }

  void flip_3k_append_1(bitset<3>& b, int n) {
    for (int i = 0; i < n; i += 3) {
      b.flip(i);
    }
  }
};
