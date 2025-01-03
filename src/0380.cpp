class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (m.count(val)) {
      return false;
    }
    v.emplace_back(val);
    m.emplace(val, v.size() - 1);
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (!m.count(val)) {
      return false;
    }
    v[m[val]] = v.back();
    m[v.back()] = m[val];
    v.pop_back();
    m.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() { return v[rand() % v.size()]; }

 private:
  unordered_map<int, int> m;
  vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
