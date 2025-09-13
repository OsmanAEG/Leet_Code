// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto next = head;

    for(int i = 0; i < n - 1; ++i) next = next->next;

    auto next_next = next->next->next;

    next->next=next_next;

    return head;
  }
};