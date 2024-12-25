class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    if (all_of(nums.begin(), nums.end(), [](int x) { return !x; })) {
      return "0";
    }
    vector<string> v;
    transform(nums.begin(), nums.end(), back_inserter(v),
              [](int x) { return to_string(x); });
    sort(v.begin(), v.end(),
         [](const string& x, const string& y) { return y + x < x + y; });
    return accumulate(v.begin(), v.end(), string{""});
  }
};
