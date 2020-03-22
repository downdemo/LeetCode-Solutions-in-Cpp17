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
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode* second_node = head->next;
    ListNode* third_node = second_node->next;
    second_node->next = head;
    head->next = swapPairs(third_node);
    return second_node;
  }
};
