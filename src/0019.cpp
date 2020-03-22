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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* p = dummy;
    ListNode* q = dummy;
    for (int i = 0; i < n + 1; ++i) {
      p = p->next;
    }
    while (p) {
      p = p->next;
      q = q->next;
    }
    q->next = q->next->next;
    return dummy->next;
  }
};
