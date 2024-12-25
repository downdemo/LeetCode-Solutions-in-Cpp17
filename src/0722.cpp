class Solution {
 public:
  vector<string> removeComments(vector<string>& source) {
    bool in_comment = false;
    vector<string> res;
    string s;
    for (auto& x : source) {
      for (int i = 0; i < x.size(); ++i) {
        string t{x.substr(i, 2)};
        if (in_comment) {
          if (t == "*/") {
            in_comment = false;
            ++i;
          }
          continue;
        }
        if (t == "/*") {
          ++i;
          in_comment = true;
          continue;
        }
        if (t == "//") {
          break;
        }
        s += x[i];
      }
      if (!in_comment && !s.empty()) {
        res.emplace_back(s);
        s.clear();
      }
    }
    return res;
  }
};
