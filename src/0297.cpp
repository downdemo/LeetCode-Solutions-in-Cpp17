/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) {
      return "";
    }
    queue<TreeNode*> q;
    q.emplace(root);
    stringstream ss;
    while (!q.empty()) {
      TreeNode* t = q.front();
      q.pop();
      if (t) {
        ss << t->val << " ";
        q.emplace(t->left);
        q.emplace(t->right);
      } else {
        ss << "# ";
      }
    }
    return ss.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.empty()) {
      return nullptr;
    }
    stringstream ss{data};
    string s;
    ss >> s;
    TreeNode* root = new TreeNode(stoi(s));
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty()) {
      TreeNode* t = q.front();
      q.pop();
      ss >> s;
      if (s == "#") {
        t->left = nullptr;
      } else {
        t->left = new TreeNode(stoi(s));
        q.emplace(t->left);
      }
      ss >> s;
      if (s == "#") {
        t->right = nullptr;
      } else {
        t->right = new TreeNode(stoi(s));
        q.emplace(t->right);
      }
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
