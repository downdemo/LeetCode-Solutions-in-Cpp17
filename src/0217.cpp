class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (auto& x : nums) {
      if (s.count(x)) {
        return true;
      }
      s.emplace(x);
    }
    return false;
  }
};
