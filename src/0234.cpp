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
  bool isPalindrome(ListNode* head) {
    if (!head || !head->next) {
      return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode* pre = nullptr;
    while (slow) {
      ListNode* t = slow->next;
      slow->next = pre;
      pre = slow;
      slow = t;
    }
    ListNode* cur = head;
    while (pre) {
      if (cur->val != pre->val) {
        return false;
      }
      cur = cur->next;
      pre = pre->next;
    }
    return true;
  }
};
