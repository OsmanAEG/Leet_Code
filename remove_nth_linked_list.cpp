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
    if(head == nullptr) return head;

    auto curr_head = head;
    int len = 1;

    while(curr_head->next != nullptr) {
      curr_head = curr_head->next;
      ++len;
    }

    curr_head = head;

    if(len == n) return curr_head->next;

    for(int i = 0; i < len - n - 1; ++i) {
      curr_head = curr_head->next;
    }

    curr_head->next = curr_head->next->next;

    return head;
  }
};