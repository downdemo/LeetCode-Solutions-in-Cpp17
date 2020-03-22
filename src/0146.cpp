class LRUCache {
 public:
  explicit LRUCache(int capacity) : n(capacity) {}

  int get(int key) {
    if (n == 0 || !m.count(key)) {
      return -1;
    }
    q.splice(q.begin(), q, m[key]);
    return q.front().second;
  }

  void put(int key, int value) {
    if (n == 0) {
      return;
    }
    if (m.count(key)) {  // 已存在该key
      q.splice(q.begin(), q, m[key]);
      q.front().second = value;
      return;
    }
    if (m.size() == n) {
      m.erase(q.back().first);
      q.pop_back();
    }
    q.emplace_front(key, value);
    m.emplace(key, q.begin());
  }

 private:
  int n;
  list<pair<int, int>> q;
  unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
