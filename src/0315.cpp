class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> helper{nums};
    sort(helper.begin(), helper.end());
    helper.erase(unique(helper.begin(), helper.end()), helper.end());
    int sz = nums.size();
    init(sz + 1);
    vector<int> res;
    for (int i = sz - 1; i >= 0; --i) {
      int x =
          lower_bound(helper.begin(), helper.end(), nums[i]) - helper.begin();
      res.emplace_back(prefix_sum(x));
      add(x + 1, 1);
    }
    reverse(res.begin(), res.end());
    return res;
  }

  void init(int n) {
    t.clear();
    t.resize(n);
    t.shrink_to_fit();
  }

  void add(int pos, int value) {
    while (pos < t.size()) {
      t[pos] += value;
      pos += lowbit(pos);
    }
  }

  int prefix_sum(int pos) const {
    int res = 0;
    while (pos) {
      res += t[pos];
      pos -= lowbit(pos);
    }
    return res;
  }

 private:
  int lowbit(int x) const { return x & (-x); }

 private:
  vector<int> t;
};
