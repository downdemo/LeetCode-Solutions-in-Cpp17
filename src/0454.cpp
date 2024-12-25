class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                   vector<int>& D) {
    unordered_map<int, int> m;
    int sz = A.size();
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        ++m[A[i] + B[j]];
      }
    }
    int res = 0;
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        if (m.count(-C[i] - D[j])) {
          res += m[-C[i] - D[j]];
        }
      }
    }
    return res;
  }
};
