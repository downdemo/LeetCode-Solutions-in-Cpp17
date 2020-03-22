class Solution {
 public:
  Solution(vector<int>& nums) { v.assign(nums.begin(), nums.end()); }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return v; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> res{v};
    for (int i = 0; i < res.size(); ++i) {
      int t = i + rand() % (res.size() - i);
      swap(res[i], res[t]);
    }
    return res;
  }

 private:
  vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
