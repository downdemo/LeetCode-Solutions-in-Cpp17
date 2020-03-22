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
    if (!l1) {
      return l2;
    }
    if (!l2) {
      return l1;
    }
    ListNode* p = l1;
    ListNode* q = l2;
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    int carry = 0;
    while (p || q) {
      int a = p ? p->val : 0;
      int b = q ? q->val : 0;
      int sum = a + b + carry;
      carry = sum / 10;
      sum = sum % 10;
      cur->next = new ListNode(sum);
      cur = cur->next;
      if (p) {
        p = p->next;
      }
      if (q) {
        q = q->next;
      }
    }
    if (carry == 1) {
      cur->next = new ListNode(1);
    }
    return dummy->next;
  }
};
