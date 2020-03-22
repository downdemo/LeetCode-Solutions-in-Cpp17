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
  ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur) {
      ListNode* t = cur->next;
      cur->next = pre;
      pre = cur;
      cur = t;
    }
    return pre;
  }
};