
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> a = ListNodeToNum(l1);
    stack<int> b = ListNodeToNum(l2);
    int carry = 0;
    ListNode* cur = nullptr;
    while (!a.empty() || !b.empty() || carry != 0) {
      int x = a.empty() ? 0 : a.top();
      int y = b.empty() ? 0 : b.top();
      if (!a.empty()) {
        a.pop();
      }
      if (!b.empty()) {
        b.pop();
      }
      int sum = x + y + carry;
      carry = sum / 10;
      sum = sum % 10;
      ListNode* node = new ListNode(sum);
      node->next = cur;
      cur = node;
    }
    return cur;
  }

  stack<int> ListNodeToNum(ListNode* l) {
    stack<int> res;
    ListNode* p = l;
    while (p) {
      res.emplace(p->val);
      p = p->next;
    }
    return res;
  }
};
