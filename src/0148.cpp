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
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* pre = slow;
    while (fast && fast->next) {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    pre->next = nullptr;
    ListNode* l1 = sortList(head);
    ListNode* l2 = sortList(slow);
    return mergeTwoLists(l1, l2);
  }

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) {
      return l2;
    }
    if (!l2) {
      return l1;
    }
    if (l1->val < l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    }
    l2->next = mergeTwoLists(l2->next, l1);
    return l2;
  }
};
