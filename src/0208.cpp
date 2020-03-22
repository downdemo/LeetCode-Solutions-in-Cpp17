class Trie {
 public:
  /** Initialize your data structure here. */
  Trie() {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    Trie* t = this;
    for (auto& x : word) {
      if (!t->next[x - 'a']) {
        t->next[x - 'a'] = new Trie;
      }
      t = t->next[x - 'a'];
    }
    t->is_end = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Trie* t = this;
    for (auto& x : word) {
      t = t->next[x - 'a'];
      if (!t) {
        return false;
      }
    }
    return t->is_end;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Trie* t = this;
    for (auto& x : prefix) {
      t = t->next[x - 'a'];
      if (!t) {
        return false;
      }
    }
    return true;
  }

 private:
  vector<Trie*> next{vector<Trie*>(26)};
  bool is_end = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
