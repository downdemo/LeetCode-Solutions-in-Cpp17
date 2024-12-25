class Solution {
 public:
  string simplifyPath(string path) {
    string res;
    vector<string> t{split(path, '/')};
    for (auto& x : t) {
      res += '/';
      res += x;
    }
    return res.empty() ? "/" : res;
  }

  vector<string> split(const string& s, char delemiter) {
    vector<string> res;
    istringstream ss{s};
    string t;
    while (getline(ss, t, delemiter)) {
      if (t.empty() || t == "." || (t == ".." && res.empty())) {
        continue;
      } else if (t == ".." && !res.empty()) {
        res.pop_back();
      } else {
        res.emplace_back(t);
      }
    }
    return res;
  }
};
