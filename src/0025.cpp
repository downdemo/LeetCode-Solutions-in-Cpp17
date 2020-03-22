/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* next_group_node = head;
    int n = k;
    while (n--) {
      if (!next_group_node) {
        return head;
      }
      next_group_node = next_group_node->next;
    }
    n = k;
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (--n) {
      ListNode* t = cur->next;
      cur->next = pre;
      pre = cur;
      cur = t;
    }
    cur->next = pre;
    head->next = reverseKGroup(next_group_node, k);
    return cur;
  }
};
