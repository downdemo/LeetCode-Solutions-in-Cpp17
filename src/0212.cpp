class Trie {
 public:
  void insert(string word) {
    Trie* t = this;
    for (auto& x : word) {
      if (!t->next[x - 'a']) {
        t->next[x - 'a'] = new Trie;
      }
      t = t->next[x - 'a'];
    }
    t->word = word;
  }

 public:
  vector<Trie*> next{vector<Trie*>(26)};
  string word;
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;
    if (board.empty() || board[0].empty()) {
      return res;
    }
    Trie* trie = new Trie;
    for (auto& x : words) trie->insert(x);
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        dfs(board, i, j, trie, res);
      }
    }
    return res;
  }

  void dfs(vector<vector<char>>& board, int i, int j, Trie* trie,
           vector<string>& res) {
    if (board[i][j] != '#' && trie->next[board[i][j] - 'a']) {
      trie = trie->next[board[i][j] - 'a'];
      if (!trie->word.empty()) {
        res.emplace_back(trie->word);
        trie->word.clear();
      }
      char t = board[i][j];
      board[i][j] = '#';
      if (i > 0) {
        dfs(board, i - 1, j, trie, res);
      }
      if (i + 1 < board.size()) {
        dfs(board, i + 1, j, trie, res);
      }
      if (j > 0) {
        dfs(board, i, j - 1, trie, res);
      }
      if (j + 1 < board[0].size()) {
        dfs(board, i, j + 1, trie, res);
      }
      board[i][j] = t;
    }
  }
};
